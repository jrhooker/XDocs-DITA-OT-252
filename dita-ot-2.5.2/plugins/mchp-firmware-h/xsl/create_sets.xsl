<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:math="http://exslt.org/math"
    xmlns:xs="http://www.w3.org/2001/XMLSchema" version="2.0">
    <xsl:output omit-xml-declaration="yes"/>

    <xsl:variable name="reg-ref-set" select="//reg-references"/>

    <xsl:output media-type="text" indent="no" encoding="UTF-8" omit-xml-declaration="yes"/>

    <xsl:strip-space elements="*"/>

    <xsl:template name="process-registers">
        <xsl:param name="current-node" select="1"/>
        <xsl:param name="starting-node" select="$current-node"/>
        <xsl:param name="current-field" select="1"/>
        <xsl:param name="total-bits" select="0"/>

        <xsl:variable name="ending-node" select="count($reg-ref-set[$current-node]/reg-reference)"/>

        <xsl:for-each select="$reg-ref-set[$current-node]/reg-reference[$current-field]">

            <xsl:variable name="bits">
                <xsl:call-template name="units-to-size">
                    <xsl:with-param name="value" select="reg-size"/>
                </xsl:call-template>
            </xsl:variable>

            <xsl:choose>
                <!-- if we've run out of fields, send the batch off to get processed and reset the reg-reference count -->
                <xsl:when test="(count(preceding-sibling::reg-reference) + 1) = $ending-node">
                    <xsl:call-template name="process-register">
                        <xsl:with-param name="ending-node" select="$ending-node"/>
                        <xsl:with-param name="reg-reference-number" select="$current-node"
                            tunnel="yes"/>
                        <xsl:with-param name="size" select="$total-bits + $bits" tunnel="yes"/>
                    </xsl:call-template>
                    <xsl:call-template name="process-registers">
                        <xsl:with-param name="current-node" select="$current-node + 1"/>
                        <xsl:with-param name="starting-node" select="$current-node + 1"/>
                        <xsl:with-param name="current-field" select="1"/>
                        <xsl:with-param name="total-bits" select="0"/>
                    </xsl:call-template>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:call-template name="process-registers">
                        <xsl:with-param name="current-node" select="$current-node"/>
                        <xsl:with-param name="current-field" select="$current-field + 1"/>
                        <xsl:with-param name="total-bits" select="$total-bits + $bits"/>
                    </xsl:call-template>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:for-each>

    </xsl:template>

    <xsl:template name="process-register">
        <xsl:param name="starting-node" tunnel="yes"/>
        <xsl:param name="ending-node" tunnel="yes"/>
        <xsl:param name="reg-reference-number" tunnel="yes"/>
        <xsl:param name="count" select="0"/>
        <xsl:param name="size" tunnel="yes"/>
        <xsl:variable name="reserved" select="32 - $size"/>

        <xsl:variable name="offset-present">
            <xsl:choose>
                <xsl:when
                    test="contains($reg-ref-set[$reg-reference-number]/reg-reference[1]/reg-address, 'NONE')">
                    <xsl:value-of select="0"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="1"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <!-- determine the name of the register -->

        <xsl:variable name="title">
            <xsl:call-template name="create-register-title"/>
        </xsl:variable>

        <xsl:variable name="registers" select="$reg-ref-set[$reg-reference-number]/reg-reference"/>
        <xsl:variable name="register-title"
            select="substring-after(//*[@id = substring-after($registers[1]/reg-details//xref/@href, '/')]/title, '-')"/>
        <!-- Account for NVMe exceptions -->
        <xsl:choose>
            <xsl:when test="contains(upper-case($register-title), 'NVME')">
                <!-- If this is the first NVME register, then print out the replacement block. Otherwise, just skip it. -->
                <xsl:variable name="temp"
                    select="$reg-ref-set[contains(upper-case(ancestor::table/title), 'NVME')]"/>
                <xsl:choose>
                    <xsl:when
                        test="$temp[1]/ancestor::table/title = $reg-ref-set[$reg-reference-number]/ancestor::table/title">
                        <xsl:value-of select="$nvme_block"/>
                    </xsl:when>
                    <xsl:otherwise/>
                </xsl:choose>
            </xsl:when>
            <xsl:when test="$offset-present = 0">
                <xsl:call-template name="write-register-no-offset">
                    <xsl:with-param name="nodes" select="$registers"/>
                    <xsl:with-param name="title" select="$title"/>
                    <xsl:with-param name="register-title" select="$register-title"/>
                    <xsl:with-param name="reserved" select="$reserved"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <xsl:call-template name="write-register">
                    <xsl:with-param name="nodes" select="$registers"/>
                    <xsl:with-param name="title" select="$title"/>
                    <xsl:with-param name="register-title" select="$register-title"/>
                    <xsl:with-param name="reserved" select="$reserved"/>
                </xsl:call-template>
            </xsl:otherwise>
        </xsl:choose>


    </xsl:template>

    <xsl:template name="create-register-title">
        <xsl:param name="starting-node" select="1"/>
        <xsl:param name="reg-reference-number" tunnel="yes"/>
        <xsl:param name="title"/>
        <xsl:param name="count" select="0"/>

        <xsl:variable name="ending-node"
            select="count($reg-ref-set[$reg-reference-number]/reg-reference)"/>

        <xsl:choose>
            <xsl:when test="(number($starting-node) + number($count)) &lt;= number($ending-node)">
                <xsl:call-template name="create-register-title">
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="title">
                        <xsl:value-of select="$title"/>
                        <xsl:if test="string-length($title) &gt; 0">
                            <xsl:text>_</xsl:text>
                        </xsl:if>
                        <xsl:value-of
                            select="$reg-ref-set[$reg-reference-number]/reg-reference[number($starting-node) + number($count)]/reg-name"
                        />
                    </xsl:with-param>
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$title"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="write-register">
        <xsl:param name="nodes"/>
        <xsl:param name="title"/>
        <xsl:param name="register-title"/>
        <xsl:param name="reserved"/>
        <xsl:param name="size" tunnel="yes"/>
        <xsl:variable name="dec_offset">
            <xsl:call-template name="hex2dec">
                <xsl:with-param name="hex" select="substring-after($nodes[1]/reg-address, '0x')"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="hex_offset">
            <xsl:call-template name="dec2hex">
                <xsl:with-param name="dec" select="$dec_offset"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="legacy-pci-title">
            <xsl:variable name="current_offset_in_dec">
                <xsl:choose>
                    <xsl:when test="string-length($hex_offset) &gt; 0 and not($hex_offset = '0')">
                        <xsl:call-template name="math:base-convert">
                            <xsl:with-param name="from-base" select="16"/>
                            <xsl:with-param name="to-base" select="10"/>
                            <xsl:with-param name="value" select="$hex_offset"/>
                        </xsl:call-template>
                    </xsl:when>
                    <xsl:otherwise><xsl:value-of select="0"/></xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
            <xsl:choose>
                <xsl:when
                    test="(number($dec_offset) * 8) &lt; 512 and not(substring($title, 1, 3) = 'PCI')">
                    <xsl:text>PCI</xsl:text><xsl:value-of select="$title"/>
                </xsl:when>
                <xsl:otherwise><xsl:value-of select="$title"/></xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:variable name="default_value">
            <xsl:call-template name="default-value"><xsl:with-param name="nodes" select="$nodes"
                /></xsl:call-template>
        </xsl:variable>
        <xsl:variable name="sticky_value">
            <xsl:call-template name="sticky-mask-value"><xsl:with-param name="nodes" select="$nodes"
                /></xsl:call-template>
        </xsl:variable>
        <xsl:variable name="write_value">
            <xsl:call-template name="write-mask-value"><xsl:with-param name="nodes" select="$nodes"
                /></xsl:call-template>
        </xsl:variable>
        <xsl:text>
/**
* @brief - </xsl:text><xsl:value-of select="normalize-space($register-title)"
            /><xsl:text> field definitions
*
* @defgroup </xsl:text><xsl:value-of
            select="normalize-space($legacy-pci-title)"
            /><xsl:text>_fields - </xsl:text><xsl:value-of select="normalize-space($register-title)"
            /><xsl:text>
*/
/** @{ */
#define </xsl:text><xsl:call-template name="add-spaces"
                ><xsl:with-param name="string"><xsl:value-of select="$legacy-pci-title"
                />_OFFSET</xsl:with-param></xsl:call-template>(0x<xsl:call-template
            name="form-hex-value"><xsl:with-param name="string" select="$hex_offset"
            /></xsl:call-template>)<xsl:text>
</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
                />_DEFAULT_VALUE</xsl:with-param></xsl:call-template>(<xsl:value-of
            select="$default_value"/>)<xsl:text>

</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
            />_WR_MSK</xsl:with-param></xsl:call-template>(<xsl:value-of select="$write_value"/>)<xsl:text>
</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
            />_STICKY_MSK</xsl:with-param></xsl:call-template>(<xsl:value-of select="$sticky_value"/>)<xsl:text>

</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
            />_SIZE</xsl:with-param></xsl:call-template>(<xsl:value-of select="$size div 8"/>)<xsl:text>
</xsl:text>
        <xsl:call-template name="process-reg-bits"><xsl:with-param name="nodes" select="$nodes"
                /><xsl:with-param name="title" select="$legacy-pci-title" tunnel="yes"
            /></xsl:call-template>
        <xsl:text>
/** @} */

</xsl:text>
    </xsl:template>

    <xsl:template name="write-register-no-offset">
        <xsl:param name="nodes"/>
        <xsl:param name="title"/>
        <xsl:param name="register-title"/>
        <xsl:param name="reserved"/>
        <xsl:param name="size" tunnel="yes"/>
        <xsl:variable name="legacy-pci-title">
            <xsl:value-of select="$title"/>
        </xsl:variable>
        <xsl:variable name="default_value">
            <xsl:call-template name="default-value"><xsl:with-param name="nodes" select="$nodes"
                /></xsl:call-template>
        </xsl:variable>
        <xsl:variable name="sticky_value">
            <xsl:call-template name="sticky-mask-value"><xsl:with-param name="nodes" select="$nodes"
                /></xsl:call-template>
        </xsl:variable>
        <xsl:variable name="write_value">
            <xsl:call-template name="write-mask-value"><xsl:with-param name="nodes" select="$nodes"
                /></xsl:call-template>
        </xsl:variable>
        <xsl:text>
/**
* @brief - </xsl:text><xsl:value-of select="normalize-space($register-title)"
            /><xsl:text> field definitions
*
* @defgroup </xsl:text><xsl:value-of
            select="normalize-space($legacy-pci-title)"
            /><xsl:text>_fields - </xsl:text><xsl:value-of select="normalize-space($register-title)"
            /><xsl:text>
*/
/** @{ */
#define </xsl:text><xsl:call-template name="add-spaces"
                ><xsl:with-param name="string"><xsl:value-of select="$legacy-pci-title"
                />_DEFAULT_VALUE</xsl:with-param></xsl:call-template>(<xsl:value-of
            select="$default_value"/>)<xsl:text>

</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
            />_WR_MSK</xsl:with-param></xsl:call-template>(<xsl:value-of select="$write_value"/>)<xsl:text>
</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
            />_STICKY_MSK</xsl:with-param></xsl:call-template>(<xsl:value-of select="$sticky_value"/>)<xsl:text>

</xsl:text>
        <xsl:text>#define </xsl:text><xsl:call-template name="add-spaces"><xsl:with-param
                name="string"><xsl:value-of select="$legacy-pci-title"
            />_SIZE</xsl:with-param></xsl:call-template>(<xsl:value-of select="$size div 8"/>)<xsl:text>
</xsl:text>
        <xsl:call-template name="process-reg-bits"><xsl:with-param name="nodes" select="$nodes"
                /><xsl:with-param name="title" select="$legacy-pci-title" tunnel="yes"
            /></xsl:call-template>
        <xsl:text>
/** @} */

</xsl:text>
    </xsl:template>

    <xsl:template name="process-reg-bits">
        <!-- the whole node set -->
        <xsl:param name="nodes"/>
        <!-- the title of the current register; all of the register names concatenated. -->
        <xsl:param name="title" tunnel="yes"/>
        <!-- current bit is the next available bit position in the 32 bit chunk -->
        <xsl:param name="current_bit" select="0"/>
        <!-- count field is the number of fields in the current register  -->
        <xsl:param name="count" select="1"/>
        <!-- count field is the number of fields in the current register  -->
        <xsl:param name="count_field" select="1"/>
        <!-- the status variable determines if the whole 32 bit regiser is made up of single-field registers. 1 for yes, 2 for no.-->
        <xsl:variable name="status">
            <xsl:call-template name="count-fields-in-nodeset">
                <xsl:with-param name="nodes" select="$nodes"/>
            </xsl:call-template>
        </xsl:variable>

        <xsl:variable name="current_id"
            select="substring-after($nodes[$count]/reg-details//xref/@href, '/')"/>

        <xsl:variable name="current_title" select="normalize-space($nodes[$count]/reg-name)"/>

        <xsl:variable name="total_fields"
            select="count(//*[@id = $current_id]/tgroup/registers/register)"/>
        <xsl:variable name="total_nodes" select="count($nodes)"/>

        <xsl:variable name="range">
            <xsl:call-template name="get-range">
                <xsl:with-param name="value_cell"
                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-position"
                />
            </xsl:call-template>
        </xsl:variable>

        <xsl:choose>
            <xsl:when test="$count &gt; $total_nodes"/>
            <xsl:when test="$count_field &gt; $total_fields">
                <xsl:call-template name="process-reg-bits">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit"/>
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="count_field" select="1"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:when test="$count_field &lt;= $total_fields">
                <xsl:if
                    test="not(contains(upper-case(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name), 'RESERVED'))">
                    <!-- Get LSB -->

                    <xsl:variable name="LSB">
                        <xsl:value-of select="$title"/>
                        <xsl:text>_</xsl:text>
                        <!-- If there is only one register in the set, there's no need to append the register name a second time in the field name. -->
                        <xsl:if test="count($nodes) &gt; 1">
                            <xsl:value-of select="$nodes[$count]/reg-name"/>
                            <xsl:text>_</xsl:text>
                        </xsl:if>
                        <!-- If status = 1, there's no need to repeat the reg_name. -->
                        <xsl:choose>
                            <!-- Hack to avoid stripping PCICCISPTR field name. -->
                            <xsl:when test="contains($title, 'CCISPTR')">                                
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:when>
                            <xsl:when test="$status = 1"/>
                            <xsl:otherwise>
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:otherwise>
                        </xsl:choose>
                        <xsl:text>LSB</xsl:text>
                    </xsl:variable>
                    <xsl:text>
#define </xsl:text>
                    <xsl:call-template name="add-spaces">
                        <xsl:with-param name="string" select="normalize-space($LSB)"/>
                    </xsl:call-template>
                    <xsl:text>(</xsl:text>
                    <xsl:value-of select="$current_bit"/>
                    <xsl:text>)</xsl:text>
                    <!-- Get MSB -->

                    <xsl:variable name="MSB">
                        <xsl:value-of select="$title"/>
                        <xsl:text>_</xsl:text>
                        <!-- If there is only one register in the set, there's no need to append the register name a second time in the field name. -->
                        <xsl:if test="count($nodes) &gt; 1">
                            <xsl:value-of select="$nodes[$count]/reg-name"/>
                            <xsl:text>_</xsl:text>
                        </xsl:if>
                        <!-- If status = 1, there's no need to repeat the reg_name. -->
                        <xsl:choose>
                            <!-- Hack to avoid stripping PCICCISPTR field name. -->
                            <xsl:when test="contains($title, 'CCISPTR')">                                
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:when>
                            <xsl:when test="$status = 1"/>
                            <xsl:otherwise>
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:otherwise>
                        </xsl:choose>
                        <xsl:text>MSB</xsl:text>
                    </xsl:variable>

                    <xsl:text>
#define </xsl:text>
                    <xsl:call-template name="add-spaces">
                        <xsl:with-param name="string" select="normalize-space($MSB)"/>
                    </xsl:call-template>
                    <xsl:text>(</xsl:text>
                    <xsl:value-of select="$current_bit + $range - 1"/>
                    <xsl:text>)</xsl:text>
                    <!-- Get Attr  -->

                    <xsl:variable name="ATTR">
                        <xsl:value-of select="$title"/>
                        <xsl:text>_</xsl:text>
                        <!-- If there is only one register in the set, there's no need to append the register name a second time in the field name. -->
                        <xsl:if test="count($nodes) &gt; 1">
                            <xsl:value-of select="$nodes[$count]/reg-name"/>
                            <xsl:text>_</xsl:text>
                        </xsl:if>
                        <!-- If status = 1, there's no need to repeat the reg_name. -->
                        <xsl:choose>
                            <!-- Hack to avoid stripping PCICCISPTR field name. -->
                            <xsl:when test="contains($title, 'CCISPTR')">                                
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:when>
                            <xsl:when test="$status = 1"/>
                            <xsl:otherwise>
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:otherwise>
                        </xsl:choose>
                        <xsl:text>ATTR</xsl:text>
                    </xsl:variable>

                    <xsl:text>
#define </xsl:text>
                    <xsl:call-template name="add-spaces">
                        <xsl:with-param name="string" select="normalize-space($ATTR)"/>
                    </xsl:call-template>
                    <xsl:text>(CSR_FLD_ATTR_</xsl:text>
                    <xsl:value-of
                        select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-type"/>
                    <xsl:text>)</xsl:text>

                    <!-- Get Val  -->
                    <xsl:variable name="VAL">
                        <xsl:value-of select="$title"/>
                        <xsl:text>_</xsl:text>
                        <!-- If there is only one register in the set, there's no need to append the register name a second time in the field name. -->
                        <xsl:if test="count($nodes) &gt; 1">
                            <xsl:value-of select="$nodes[$count]/reg-name"/>
                            <xsl:text>_</xsl:text>
                        </xsl:if>
                        <!-- If status = 1, there's no need to repeat the reg_name. -->
                        <xsl:choose>
                            <!-- Hack to avoid stripping PCICCISPTR field name. -->
                            <xsl:when test="contains($title, 'CCISPTR')">                                
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:when>
                            <xsl:when test="$status = 1"/>
                            <xsl:otherwise>
                                <xsl:value-of
                                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-name"/>
                                <xsl:text>_</xsl:text>
                            </xsl:otherwise>
                        </xsl:choose>
                        <xsl:text>VAL</xsl:text>
                    </xsl:variable>

                    <xsl:text>
#define </xsl:text>
                    <xsl:call-template name="add-spaces">
                        <xsl:with-param name="string" select="normalize-space($VAL)"/>
                    </xsl:call-template>
                    <xsl:text>(</xsl:text>
                    <xsl:choose>
                        <xsl:when
                            test="contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default, '0x')">
                            <xsl:text>0x</xsl:text>
                            <xsl:call-template name="form-hex-value">
                                <xsl:with-param name="string"
                                    select="substring-after(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default , '0x')"
                                />
                            </xsl:call-template>
                        </xsl:when>
                        <xsl:when
                            test="contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default, 'FWINIT')">
                            <xsl:text>0x00000000</xsl:text>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:value-of
                                select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default"
                            />
                        </xsl:otherwise>
                    </xsl:choose>
                    <xsl:text>)                 
                 </xsl:text>
                </xsl:if>
                <xsl:call-template name="process-reg-bits">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit + number($range)"/>
                    <xsl:with-param name="count" select="$count"/>
                    <xsl:with-param name="count_field" select="$count_field + 1"/>
                </xsl:call-template>
            </xsl:when>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="count-fields-in-nodeset">
        <xsl:param name="nodes"/>
        <xsl:param name="count" select="1"/>
        <xsl:param name="status" select="1"/>

        <!-- In order for this condition to be satisfied, every node in the set has to have only a single field and every field must have the same
      name as its register title -->

        <xsl:variable name="current_id"
            select="substring-after($nodes[$count]/reg-details//xref/@href, '/')"/>

        <xsl:variable name="current_title" select="normalize-space($nodes[$count]/reg-name)"/>

        <xsl:variable name="count-current-fields" select="count($nodes[$count]/register)"/>

        <xsl:choose>
            <!-- When you've counted all the nodes, return the status. 1 for all singles, 2 for at least one multi -->
            <xsl:when test="$count &gt; count($nodes)">
                <xsl:value-of select="$status"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:call-template name="count-fields-in-nodeset">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="status">
                        <xsl:choose>
                            <xsl:when
                                test="$count-current-fields &gt; 1 or not($current_title = normalize-space(//*[@id = $current_id]/tgroup/registers/register[1]/reg-name))">
                                <xsl:value-of select="2"/>
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:value-of select="$status"/>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:with-param>
                </xsl:call-template>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>

    <xsl:template name="default-value">
        <!-- the whole node set -->
        <xsl:param name="nodes"/>
        <!-- current bit is the next available bit position in the 32 bit chunk -->
        <xsl:param name="current_bit" select="0"/>
        <!-- count is the number of nodes in the current set  -->
        <xsl:param name="count" select="1"/>
        <!-- count field is the number of fields in the current register  -->
        <xsl:param name="count_field" select="1"/>
        <!-- running total is the accumulated default value of the nodeset -->
        <xsl:param name="running_total" select="0"/>

        <xsl:variable name="current_id"
            select="substring-after($nodes[$count]/reg-details//xref/@href, '/')"/>

        <xsl:variable name="total_fields"
            select="count(//*[@id = $current_id]/tgroup/registers/register)"/>
        <xsl:variable name="total_nodes" select="count($nodes)"/>

        <xsl:variable name="range">
            <xsl:call-template name="get-range">
                <xsl:with-param name="value_cell"
                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-position"
                />
            </xsl:call-template>
        </xsl:variable>

        <!-- convert the bit default to binary so that we can prepend it to the mask value -->
        <xsl:variable name="bit_default" as="xs:string">
            <xsl:choose>
                <xsl:when
                    test="number(substring-after(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default, '0x')) = 0"
                    >0</xsl:when>
                <xsl:when
                    test="contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default, '0x')">
                    <xsl:variable name="temp">
                        <xsl:call-template name="math:base-convert">
                            <xsl:with-param name="from-base" select="16"/>
                            <xsl:with-param name="to-base" select="2"/>
                            <xsl:with-param name="value"
                                select="substring-after(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-default, '0x')"
                            />
                        </xsl:call-template>
                    </xsl:variable>
                    <xsl:value-of select="$temp"/>
                </xsl:when>
                <xsl:otherwise>0</xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <!-- Create a bit mask of the approprite size  -->
        <xsl:variable name="bit_mask">
            <xsl:choose>
                <xsl:when test="number($current_bit) &gt; 0">
                    <xsl:value-of
                        select="substring('00000000000000000000000000000000', 1, $current_bit)"/>
                </xsl:when>
                <xsl:otherwise/>
            </xsl:choose>
        </xsl:variable>

        <!-- concat the default and the mask value and convert to decimal -->
        <xsl:variable name="current_default">
            <xsl:variable name="valueAndMask" select="concat($bit_default, $bit_mask)"/>
            <xsl:if test="contains($valueAndMask, '1')">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="2"/>
                    <xsl:with-param name="to-base" select="10"/>
                    <xsl:with-param name="value" select="$valueAndMask"/>
                </xsl:call-template>
            </xsl:if>
            <xsl:if test="not(contains($valueAndMask, '1'))">0</xsl:if>
        </xsl:variable>

        <xsl:variable name="current_default_in_hex">
            <xsl:variable name="valueAndMask" select="concat($bit_default, $bit_mask)"/>
            <xsl:if test="contains($valueAndMask, '1')">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="2"/>
                    <xsl:with-param name="to-base" select="16"/>
                    <xsl:with-param name="value" select="$valueAndMask"/>
                </xsl:call-template>
            </xsl:if>
            <xsl:if test="not(contains($valueAndMask, '1'))">0</xsl:if>
        </xsl:variable>

        <xsl:choose>
            <xsl:when test="$count &gt; $total_nodes">
                <xsl:if test="xs:integer($running_total + $current_default) &gt; 0">
                    <xsl:text>0x</xsl:text>
                    <xsl:call-template name="form-hex-value">
                        <xsl:with-param name="string">
                            <xsl:call-template name="math:base-convert">
                                <xsl:with-param name="from-base" select="10"/>
                                <xsl:with-param name="to-base" select="16"/>
                                <xsl:with-param name="value" select="xs:integer($running_total)"/>
                            </xsl:call-template>
                        </xsl:with-param>
                    </xsl:call-template>
                </xsl:if>
                <xsl:if test="not(xs:integer($running_total + $current_default) &gt; 0)"
                    >0x00000000</xsl:if>
            </xsl:when>
            <xsl:when test="$count_field &gt; $total_fields">
                <xsl:call-template name="default-value">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit"/>
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="count_field" select="1"/>
                    <xsl:with-param name="running_total"
                        select="xs:integer($running_total + $current_default)"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:when test="$count_field &lt;= $total_fields">
                <xsl:call-template name="default-value">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit + number($range)"/>
                    <xsl:with-param name="count" select="$count"/>
                    <xsl:with-param name="count_field" select="$count_field + 1"/>
                    <xsl:with-param name="running_total"
                        select="xs:integer($running_total + $current_default)"/>
                </xsl:call-template>
            </xsl:when>
        </xsl:choose>

    </xsl:template>

    <xsl:template name="write-mask-value">
        <!-- the whole node set -->
        <xsl:param name="nodes"/>
        <!-- current bit is the next available bit position in the 32 bit chunk -->
        <xsl:param name="current_bit" select="0"/>
        <!-- count is the number of nodes in the current set  -->
        <xsl:param name="count" select="1"/>
        <!-- count field is the number of fields in the current register  -->
        <xsl:param name="count_field" select="1"/>
        <!-- running total is the accumulated default value of the nodeset -->
        <xsl:param name="running_total" select="0"/>

        <xsl:variable name="current_id"
            select="substring-after($nodes[$count]/reg-details//xref/@href, '/')"/>

        <xsl:variable name="total_fields"
            select="count(//*[@id = $current_id]/tgroup/registers/register)"/>
        <xsl:variable name="total_nodes" select="count($nodes)"/>

        <xsl:variable name="range">
            <xsl:call-template name="get-range">
                <xsl:with-param name="value_cell"
                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-position"
                />
            </xsl:call-template>
        </xsl:variable>

        <!-- convert the bit default to binary so that we can prepend it to the mask value -->
        <xsl:variable name="bit_default" as="xs:string">
            <xsl:choose>
                <xsl:when
                    test="(contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-type, 'W') or contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-type, 'w')) and not(contains(upper-case(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-type), 'RWL'))">
                    <xsl:variable name="temp">
                        <xsl:call-template name="generate-bit-value">
                            <xsl:with-param name="range">
                                <xsl:value-of select="$range"/>
                            </xsl:with-param>
                        </xsl:call-template>
                    </xsl:variable>
                    <xsl:value-of select="$temp"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="0"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <!-- Create a bit mask of the approprite size  -->
        <xsl:variable name="bit_mask">
            <xsl:choose>
                <xsl:when test="number($current_bit) &gt; 0">
                    <xsl:value-of
                        select="substring('00000000000000000000000000000000', 1, $current_bit)"/>
                </xsl:when>
                <xsl:otherwise/>
            </xsl:choose>
        </xsl:variable>


        <!-- concat the default and the mask value and convert to decimal -->
        <xsl:variable name="current_default">
            <xsl:variable name="valueAndMask" select="concat($bit_default, $bit_mask)"/>
            <xsl:if test="contains($valueAndMask, '1')">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="2"/>
                    <xsl:with-param name="to-base" select="10"/>
                    <xsl:with-param name="value" select="$valueAndMask"/>
                </xsl:call-template>
            </xsl:if>
            <xsl:if test="not(contains($valueAndMask, '1'))">0</xsl:if>
        </xsl:variable>

        <xsl:variable name="current_default_in_hex">
            <xsl:variable name="valueAndMask" select="concat($bit_default, $bit_mask)"/>
            <xsl:if test="contains($valueAndMask, '1')">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="2"/>
                    <xsl:with-param name="to-base" select="16"/>
                    <xsl:with-param name="value" select="$valueAndMask"/>
                </xsl:call-template>
            </xsl:if>
            <xsl:if test="not(contains($valueAndMask, '1'))">0</xsl:if>
        </xsl:variable>


        <xsl:choose>
            <xsl:when test="$count &gt; $total_nodes">
                <xsl:if test="xs:integer($running_total + $current_default) &gt; 0">
                    <xsl:text>0x</xsl:text>
                    <xsl:call-template name="form-hex-value">
                        <xsl:with-param name="string">
                            <xsl:call-template name="math:base-convert">
                                <xsl:with-param name="from-base" select="10"/>
                                <xsl:with-param name="to-base" select="16"/>
                                <xsl:with-param name="value" select="xs:integer($running_total)"/>
                            </xsl:call-template>
                        </xsl:with-param>
                    </xsl:call-template>
                </xsl:if>
                <xsl:if test="not(xs:integer($running_total + $current_default) &gt; 0)"
                    >0x00000000</xsl:if>
            </xsl:when>
            <xsl:when test="$count_field &gt; $total_fields">
                <xsl:call-template name="write-mask-value">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit"/>
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="count_field" select="1"/>
                    <xsl:with-param name="running_total"
                        select="xs:integer($running_total + $current_default)"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:when test="$count_field &lt;= $total_fields">
                <xsl:call-template name="write-mask-value">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit + number($range)"/>
                    <xsl:with-param name="count" select="$count"/>
                    <xsl:with-param name="count_field" select="$count_field + 1"/>
                    <xsl:with-param name="running_total"
                        select="xs:integer($running_total + $current_default)"/>
                </xsl:call-template>
            </xsl:when>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="sticky-mask-value">
        <!-- the whole node set -->
        <xsl:param name="nodes"/>
        <!-- current bit is the next available bit position in the 32 bit chunk -->
        <xsl:param name="current_bit" select="0"/>
        <!-- count is the number of nodes in the current set  -->
        <xsl:param name="count" select="1"/>
        <!-- count field is the number of fields in the current register  -->
        <xsl:param name="count_field" select="1"/>
        <!-- running total is the accumulated default value of the nodeset -->
        <xsl:param name="running_total" select="0"/>

        <xsl:variable name="current_id"
            select="substring-after($nodes[$count]/reg-details//xref/@href, '/')"/>

        <xsl:variable name="total_fields"
            select="count(//*[@id = $current_id]/tgroup/registers/register)"/>
        <xsl:variable name="total_nodes" select="count($nodes)"/>

        <xsl:variable name="range">
            <xsl:call-template name="get-range">
                <xsl:with-param name="value_cell"
                    select="//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-position"
                />
            </xsl:call-template>
        </xsl:variable>

        <!-- convert the bit default to binary so that we can prepend it to the mask value -->
        <xsl:variable name="bit_default" as="xs:string">
            <xsl:choose>
                <xsl:when
                    test="contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-type, 'S') or contains(//*[@id = $current_id]/tgroup/registers/register[$count_field]/reg-type, 's')">
                    <xsl:variable name="temp">
                        <xsl:call-template name="generate-bit-value">
                            <xsl:with-param name="range">
                                <xsl:value-of select="$range"/>
                            </xsl:with-param>
                        </xsl:call-template>
                    </xsl:variable>
                    <xsl:value-of select="$temp"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="0"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <!-- Create a bit mask of the approprite size  -->
        <xsl:variable name="bit_mask">
            <xsl:choose>
                <xsl:when test="number($current_bit) &gt; 0">
                    <xsl:value-of
                        select="substring('00000000000000000000000000000000', 1, $current_bit)"/>
                </xsl:when>
                <xsl:otherwise/>
            </xsl:choose>
        </xsl:variable>


        <!-- concat the default and the mask value and convert to decimal -->
        <xsl:variable name="current_default">
            <xsl:variable name="valueAndMask" select="concat($bit_default, $bit_mask)"/>
            <xsl:if test="contains($valueAndMask, '1')">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="2"/>
                    <xsl:with-param name="to-base" select="10"/>
                    <xsl:with-param name="value" select="$valueAndMask"/>
                </xsl:call-template>
            </xsl:if>
            <xsl:if test="not(contains($valueAndMask, '1'))">0</xsl:if>
        </xsl:variable>

        <xsl:variable name="current_default_in_hex">
            <xsl:variable name="valueAndMask" select="concat($bit_default, $bit_mask)"/>
            <xsl:if test="contains($valueAndMask, '1')">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="2"/>
                    <xsl:with-param name="to-base" select="16"/>
                    <xsl:with-param name="value" select="$valueAndMask"/>
                </xsl:call-template>
            </xsl:if>
            <xsl:if test="not(contains($valueAndMask, '1'))">0</xsl:if>
        </xsl:variable>

        <xsl:choose>
            <xsl:when test="$count &gt; $total_nodes">
                <xsl:if test="xs:integer($running_total + $current_default) &gt; 0">
                    <xsl:text>0x</xsl:text>
                    <xsl:call-template name="form-hex-value">
                        <xsl:with-param name="string">
                            <xsl:call-template name="math:base-convert">
                                <xsl:with-param name="from-base" select="10"/>
                                <xsl:with-param name="to-base" select="16"/>
                                <xsl:with-param name="value" select="xs:integer($running_total)"/>
                            </xsl:call-template>
                        </xsl:with-param>
                    </xsl:call-template>
                </xsl:if>
                <xsl:if test="not(xs:integer($running_total + $current_default) &gt; 0)"
                    >0x00000000</xsl:if>
            </xsl:when>
            <xsl:when test="$count_field &gt; $total_fields">
                <xsl:call-template name="sticky-mask-value">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit"/>
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="count_field" select="1"/>
                    <xsl:with-param name="running_total"
                        select="xs:integer($running_total + $current_default)"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:when test="$count_field &lt;= $total_fields">
                <xsl:call-template name="sticky-mask-value">
                    <xsl:with-param name="nodes" select="$nodes"/>
                    <xsl:with-param name="current_bit" select="$current_bit + number($range)"/>
                    <xsl:with-param name="count" select="$count"/>
                    <xsl:with-param name="count_field" select="$count_field + 1"/>
                    <xsl:with-param name="running_total"
                        select="xs:integer($running_total + $current_default)"/>
                </xsl:call-template>
            </xsl:when>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="generate-bit-value">
        <xsl:param name="range"/>
        <xsl:param name="count" select="1"/>
        <xsl:param name="bit_string"/>
        <xsl:choose>
            <xsl:when test="xs:integer($count) &lt;= xs:integer($range)">
                <xsl:call-template name="generate-bit-value">
                    <xsl:with-param name="range" select="xs:integer($range)"/>
                    <xsl:with-param name="count" select="xs:integer($count) +1"/>
                    <xsl:with-param name="bit_string" select="concat($bit_string, '1')"/>
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="$bit_string"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="get-range">
        <xsl:param name="value_cell"/>
        <xsl:choose>
            <xsl:when test="$value_cell/single">
                <xsl:value-of select="1"/>
            </xsl:when>
            <xsl:when test="$value_cell/double">
                <xsl:value-of
                    select="number(normalize-space($value_cell/double/msb)) - number(normalize-space($value_cell/double/lsb)) + 1"
                />
            </xsl:when>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="form-bin-value">
        <xsl:param name="lsb"/>
        <xsl:value-of select="substring('0000000000000000000000000000000', number($lsb))"/>
    </xsl:template>

    <xsl:template name="form-hex-value">
        <xsl:param name="string"/>
        <xsl:variable name="length" select="string-length($string)"/>
        <xsl:value-of select="lower-case(substring(concat('00000000', $string), $length + 1, 8))"/>
    </xsl:template>

    <xsl:template name="add-spaces">
        <xsl:param name="string"/>
        <xsl:value-of
            select="substring(concat($string, '                                                             '), 1, 65)"
        />
    </xsl:template>

    <xsl:template name="process-groups">
        <xsl:param name="current-node" select="1"/>
        <xsl:param name="starting-node" select="$current-node"/>
        <xsl:param name="current-field" select="1"/>
        <xsl:param name="total-bits" select="0"/>
        <xsl:param name="offset" select="0"/>

        <xsl:variable name="ending-node" select="count($reg-ref-set[$current-node]/reg-reference)"/>

        <xsl:for-each select="$reg-ref-set[$current-node]/reg-reference[$current-field]">

            <xsl:variable name="bits">
                <xsl:call-template name="units-to-size">
                    <xsl:with-param name="value" select="reg-size"/>
                </xsl:call-template>
            </xsl:variable>

            <xsl:choose>
                <!-- if we've run out of fields, send the batch off to get processed and reset the reg-reference count -->
                <xsl:when test="(count(preceding-sibling::reg-reference) + 1) = $ending-node">
                    <xsl:call-template name="process-reg-group">
                        <xsl:with-param name="ending-node" select="$ending-node"/>
                        <xsl:with-param name="reg-reference-number" select="$current-node"/>
                        <xsl:with-param name="offset" select="$offset"/>
                        <xsl:with-param name="size" select="$total-bits + $bits" tunnel="yes"/>
                    </xsl:call-template>
                    <xsl:if
                        test="not(contains($reg-ref-set[$current-node]/reg-reference[$current-field]/reg-address, 'NONE'))">
                        <!-- This hacks the ridiculas situation we're in with the need to take some of the NVME registers and create a U and an L version
                        which consumes an extra register space, so we increment the starting count 1 to compensate-->
                        <xsl:variable name="starting-count">
                            <xsl:choose>
                                <xsl:when
                                    test="contains($reg-ref-set[$current-node]/reg-reference[$current-field]/reg-name, 'NVMECAP')
                                or contains($reg-ref-set[$current-node]/reg-reference[$current-field]/reg-name, 'NVMEASQ')
                                or contains($reg-ref-set[$current-node]/reg-reference[$current-field]/reg-name, 'NVMEACQ')">
                                    <xsl:value-of select='2'/>
                                </xsl:when>
                                <xsl:otherwise>
                                    <xsl:value-of select="1"/>
                                </xsl:otherwise>                                
                            </xsl:choose>
                        </xsl:variable>
                        <xsl:call-template name="fill-out-empty-registers">
                            <xsl:with-param name="reg-reference-number" select="$current-node"/>
                            <xsl:with-param name="count" select="$starting-count"/>
                        </xsl:call-template>
                    </xsl:if>
                    <xsl:call-template name="process-groups">
                        <xsl:with-param name="current-node" select="$current-node + 1"/>
                        <xsl:with-param name="starting-node" select="$current-node + 1"/>
                        <xsl:with-param name="current-field" select="1"/>
                        <xsl:with-param name="total-bits" select="0"/>
                        <xsl:with-param name="offset" select="$offset + $total-bits + $bits"/>
                    </xsl:call-template>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:call-template name="process-groups">
                        <xsl:with-param name="current-node" select="$current-node"/>
                        <xsl:with-param name="current-field" select="$current-field + 1"/>
                        <xsl:with-param name="total-bits" select="$total-bits + $bits"/>
                        <xsl:with-param name="offset" select="$offset"/>
                    </xsl:call-template>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:for-each>
    </xsl:template>

    <xsl:template name="process-reg-group">
        <xsl:param name="ending-node"/>
        <xsl:param name="title"/>
        <xsl:param name="reg-reference-number"/>
        <xsl:param name="offset"/>
        <xsl:param name="count" select="1"/>
        <xsl:param name="prefix" tunnel="yes"/>
        <xsl:param name="suffix" tunnel="yes"/>

        <xsl:variable name="dec_offset">
            <!-- hacked to account for reg-references with an address value of NONE. Define 1040 to avoid trigging the PCI hack -->
            <xsl:choose>
                <xsl:when
                    test="contains($reg-ref-set[$reg-reference-number]/reg-reference[1]/reg-address, 'NONE')">
                    <xsl:value-of select="1040"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:call-template name="hex2dec">
                        <xsl:with-param name="hex"
                            select="substring-after($reg-ref-set[$reg-reference-number]/reg-reference[1]/reg-address, '0x')"
                        />
                    </xsl:call-template>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>

        <xsl:variable name="hex_offset">
            <xsl:call-template name="dec2hex">
                <xsl:with-param name="dec" select="$dec_offset"/>
            </xsl:call-template>
        </xsl:variable>

        <xsl:choose>
            <xsl:when test="(number($count)) &lt;= number($ending-node)">
                <xsl:call-template name="process-reg-group">
                    <xsl:with-param name="count" select="$count + 1"/>
                    <xsl:with-param name="offset" select="$offset"/>
                    <xsl:with-param name="ending-node" select="$ending-node"/>
                    <xsl:with-param name="reg-reference-number" select="$reg-reference-number"/>
                    <xsl:with-param name="title">
                        <xsl:value-of select="$title"/>
                        <xsl:if test="string-length($title) &gt; 0">
                            <xsl:text>_</xsl:text>
                        </xsl:if>
                        <xsl:value-of
                            select="$reg-ref-set[$reg-reference-number]/reg-reference[$count]/reg-name"
                        />
                    </xsl:with-param>
                </xsl:call-template>
            </xsl:when>
            <xsl:otherwise>
                <!-- If it's one of the NONE offest values, don't do a new line because we're not making an entry. -->
                <xsl:if test="not(contains($reg-ref-set[$reg-reference-number]/reg-reference[1]/reg-address, 'NONE') or contains($title, 'PCIEL0EQCTL') or contains($title, 'PCIEL2EQCTL') or contains($title, 'PCIEL4EQCTL') or contains($title, 'PCIEL6EQCTL'))">
                <xsl:text>               
           </xsl:text> 
                </xsl:if> 
                <xsl:variable name="NVMe">
                    <xsl:call-template name="isNMVe">
                        <xsl:with-param name="title" select="$title"/>
                    </xsl:call-template>
                </xsl:variable>
                <xsl:choose>
                    <xsl:when test="contains($reg-ref-set[$reg-reference-number]/reg-reference[1]/reg-address, 'NONE')"/>
                    <xsl:when
                        test="$NVMe = 1 and not(contains($suffix, 'STICKY_MSK')) and contains($title, 'NVMECAP')">
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>L</xsl:text>
                        <xsl:text>,
           </xsl:text>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>U</xsl:text>
                        <xsl:text>,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and not(contains($suffix, 'STICKY_MSK')) and contains($title, 'NVMECC')">
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>L</xsl:text>
                        <xsl:text>,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and not(contains($suffix, 'STICKY_MSK')) and contains($title, 'NVMEASQ')">
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>L</xsl:text>
                        <xsl:text>,
           </xsl:text>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>U</xsl:text>
                        <xsl:text>,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and not(contains($suffix, 'STICKY_MSK')) and contains($title, 'NVMEACQ')">
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>L</xsl:text>
                        <xsl:text>,
           </xsl:text>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>U</xsl:text>
                        <xsl:text>,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and contains($suffix, 'STICKY_MSK') and contains($title, 'NVMECAP')">
                        <xsl:text>0x00000000L,
           0x00000000U,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and contains($suffix, 'STICKY_MSK') and contains($title, 'NVMECC')">
                        <xsl:text>0x00000000L</xsl:text>
                        <xsl:text>,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and contains($suffix, 'STICKY_MSK') and contains($title, 'NVMEASQ')">
                        <xsl:text>0x00000000L,
           0x00000000U,</xsl:text>
                    </xsl:when>
                    <xsl:when
                        test="$NVMe = 1 and contains($suffix, 'STICKY_MSK') and contains($title, 'NVMEACQ')">
                        <xsl:text>0x00000000L,
           0x00000000U,</xsl:text>
                    </xsl:when>
                    <xsl:when test="$NVMe = 1 and contains($suffix, 'WR_MSK')">
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:call-template name="nmve-title">
                            <xsl:with-param name="title" select="$title"/>
                        </xsl:call-template>
                        <xsl:text>_WR_MSK</xsl:text>
                    </xsl:when>
                    <xsl:when test="$NVMe = 1 and contains($suffix, 'STICKY_MSK')">
                        <xsl:text>0x00000000,</xsl:text>
                    </xsl:when>
                    <xsl:when test="contains($title, 'PCIEL0EQCTL') or
                        contains($title, 'PCIEL2EQCTL') or
                        contains($title, 'PCIEL4EQCTL') or
                        contains($title, 'PCIEL6EQCTL')"/>
                    <xsl:otherwise>
                        <xsl:if
                            test="(number($dec_offset) * 8) &lt; 512 and not(substring($title, 1, 3) = 'PCI')">
                            <xsl:text>PCI</xsl:text>
                        </xsl:if>
                        <xsl:value-of select="$prefix"/>
                        <xsl:if test="string-length($prefix) &gt; 1">_</xsl:if>
                        <xsl:choose>
                            <xsl:when test="contains(substring(upper-case($title), 1, 4), 'NVME')">
                                <xsl:call-template name="nmve-title">
                                    <xsl:with-param name="title" select="$title"/>
                                </xsl:call-template>
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:value-of select="$title"/>
                            </xsl:otherwise>
                        </xsl:choose>
                        <xsl:if test="string-length($suffix) &gt; 1">_</xsl:if>
                        <xsl:value-of select="$suffix"/>
                        <xsl:text>,</xsl:text>
                    </xsl:otherwise>
                </xsl:choose>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="fill-out-empty-registers">
        <xsl:param name="reg-reference-number"/>
        <xsl:param name="count" select="1"/>
        <xsl:variable name="offset">
            <xsl:if test="$reg-reference-number = 1">
                <xsl:value-of select="0"/>
            </xsl:if>
            <xsl:if test="$reg-reference-number &gt; 1">
                <xsl:call-template name="math:base-convert">
                    <xsl:with-param name="from-base" select="16"/>
                    <xsl:with-param name="to-base" select="10"/>
                    <xsl:with-param name="value"
                        select="substring-after(normalize-space($reg-ref-set[$reg-reference-number]/reg-reference[1]/reg-address), '0x')"
                    />
                </xsl:call-template>
            </xsl:if>
        </xsl:variable>
        <xsl:variable name="next-offset">
            <xsl:choose>
                <xsl:when test="$reg-ref-set[$reg-reference-number] = $reg-ref-set[last()]">
                    <xsl:value-of select="0"/>
                </xsl:when>
                <xsl:when
                    test="contains($reg-ref-set[$reg-reference-number + 1]/reg-reference[1]/reg-address, 'NONE')">
                    <xsl:value-of select="0"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:call-template name="math:base-convert">
                        <xsl:with-param name="from-base" select="16"/>
                        <xsl:with-param name="to-base" select="10"/>
                        <xsl:with-param name="value"
                            select="substring-after(normalize-space($reg-ref-set[number($reg-reference-number) + 1]/reg-reference[1]/reg-address), '0x')"
                        />
                    </xsl:call-template>
                </xsl:otherwise>
            </xsl:choose>

        </xsl:variable>
        <!-- Caculate the number of registers by dividing the decimal offset value by 4 and then subtracting 1 for the current register -->
        <!-- If the register is one of the special NVME registers that has a U and L added, add 1 more to the current sum to account for the
        added line -->
        <xsl:variable name="registers">
            <xsl:variable name="temp">
                <xsl:if test="xs:integer($offset) &lt;= 0">
                    <xsl:value-of select="1"/>
                </xsl:if>
                <xsl:if test="xs:integer($offset) &gt; 0">
                    <xsl:value-of
                        select="(xs:integer($next-offset) div 4) - (xs:integer($offset) div 4)"/>
                </xsl:if>
            </xsl:variable>
            <xsl:choose>
                <xsl:when test="$temp &lt; 1">
                    <xsl:value-of select="1"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="$temp"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:choose>
            <xsl:when test="number($registers) &lt;= number($count)"/>
            <xsl:otherwise>
                <xsl:text>
           0x00000000,</xsl:text>
                <xsl:call-template name="fill-out-empty-registers">
                    <xsl:with-param name="reg-reference-number" select="$reg-reference-number"/>
                    <xsl:with-param name="count" select="$count + 1"/>
                </xsl:call-template>
            </xsl:otherwise>
        </xsl:choose>

    </xsl:template>

    <xsl:template name="units-to-size">
        <xsl:param name="value"/>
        <xsl:variable name="processed-value" select="upper-case(normalize-space($value))"/>
        <xsl:variable name="multiplier">
            <xsl:choose>
                <xsl:when test="contains(substring-before($processed-value, ' '), '1')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '2')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '3')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '4')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '5')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '6')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '7')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '8')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '9')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '0')">
                    <xsl:value-of select="number(substring-before($processed-value, ' '))"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="1"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:variable name="unit">
            <xsl:choose>
                <xsl:when test="contains(substring-before($processed-value, ' '), '1')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '2')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '3')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '4')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '5')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '6')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '7')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '8')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '9')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:when test="contains(substring-before($processed-value, ' '), '0')">
                    <xsl:value-of select="substring-after($processed-value, ' ')"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="$processed-value"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:choose>
            <xsl:when test="contains($unit,'QWORD')">
                <xsl:value-of select="64 * $multiplier"/>
            </xsl:when>
            <xsl:when test="contains($unit,'DWORD')">
                <xsl:value-of select="32 * $multiplier"/>
            </xsl:when>
            <xsl:when test="contains($unit,'WORD')">
                <xsl:value-of select="16 * $multiplier"/>
            </xsl:when>
            <xsl:when test="contains($unit,'BYTE')">
                <xsl:value-of select="8 * $multiplier"/>
            </xsl:when>
            <xsl:otherwise>
                <message>What the Dickens? The units-to-size template failed! The value it choked on
                    was: <xsl:value-of select="$value"/></message>
            </xsl:otherwise>
        </xsl:choose>
        <xsl:text>                
</xsl:text>
    </xsl:template>

    <xsl:template name="isNMVe">
        <xsl:param name="title"/>
        <xsl:choose>
            <xsl:when test="contains(substring($title, 1, 4), 'NVME')">
                <xsl:value-of select="1"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="0"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="nmve-title">
        <xsl:param name="title"/>
        <xsl:text>NVME_</xsl:text>
        <xsl:value-of select="substring-after(upper-case($title), 'NVME')"/>
    </xsl:template>

</xsl:stylesheet>
