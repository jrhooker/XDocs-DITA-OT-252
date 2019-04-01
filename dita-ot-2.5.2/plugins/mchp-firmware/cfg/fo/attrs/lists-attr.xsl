<?xml version='1.0' encoding='utf-8'?>
<xsl:stylesheet exclude-result-prefixes="xs ditaarch opentopic e dita-ot opentopic-func" version="2.0" xmlns:dita-ot="http://dita-ot.sourceforge.net/ns/201007/dita-ot" xmlns:ditaarch="http://dita.oasis-open.org/architecture/2005/" xmlns:e="mchp-firmware" xmlns:opentopic="http://www.idiominc.com/opentopic" xmlns:opentopic-func="http://www.idiominc.com/opentopic/exsl/function" xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <!--list-->
  <xsl:attribute-set name="ol">
    <xsl:attribute name="provisional-distance-between-starts">
      <xsl:call-template name="e:list-label-length" />
      <xsl:text>em * 0.7</xsl:text>
    </xsl:attribute>
  </xsl:attribute-set>
  <xsl:template name="e:list-label-length">
    <xsl:variable as="xs:integer*" name="labels">
      <xsl:variable name="depth" select="count(ancestor-or-self::*[contains(@class, ' topic/ol ')])" />
      <xsl:variable as="xs:string" name="format">
        <xsl:call-template name="getVariable">
          <xsl:with-param name="id" select="concat('Ordered List Format ', $depth)" />
        </xsl:call-template>
      </xsl:variable>
      <xsl:for-each select="*[contains(@class, ' topic/li ')]">
        <xsl:variable name="s">
          <xsl:call-template name="getVariable">
            <xsl:with-param name="id" select="concat('Ordered List Number ', $depth)" />
            <xsl:with-param as="element()*" name="params">
              <number>
                <xsl:number format="{$format}" />
              </number>
            </xsl:with-param>
          </xsl:call-template>
        </xsl:variable>
        <xsl:sequence select="string-length(normalize-space($s))" />
      </xsl:for-each>
    </xsl:variable>
    <xsl:sequence select="max($labels)" />
  </xsl:template>
</xsl:stylesheet>
