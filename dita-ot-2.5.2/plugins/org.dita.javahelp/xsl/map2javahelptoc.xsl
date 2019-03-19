<?xml version="1.0" encoding="UTF-8" ?>
<!--
This file is part of the DITA Open Toolkit project.

Copyright 2004, 2005 IBM Corporation

See the accompanying LICENSE file for applicable license.
-->

<xsl:stylesheet version="2.0" 
                xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<!-- stylesheet imports -->
<xsl:import href="plugin:org.dita.xhtml:xsl/xslhtml/map2TOC.xsl"/>
<xsl:import href="plugin:org.dita.base:xsl/common/output-message.xsl"/>
<xsl:import href="plugin:org.dita.base:xsl/common/dita-utilities.xsl"/>
  
<!-- default "output extension" processing parameter ('.html')-->
<xsl:param name="OUTEXT" select="'.html'"/><!-- "htm" and "html" are valid values -->
<!-- Deprecated since 2.3 -->
<xsl:variable name="msgprefix">DOTX</xsl:variable>
  
  <xsl:param name="ditamap-concat" select="concat('file:///', $BASEDIR2, '/', $ditamap)"/>
  
  <xsl:param name="ditamapISO" select="document($ditamap-concat)"/>
  <!--<xsl:param name="ditamapISO" select="document('file:///C:\Temp\DITA-OT1.8.5\temp\temp20171002144054678\PublishTest.ditamap')"/>-->
  <xsl:param name="pmc_title"><xsl:value-of select="$ditamapISO//pmc_iso[1]/pmc_title"></xsl:value-of></xsl:param> 
  
  

  <xsl:output    method="xml"    omit-xml-declaration="no"    encoding="UTF-8"
    doctype-public="-//Sun Microsystems Inc.//DTD JavaHelp TOC Version 2.0//EN"
    doctype-system="http://java.sun.com/products/javahelp/toc_2_0.dtd"    indent="yes"/>

<xsl:template match="*[contains(@class,' map/map ')]" mode="toctop">
  <toc version="2.0">
    <tocitem text="{translate($pmc_title, '&#xA;', '')}">
        <xsl:apply-templates select="*[contains(@class,' map/topicref ')]"/>
  </tocitem>
    </toc>
</xsl:template>

<xsl:template match="*[contains(@class,' map/topicref ')]" mode="tocentry">
  <xsl:param name="infile"/>
  <xsl:param name="outroot"/>
  <xsl:param name="outfile"/>
  <xsl:param name="nodeID"/>
  <xsl:param name="isFirst"/>
  <xsl:param name="subtopicNodes"/>
  <xsl:param name="title"/>
  <xsl:choose>
  <xsl:when test="(@toc and translate(@toc, 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')='no')
            or (@processing-role='resource-only')">
    <!-- <xsl:variable name="results">  -->
    <!-- Process children nodes. -->
<!--     <xsl:apply-templates select="$subtopicNodes"/> -->
    <xsl:apply-templates select="./*[contains(@class, ' map/topicref ')]"/>
    <!-- </xsl:variable>  -->
    <!-- <xsl:text/>  -->
  </xsl:when>
  <xsl:when test="string-length($title) &gt; 1">
    <tocitem text="{$title}">
      <xsl:if test="$outroot and $outroot!=''">
        <xsl:attribute name="target">
          <xsl:value-of select="translate($outroot, '\/.', '___')"/>
        </xsl:attribute>
      </xsl:if>
      <xsl:if test="@copy-to">
        <xsl:variable name="copyToWithoutExtension">
          <xsl:call-template name="replace-extension">
           <xsl:with-param name="filename" select="@copy-to"/>
           <xsl:with-param name="extension" select="''"/>
          </xsl:call-template>
        </xsl:variable>
        <xsl:attribute name="target">
          <xsl:value-of select="translate($copyToWithoutExtension, '\/.', '___')"/>     
        </xsl:attribute>
      </xsl:if>

      <xsl:apply-templates select="$subtopicNodes"/>
    </tocitem>
  </xsl:when>
  <xsl:otherwise>
    <xsl:apply-templates select="$subtopicNodes"/>
  </xsl:otherwise>
  </xsl:choose>
</xsl:template>

<!-- do nothing when meeting with reltable -->
<xsl:template match="*[contains(@class,' map/reltable ')]"/>

</xsl:stylesheet>
