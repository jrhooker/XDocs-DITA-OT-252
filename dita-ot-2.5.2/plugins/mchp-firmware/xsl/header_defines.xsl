<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac" version="2.0">
    
    <xsl:template name="defines">
        <xsl:param name="tableset"/>
        <xsl:for-each select="$tableset/descendant-or-self::*[contains(@class, ' topic/table ')]">
            <xsl:variable name="table_name">
                <xsl:call-template name="process-message-name">
                    <xsl:with-param name="name" select="*[contains(@class, ' topic/title ')]"/>
                </xsl:call-template>
            </xsl:variable>
            <xsl:call-template name="dword-defines">
                <xsl:with-param name="table" select="."/>
                <xsl:with-param name="dword_number" select="0"/>
            </xsl:call-template>
        </xsl:for-each>
    </xsl:template>
    
    <xsl:template name="dword-defines">
        <xsl:param name="table"/>
        <xsl:param name="dword_number" select="0"/>
        <xsl:param name="dword_limit" select="100"/>
        <xsl:variable name="table_name">
            <xsl:call-template name="process-message-name">
                <xsl:with-param name="name" select="*[contains(@class, ' topic/title ')]"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:if
            test="$table/descendant::*[contains(@class, ' struct-d/value ')][number(.) = $dword_number]">
            <xsl:text>                
/** 
* @brief Macro to create dword</xsl:text>
            <xsl:value-of select="$dword_number"/>
            <xsl:text> for message </xsl:text>
            <xsl:value-of select="$table_name"/>
            <xsl:text>
*/
#define </xsl:text>
            <xsl:value-of select="$table_name"/>
            <xsl:text>_DW</xsl:text>
            <xsl:value-of select="$dword_number"/>
            <xsl:call-template name="define-field-list">
                <xsl:with-param name="dword_number" select="$dword_number"/>
                <xsl:with-param name="table" select="$table"/>
            </xsl:call-template>
            <xsl:call-template name="define-load-fields">
                <xsl:with-param name="table" select="$table"/>
                <xsl:with-param name="dword_number" select="$dword_number"/>
            </xsl:call-template>
            <xsl:text>   
  </xsl:text>
        </xsl:if>
        <xsl:if test="$dword_number &lt; $dword_limit">
            <xsl:call-template name="dword-defines">
                <xsl:with-param name="table" select="$table"/>
                <xsl:with-param name="dword_number" select="$dword_number + 1"/>
            </xsl:call-template>
        </xsl:if>
        
    </xsl:template>
    
    
    <xsl:template name="define-field-list">
        <xsl:param name="dword_number"/>
        <xsl:param name="table"/>
        <xsl:variable name="table_name">
            <xsl:call-template name="process-message-name">
                <xsl:with-param name="name" select="*[contains(@class, ' topic/title ')]"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="node-count"
            select="count($table/descendant::*[contains(@class, ' struct-d/value ')][number(.) = $dword_number]/following-sibling::*[contains(@class, ' struct-d/name ')][not(contains(., 'reserve') or contains(., 'Reserve'))])"/>
        <xsl:variable name="function-list"
            select="$table/descendant::*[contains(@class, ' struct-d/value ')][number(.) = $dword_number]/following-sibling::*[contains(@class, ' struct-d/name ')][not(contains(., 'reserve') or contains(., 'Reserve'))]"/>
       
        <!--This section of code has been removed at the request of Raviteja Reddy Levaka - C34323. -->
        <!--<xsl:choose>
            <xsl:when test="number($dword_number) = 0 and $node-count &gt; 1">
                <xsl:text>+</xsl:text>
            </xsl:when>
            <xsl:when test="number($dword_number) &gt; 0 and $node-count &gt; 0">
                <xsl:text>-</xsl:text>
            </xsl:when>
        </xsl:choose>-->
        <xsl:text>(</xsl:text>
        <xsl:for-each select="$function-list">
            <xsl:choose>
                <xsl:when test="number($dword_number) = 0">                    
                    <xsl:choose>
                        <xsl:when test="contains(ancestor::struct/@structure, 'sub')">
                            <xsl:choose>
                                <xsl:when test="contains(., 'reserved') or contains(., 'Reserved')">
                                    <xsl:call-template name="calculate-reserved-field-name"/>  
                                </xsl:when>
                                <xsl:otherwise>
                                    <xsl:value-of select="normalize-space(.)"/>
                                </xsl:otherwise>
                            </xsl:choose>
                        </xsl:when>
                        <xsl:when test="position() = 1">
                        </xsl:when>
                        <xsl:when test="position() &gt; 1">
                            <xsl:choose>
                                <xsl:when test="contains(., 'reserved') or contains(., 'Reserved')">
                                    <xsl:call-template name="calculate-reserved-field-name"/>  
                                </xsl:when>
                                <xsl:otherwise>                               
                                    <xsl:value-of select="normalize-space(.)"/>
                                </xsl:otherwise>
                            </xsl:choose>
                        </xsl:when>
                    </xsl:choose>     
                </xsl:when>
                <xsl:when test="contains(., 'reserved') or contains(., 'Reserved')">
                    <xsl:call-template name="calculate-reserved-field-name"/>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:value-of select="normalize-space(.)"/>
                </xsl:otherwise>
            </xsl:choose>
            <xsl:if
                test="(not(position() = $node-count) and not($dword_number = 0 and position() = 1)) or (position() = 1 and $dword_number = 0 and ancestor::struct/@structure = 'sub')"
                >,</xsl:if>
        </xsl:for-each>
        <xsl:choose>
            <xsl:when test="number($dword_number) = 0 and $node-count &gt; 1">
                <xsl:text>)</xsl:text>
            </xsl:when>
            <xsl:when test="number($dword_number) &gt; 0 and $node-count &gt; 0">
                <xsl:text>)</xsl:text>
            </xsl:when>
        </xsl:choose>
    </xsl:template>
    
    <xsl:template name="define-load-fields">
        <xsl:param name="dword_number"/>
        <xsl:param name="table"/>
        <xsl:variable name="table_name">
            <xsl:call-template name="process-message-name">
                <xsl:with-param name="name"
                    select="$table/descendant::*[contains(@class, ' topic/title ')]"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="node-count"
            select="count($table/descendant::*[contains(@class, ' struct-d/value ')][number(.) = $dword_number]/following-sibling::*[contains(@class, ' struct-d/name ')][not(contains(., 'reserve') or contains(., 'Reserve'))])"/>
        <xsl:variable name="function-list"
            select="$table/descendant::*[contains(@class, ' struct-d/value ')][number(.) = $dword_number]/following-sibling::*[contains(@class, ' struct-d/name ')][not(contains(., 'reserve') or contains(., 'Reserve'))]"/>
        <xsl:text> (</xsl:text>
        <xsl:for-each select="$function-list">((<xsl:choose>
                    <xsl:when test="contains(., 'reserved') or contains(., 'Reserved')">
                        <xsl:call-template name="calculate-reserved-field-name"/>
                    </xsl:when>
                    <xsl:otherwise><xsl:value-of select="normalize-space(.)"/></xsl:otherwise>
                </xsl:choose>
           <xsl:text disable-output-escaping="yes">)&lt;&lt;</xsl:text>
            <xsl:call-template name="getLSBdefineName"/>)<xsl:if
                test="not(position() = $node-count)">|</xsl:if></xsl:for-each>
        <xsl:text>) </xsl:text>
    </xsl:template>
    
    <!-- GENERIC -->
    
    <xsl:template name="getLSB">
        <xsl:choose>
            <xsl:when
                test="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/double ')]">
                <xsl:value-of
                    select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/double ')]/*[contains(@class, ' struct-d/lsb ')]"
                />
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of
                    select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/single ')]"
                />
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
    <xsl:template name="getLSBdefineName">
        <xsl:variable name="text">
            <xsl:value-of
                select="ancestor::*[contains(@class, ' topic/table ')]/*[contains(@class, ' topic/title ')]"/>
            <xsl:text>_</xsl:text>            
        </xsl:variable>
        <xsl:call-template name="process-message-name">
            <xsl:with-param name="name" select="$text"/>
        </xsl:call-template>
        <xsl:value-of select="upper-case(.)"/><xsl:text>_LSB </xsl:text>
    </xsl:template>
    
    <xsl:template name="getMSB">
        <xsl:choose>
            <xsl:when
                test="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/double ')]">
                <xsl:value-of
                    select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/double ')]/*[contains(@class, ' struct-d/msb ')]"
                />
            </xsl:when>
            <xsl:otherwise>
                <xsl:value-of
                    select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/single ')]"
                />
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
    <xsl:template name="calculate-reserved-field-name">
        <xsl:variable name="dword" select="preceding-sibling::*[contains(@class, ' struct-d/value ')]"/>
        <xsl:variable name="bit_value">
            <xsl:choose>
                <xsl:when
                    test="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/single ')]"
                    ><xsl:value-of
                        select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/single ')]"
                    /></xsl:when>
                <xsl:otherwise>
                    <xsl:value-of
                        select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/double ')]/*[contains(@class, ' struct-d/msb ')]"
                    /><xsl:text>_</xsl:text><xsl:value-of
                        select="preceding-sibling::*[contains(@class, ' struct-d/position ')]/*[contains(@class, ' struct-d/double ')]/*[contains(@class, ' struct-d/lsb ')]"
                    />
                </xsl:otherwise>
            </xsl:choose>
        </xsl:variable>
        <xsl:value-of select="."/>DW<xsl:value-of select="$dword"/>B<xsl:value-of
            select="$bit_value"/>
    </xsl:template>
    
</xsl:stylesheet>
