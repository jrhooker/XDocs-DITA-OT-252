<?xml version='1.0' encoding='utf-8'?>
<xsl:stylesheet exclude-result-prefixes="xs ditaarch opentopic e dita-ot opentopic-func" version="2.0" xmlns:dita-ot="http://dita-ot.sourceforge.net/ns/201007/dita-ot" xmlns:ditaarch="http://dita.oasis-open.org/architecture/2005/" xmlns:e="mchp-firmware" xmlns:opentopic="http://www.idiominc.com/opentopic" xmlns:opentopic-func="http://www.idiominc.com/opentopic/exsl/function" xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:attribute-set name="region-body.odd">
    <xsl:attribute name="column-count">1</xsl:attribute>
    <xsl:attribute name="column-gap">12pt</xsl:attribute>
  </xsl:attribute-set>
  <xsl:attribute-set name="region-body.even">
    <xsl:attribute name="column-count">1</xsl:attribute>
    <xsl:attribute name="column-gap">12pt</xsl:attribute>
  </xsl:attribute-set>
  <xsl:attribute-set name="region-bodyfrontmatter.odd">
    <xsl:attribute name="column-count">1</xsl:attribute>
  </xsl:attribute-set>
  <xsl:attribute-set name="region-bodyfrontmatter.even">
    <xsl:attribute name="column-count">1</xsl:attribute>
  </xsl:attribute-set>
  <xsl:attribute-set name="region-bodyindex.odd">
    <xsl:attribute name="column-count">2</xsl:attribute>
  </xsl:attribute-set>
  <xsl:attribute-set name="region-bodyindex.even">
    <xsl:attribute name="column-count">2</xsl:attribute>
  </xsl:attribute-set>
</xsl:stylesheet>
