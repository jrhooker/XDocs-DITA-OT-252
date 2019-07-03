<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:str="http://xsltsl.org/string" xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac"
 exclude-result-prefixes="xs" version="2.0">
 
 <xsl:import href="xsltsl-1.2.1/stdlib.xsl"/>
 <xsl:import href="variables.xsl"/>
 <xsl:import href="header_defines.xsl"/>
 <xsl:import href="header_structs.xsl"/>
 <xsl:import href="includes.xsl"/>
 <xsl:param name="enum_starting_value">
  <xsl:variable name="content" select="/bookmap/topic[1]//enumvalue[1]"/>
  <xsl:choose>
   <xsl:when test="string-length($content) &gt; 2">
    <xsl:value-of select="$content"/>
   </xsl:when>
   <xsl:otherwise>
    <xsl:text>You have failed to define a starting enum value. In the same topic as that which contains your include definition, insert a paragraph (p) element containing a enumvalue element in the form (0xVALUE_HERE).</xsl:text>
   </xsl:otherwise>
  </xsl:choose>
  
  
  
 </xsl:param>
 <xsl:param name="enum_name_param">this_is_the_enum_name_param</xsl:param>
 <xsl:param name="datatype">u32</xsl:param>
 
 
 <xsl:variable name="line_feed">
  <xsl:text>        
</xsl:text>
 </xsl:variable>
 
 <xsl:output media-type="text" indent="no" encoding="UTF-8" omit-xml-declaration="yes"/>
 
 <xsl:strip-space elements="*"/>
 
 <xsl:template match="/">
  <xsl:value-of select="$starting_block"/>
  <xsl:variable name="nodeset">
   <xsl:apply-templates mode="variable"/>
  </xsl:variable>
  <xsl:call-template name="chapter-header-values">
   <xsl:with-param name="content"
    select="/bookmap/topic[1]"/>
  </xsl:call-template>
  <xsl:call-template name="gather-content">
   <xsl:with-param name="nodeset" select="$nodeset"/>
  </xsl:call-template>
 </xsl:template>
 
 <xsl:template match="@*|node()" mode="variable">
  <xsl:copy>
   <xsl:apply-templates select="@*|node()" mode="variable"/>
  </xsl:copy>
 </xsl:template>
  
 <xsl:template name="gather-content">
  <xsl:param name="nodeset"/>
  <xsl:call-template name="enum">
   <xsl:with-param name="tableset"
    select="$nodeset//table[descendant::*[contains(@class, ' struct-d/struct ')]]"/>
  </xsl:call-template>
 <xsl:call-template name="defines">
   <xsl:with-param name="tableset"
    select="$nodeset//table[descendant::*[contains(@class, ' struct-d/struct ')]]"/>
  </xsl:call-template>
 <xsl:call-template name="struct">
   <xsl:with-param name="tableset"
    select="$nodeset//table[descendant::*[contains(@class, ' struct-d/struct ')]]"/>
  </xsl:call-template>
  <xsl:call-template name="defineslsbmsb">
   <xsl:with-param name="tableset"
    select="$nodeset//table[descendant::*[contains(@class, ' struct-d/struct ')]]"/>
  </xsl:call-template>
  <xsl:call-template name="closing-endif">
   <xsl:with-param name="title"
    select="/bookmap/topic[1]"/>
  </xsl:call-template>
 </xsl:template>
 
 <xsl:template name="enum">
  <xsl:param name="tableset"/>
  <xsl:text>
/** 
* @brief Enumerate the opcode for each message
*/
typedef enum {
  </xsl:text>
  <xsl:variable name="count"
   select="count($tableset[descendant::*[contains(@class, ' struct-d/dword ')]]/descendant-or-self::*[contains(@class, ' topic/table ')]/*[contains(@class, ' topic/title ')])"/>
  <xsl:variable name="tables"
   select="$tableset[descendant::*[contains(@class, ' struct-d/dword ')]]/descendant-or-self::*[contains(@class, ' topic/table ')]/*[contains(@class, ' topic/title ')]"/>
  <xsl:for-each select="$tables">
   <xsl:variable name="processed_name">
    <xsl:call-template name="process-dword-name">
     <xsl:with-param name="name" select="."/>
    </xsl:call-template>
   </xsl:variable>
   <xsl:value-of select="upper-case($processed_name)"/>
   <xsl:text>_OPCODE</xsl:text>
   <xsl:if test="position() = 1">
    <xsl:text> = </xsl:text>
    <xsl:value-of select="$enum_starting_value"/>
   </xsl:if>
   <xsl:if test="position() &lt; $count">
    <xsl:text>,</xsl:text>
   </xsl:if>
   <xsl:text>    
  </xsl:text>
  </xsl:for-each>
  <xsl:text>}</xsl:text>
  <xsl:variable name="title">
   <xsl:call-template name="get-file-title">
    <xsl:with-param name="title"
     select="/bookmap/topic[1]"/>
   </xsl:call-template>
  </xsl:variable> 
  <xsl:value-of select="lower-case($title)"/><xsl:text>_opcode_e</xsl:text>
  <xsl:text>;</xsl:text>
 </xsl:template>
 
 <xsl:template name="defineslsbmsb">
  <xsl:param name="tableset"/>
  <xsl:text>
/** 
* @brief Bit definitions
*/
 </xsl:text>
  <xsl:for-each select="$tableset/descendant::*[contains(@class, ' struct-d/name ')][preceding-sibling::*[contains(@class, ' struct-d/value ')][not(contains(. ,':'))]]">
   <xsl:call-template name="define-lsb"/>
   <xsl:call-template name="define-msb"/>
  </xsl:for-each>
 </xsl:template>
 
 <!-- DEFINESLsbMsb -->
 
 <xsl:template name="define-lsb">
  <xsl:text>#define </xsl:text>
  
  <xsl:variable name="text">
   <xsl:value-of
    select="ancestor::*[contains(@class, ' topic/table ')]/*[contains(@class, ' topic/title ')]"/>
   <xsl:text>_</xsl:text>
   <xsl:value-of select="."/>
  </xsl:variable>
  
  <xsl:call-template name="process-dword-name">
   <xsl:with-param name="name" select="$text"/>
  </xsl:call-template>
  <xsl:text>_LSB </xsl:text>
  <xsl:call-template name="getLSB"/>
  <xsl:text>   
  </xsl:text>
 </xsl:template>
 
 <xsl:template name="define-msb">
  <xsl:text>#define </xsl:text>
  
  <xsl:variable name="text">
   <xsl:value-of
    select="ancestor::*[contains(@class, ' topic/table ')]/*[contains(@class, ' topic/title ')]"/>
   <xsl:text>_</xsl:text>
   <xsl:value-of select="."/>
  </xsl:variable>
  
  <xsl:call-template name="process-dword-name">
   <xsl:with-param name="name" select="$text"/>
  </xsl:call-template>
  <xsl:text>_MSB </xsl:text>
  <xsl:call-template name="getMSB"/>
  <xsl:text>
  </xsl:text>
 </xsl:template>
 
 <xsl:template name="process_message_name">
  <xsl:param name="name"/>
  <xsl:variable name="temp">
   <xsl:call-template name="add-underscores">
    <xsl:with-param name="name" select="$name"/>
   </xsl:call-template>
  </xsl:variable>
  <xsl:value-of select="upper-case($temp)"/>
 </xsl:template>
 
 <!-- This template inserts underscores before each upper case letter except the first and then forces the whole word to uppercase -->
 
 <xsl:template name="process-dword-name">
  <xsl:param name="name"/>
  <xsl:choose>
   <xsl:when test="contains($name, 'reserve')">
    <xsl:variable name="temp">
     <xsl:value-of select="$name"/>
     <xsl:text>_R</xsl:text>
     <xsl:value-of
      select="count(ancestor::*[contains(@class, ' struct-d/dword ')]/preceding-sibling::*[contains(@class, ' struct-d/dword ')]/*[contains(@class, ' struct-d/name ')][contains(., 'reserve')])"
     />
    </xsl:variable>
    <xsl:value-of select="upper-case($temp)"/>
   </xsl:when>
   <xsl:otherwise>
    <xsl:variable name="temp">
     <xsl:call-template name="add-underscores">
      <xsl:with-param name="name" select="$name"/>
     </xsl:call-template>
    </xsl:variable>
    <xsl:value-of select="upper-case($temp)"/>
   </xsl:otherwise>
  </xsl:choose>
 </xsl:template>
 
 <!-- Check for capital letters and add underscores in front. -->
 
 <xsl:template name="add-underscores-recurse">
  <xsl:param name="entry" select="''"/>
  <xsl:param name="search.chars">ABCDEFGHIJKLMNOPQRSTUVWXYZ</xsl:param>
  <xsl:choose>
   <xsl:when test="$name.underscore = ''">
    <xsl:value-of select="$entry"/>
   </xsl:when>
   <xsl:when test="string-length($entry) &gt; 0">
    <xsl:variable name="char" select="substring($entry, 1, 1)"/>
    <xsl:if test="contains($search.chars, $char)">
     <!-- Do not hyphen in-between // -->
     <xsl:if test="not($char = '/' and substring($entry,2,1) = '/')">
      <xsl:copy-of select="$name.underscore"/>
     </xsl:if>
    </xsl:if>
    <xsl:value-of select="$char"/>
    <!-- recurse to the next character -->
    <xsl:call-template name="add-underscores-recurse">
     <xsl:with-param name="entry" select="substring($entry, 2)"/>
    </xsl:call-template>
   </xsl:when>
   <xsl:otherwise>
    <xsl:value-of select="$entry"/>
   </xsl:otherwise>
  </xsl:choose>
 </xsl:template>
 
 <xsl:param name="name.underscore">_</xsl:param>
 
 <xsl:template name="add-underscores">
  <xsl:param name="name"/>
  <xsl:variable name="size" select="string-length($name)"/>
  <xsl:variable name="processed_name">
   <xsl:call-template name="add-underscores-recurse">
    <xsl:with-param name="entry" select="substring($name, 2, ($size - 1))"/>
   </xsl:call-template>
  </xsl:variable>
  <xsl:value-of select="substring($name, 1, 1)"/>
  <xsl:value-of select="$processed_name"/>
 </xsl:template>
 
 <xsl:template name="chapter-header-values">
  <xsl:param name="content"/>
  <xsl:variable name="titles" select="$content/descendant::*[contains(@class, ' topic/title ')]"/>
  <xsl:text disable-output-escaping="yes">
#ifndef _</xsl:text><xsl:value-of
 select="translate(upper-case($titles[1]),' ', '_')"
/>_MESSAGES_H_<xsl:text>
#define _</xsl:text><xsl:value-of
 select="translate(upper-case($titles[1]),' ', '_')"/>_MESSAGES_H_
  <xsl:call-template name="process-includes">
   <xsl:with-param name="includesList" select="$content/descendant::*[contains(@class, ' struct-d/includeslist ')]"></xsl:with-param>
  </xsl:call-template>
 </xsl:template>
 
 <xsl:template name="closing-endif">
  <xsl:param name="title"/>
  <xsl:variable name="titles" select="$title/descendant::*[contains(@class, ' topic/title ')]"/>
  <xsl:text disable-output-escaping="yes">
#endif /*</xsl:text><xsl:value-of
 select="translate(upper-case($titles[1]),' ', '_')"/>_MESSAGES_H_<xsl:text>*/
</xsl:text>
 </xsl:template>
 
 <xsl:template name="get-file-title">
  <xsl:param name="title"/>
  <xsl:variable name="titles" select="$title/*[contains(@class, ' topic/title ')]"/>
  <xsl:value-of select="translate($titles[1],' ', '_')"/>
 </xsl:template>
 
 
</xsl:stylesheet>
