<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac" version="2.0">


    <xsl:template name="struct">
        <xsl:param name="tableset"/>
        <xsl:variable name="title">
            <xsl:call-template name="get-file-title">
                <xsl:with-param name="title"
                    select="/bookmap/topic[1]/title[1]"
                />
            </xsl:call-template>
        </xsl:variable>
        <xsl:for-each select="$tableset/descendant-or-self::*[contains(@class, ' topic/table ')]">
            <xsl:variable name="table_name">
                <xsl:call-template name="process_struct_name"><xsl:with-param name="name"
                        select="*[contains(@class, ' topic/title ')]"/></xsl:call-template>
            </xsl:variable>
            <xsl:text>
/** 
* @brief Structure declaration for the </xsl:text><xsl:value-of
                select="*[contains(@class, ' topic/title ')]"/><xsl:text> message
*/
 typedef union
  {
  struct
      { </xsl:text>
            <xsl:for-each select="descendant::*[contains(@class, ' struct-d/dword ')]">
                <xsl:call-template name="struct-documentation"/>
                <xsl:call-template name="struct-declaration"><xsl:with-param name="title"
                        select="$title"/></xsl:call-template>
            </xsl:for-each>
            <xsl:text>
     };
  </xsl:text><xsl:value-of select="$datatype"
                /><xsl:text> dw[</xsl:text><xsl:call-template name="count-dwords"><xsl:with-param
                    name="dwords" select="descendant::*[contains(@class, ' struct-d/value ')]"
                /></xsl:call-template><xsl:text>];
} </xsl:text><xsl:value-of select="$table_name"
            />; </xsl:for-each>
    </xsl:template>

    <xsl:template name="struct-documentation">
        <xsl:text>
        /**
        * DWORD:</xsl:text>
        <xsl:value-of select="*[contains(@class, ' struct-d/value ')]"/>
        <xsl:if test="not(*[contains(@class, ' struct-d/value ')][contains(., ':')])">
            <xsl:text>   BITS: </xsl:text>
            <xsl:call-template name="struct-get-position"/>
        </xsl:if>
        <xsl:apply-templates select="*[contains(@class, ' struct-d/description ')]" mode="struct"/>
        <xsl:text>
        */
 </xsl:text>
    </xsl:template>

    <xsl:template name="struct-declaration">
        <xsl:param name="title"/>
        <xsl:text>        </xsl:text>       
                <xsl:value-of select="$datatype"/>
                <xsl:text> </xsl:text>
                <xsl:call-template name="struct-get-field-name"/>
        <xsl:choose>
            <xsl:when test="*[contains(@class, ' struct-d/value ')][contains(., ':')]">
                <xsl:variable name="bit_count" select="number(substring-before(*[contains(@class, ' struct-d/value ')], ':')) - number(substring-after(*[contains(@class, ' struct-d/value ')], ':')) + 1"/>
                <xsl:if test="number($bit_count) &lt; 32">
                <xsl:text>[</xsl:text>
                <xsl:value-of
                    select="$bit_count"/>
                <xsl:text>]</xsl:text>
                </xsl:if>
            </xsl:when>
            <xsl:otherwise>
                <xsl:variable name="bit_range"><xsl:call-template name="struct-calculate-bits"/></xsl:variable>
                <xsl:if test="number($bit_range) &lt; 32">
                <xsl:text> : </xsl:text>
                <xsl:value-of select="$bit_range"></xsl:value-of>
                <xsl:text/>
                </xsl:if>
            </xsl:otherwise>
        </xsl:choose>
        <xsl:text>;</xsl:text>
    </xsl:template>

    <xsl:template name="struct-get-position">
        <xsl:choose>
            <xsl:when test="descendant::*[contains(@class, ' struct-d/single ')]">
                <xsl:value-of select="descendant::*[contains(@class, ' struct-d/single ')]"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of select="descendant::*[contains(@class, ' struct-d/msb ')]"
                    />:<xsl:value-of select="descendant::*[contains(@class, ' struct-d/lsb ')]"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template name="struct-get-field-name">
        <xsl:variable name="name">
            <xsl:choose>
                <xsl:when test="contains(*[contains(@class, ' struct-d/name ')], 'reserve') or contains(*[contains(@class, ' struct-d/name ')], 'Reserve')">
                    <xsl:value-of select="*[contains(@class, ' struct-d/name ')]"/>
                    <xsl:for-each select="*[contains(@class, ' struct-d/name ')]">
                     <xsl:call-template name="calculate-reserved-field-position"/>
                    </xsl:for-each>
                </xsl:when>
                <xsl:otherwise><xsl:value-of select="*[contains(@class, ' struct-d/name ')]"/></xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:call-template name="process_struct_field">            
            <xsl:with-param name="name" select="$name"/>
        </xsl:call-template>
    </xsl:template>

    <xsl:template name="struct-calculate-bits">
        <xsl:choose>
            <xsl:when test="descendant::*[contains(@class, ' struct-d/single ')]">
                <xsl:text>1</xsl:text>
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of
                    select="number(descendant::*[contains(@class, ' struct-d/msb ')]) - number(descendant::*[contains(@class, ' struct-d/lsb ')]) + 1"
                />
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template match="*" mode="struct">
        <xsl:apply-templates mode="struct"/>
    </xsl:template>

    <xsl:template match="*[contains(@class, ' topic/p ')]" mode="struct">
        <xsl:text>
        * </xsl:text>
        <xsl:value-of select="normalize-space(.)"/>
    </xsl:template>

    <xsl:template match="*[contains(@class, ' topic/li ')]" mode="struct">
        <xsl:choose>
            <xsl:when test="not(child::*[contains(@class, ' topic/p ')])">
                <xsl:text>
        *- </xsl:text>
                <xsl:value-of select="normalize-space(.)"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:apply-templates mode="struct"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template
        match="*[contains(@class, ' topic/p ')][parent::*[contains(@class, ' topic/li ')]]"
        mode="struct">
        <xsl:choose>
            <xsl:when test="not(preceding-sibling::*[contains(@class, ' topic/p ')])">
                <xsl:text>
        *- </xsl:text>
                <xsl:value-of select="normalize-space(.)"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:text>
        *  </xsl:text>
                <xsl:value-of select="normalize-space(.)"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>

    <xsl:template
        match="*[contains(@class, ' topic/p ')][parent::*[contains(@class, ' topic/ol ')]]"
        mode="struct">
        <xsl:text>
        * </xsl:text>
        <xsl:number/>
        <xsl:text>. </xsl:text>
        <xsl:value-of select="normalize-space(.)"/>
    </xsl:template>

    <xsl:template match="*[parent::*[contains(@class, ' topic/p ')]]" mode="struct">
        <xsl:value-of select="."/>
    </xsl:template>

    <xsl:template name="process_struct_name">
        <xsl:param name="name"/>
        <xsl:variable name="temp">
            <xsl:call-template name="add-underscores">
                <xsl:with-param name="name" select="$name"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:value-of select="lower-case($temp)"/>_t </xsl:template>

    <xsl:template name="process_struct_field">
        <xsl:param name="name"/>        
        <xsl:variable name="name-length" select="string-length($name)"/>
        <xsl:variable name="first_letter" select="lower-case(substring($name, 1, 1))"/>
        <xsl:value-of select="$first_letter"/>
        <xsl:value-of select="substring($name, 2, ($name-length - 1))"/>       
    </xsl:template>

    <xsl:template name="count-dwords">
        <xsl:param name="dwords"/>
        <xsl:variable name="temp" select="$dwords[last()]"/>       
            <xsl:choose>
                <xsl:when test="contains($temp, ':')">
                    <xsl:value-of select="number(normalize-space(substring-before($temp, ':'))) + 1"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="number(normalize-space($temp)) + 1"/>
                </xsl:otherwise>
            </xsl:choose>
    </xsl:template>

 

</xsl:stylesheet>
