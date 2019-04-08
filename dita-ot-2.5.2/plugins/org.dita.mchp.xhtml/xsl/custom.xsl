<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    exclude-result-prefixes="xs"
    version="2.0">    
    
    <xsl:import href="dita2xhtml.xsl"/>
    <!--<xsl:import href="common/common.xsl"/>-->
    
    <xsl:param name="SHOWCOMMENTS">NO</xsl:param><!-- values: yes, no (or any not "yes") -->
    <xsl:param name="SHOWCOMMENTS-NUM" select="0"/><!-- values: yes, no (or any not "yes") -->
    
</xsl:stylesheet>