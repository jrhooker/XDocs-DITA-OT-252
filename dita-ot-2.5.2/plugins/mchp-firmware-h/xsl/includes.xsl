<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac" version="2.0">
    
<xsl:template name="process-includes">
    <xsl:param name="includesList"></xsl:param>
    <xsl:message>processing includes</xsl:message>
    <xsl:for-each select="$includesList/*[contains(@class, ' struct-d/include ')]">
<xsl:text>/*</xsl:text>
<xsl:apply-templates select="*[contains(@class, ' struct-d/description ')]" mode="include"/>
<xsl:text>
*/
</xsl:text>
<xsl:text disable-output-escaping="yes">#include &lt;</xsl:text><xsl:value-of select="*[contains(@class, ' struct-d/name ')]"></xsl:value-of><xsl:text disable-output-escaping="yes">&gt;
</xsl:text>
    </xsl:for-each>
</xsl:template>   
    
    
    <xsl:template match="*" mode="include">
        <xsl:apply-templates mode="include"/>
    </xsl:template>
    
    <xsl:template match="*[contains(@class, ' topic/p ')]" mode="include">
<xsl:text>
* </xsl:text>
        <xsl:value-of select="normalize-space(.)"/>
    </xsl:template>
    
    <xsl:template match="*[contains(@class, ' topic/li ')]" mode="include">
        <xsl:choose>
            <xsl:when test="not(child::*[contains(@class, ' topic/p ')])">
<xsl:text>
*- </xsl:text>
                <xsl:value-of select="normalize-space(.)"/>
            </xsl:when>
            <xsl:otherwise>
                <xsl:apply-templates mode="include"/>
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
    <xsl:template
        match="*[contains(@class, ' topic/p ')][parent::*[contains(@class, ' topic/li ')]]"
        mode="include">
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
        mode="include">
<xsl:text>
* </xsl:text>
        <xsl:number/>
        <xsl:text>. </xsl:text>
        <xsl:value-of select="normalize-space(.)"/>
    </xsl:template>
    
    <xsl:template match="*[parent::*[contains(@class, ' topic/p ')]]" mode="include">
        <xsl:value-of select="."/>
    </xsl:template>
    

</xsl:stylesheet>