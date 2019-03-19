<?xml version="1.0" encoding="UTF-8"?>
<!-- <!DOCTYPE xsl:stylesheet SYSTEM "stylesheet.dtd"> -->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:ditaarch="http://dita.oasis-open.org/architecture/2005/" xmlns:dita-ot="http://dita-ot.sourceforge.net/ns/201007/dita-ot" exclude-result-prefixes="dita-ot">
    <!-- remove dita-ot attributes -->
	<xsl:template match="@dita-ot:*" />
	
	<!-- remove dita-ot elements -->
	<xsl:template match="dita-ot:*" />
	
	<!--copy everyting that doesn't match elsewhere 
    <xsl:template match="@*|node()">
        <xsl:copy>
            <xsl:apply-templates select="@*|node()"/>
        </xsl:copy>
    </xsl:template>
	<xsl:template match="*"> -->
	<!-- Copy elements -->
	<xsl:template match="*" priority="-1">
	   <xsl:element name="{name()}">
		  <xsl:apply-templates select="node()|@*"/>
	   </xsl:element>
	</xsl:template>

	<!-- Copy all other nodes -->
	<xsl:template match="node()|@*" priority="-2">
	   <xsl:copy />      
	</xsl:template>
</xsl:stylesheet>