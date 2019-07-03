<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:str="http://xsltsl.org/string" xmlns:xs="http://www.w3.org/2001/XMLSchema"
 xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac" xmlns:math="http://exslt.org/math"
 xmlns:f="http://pmcs.com/functions" exclude-result-prefixes="xs" version="2.0">

 <xsl:import href="xsltsl-1.2.1/stdlib.xsl"/>
 <xsl:import href="hexConversions.xsl"/>
 <xsl:import href="conversionFunctions.xsl"/>
 <xsl:param name="audience">External</xsl:param>
 <xsl:param name="datatype">u32</xsl:param>
 <xsl:param name="production-path">/Projects/BelmarCARREG/output/</xsl:param>
 <xsl:param name="base">
  <xsl:variable name="temp">
   <xsl:call-template name="substring-before-last">
    <xsl:with-param name="string1" select="document-uri(.)"/>
    <xsl:with-param name="string2" select="'/'"/>
   </xsl:call-template>
  </xsl:variable>
  <xsl:value-of select="concat($temp, '/')"/>
 </xsl:param>
 <xsl:param name="internal" select="0"/>

 <xsl:output media-type="xml" indent="yes" encoding="UTF-8" omit-xml-declaration="yes"/>

 <xsl:strip-space elements="*"/>

 <xsl:template match="//table[@otherprops = 'node_ids']">
  <xsl:result-document href="{$production-path}IDT_reg.xml" method="xml">
   <xsl:element name="carnamespace">
    <xsl:for-each select="descendant::row[entry[1][descendant::xref]]">
     <xsl:element name="device">
      <xsl:attribute name="type">
       <xsl:value-of select="normalize-space(translate(entry[1], ' ', ''))"/>
      </xsl:attribute>
      <xsl:element name="node">
       <xsl:attribute name="name">
        <xsl:value-of select="normalize-space(translate(entry[1], ' ', ''))"/>
       </xsl:attribute>
       <xsl:attribute name="nodeid">
        <xsl:value-of select="concat('0x' , normalize-space(translate(entry[4], ' ', '')))"/>
       </xsl:attribute>
       <xsl:attribute name="aliases"/>
      </xsl:element>
      <xsl:variable name="file">
       <xsl:value-of select="entry[1]//xref/@href"/>
      </xsl:variable>

      <xsl:variable name="current_device" select="document($file)"/>
      <xsl:for-each select="$current_device//table[descendant::csrreg-reference]">
       <xsl:call-template name="generate-registers"/>
      </xsl:for-each>
     </xsl:element>
    </xsl:for-each>
   </xsl:element>
  </xsl:result-document>
 </xsl:template>

 <xsl:template name="generate-registers">

  <xsl:param name="address-location" tunnel="yes"/>
  <xsl:param name="prefix" tunnel="yes"/>
  <xsl:param name="address-offset" tunnel="yes"/>

  <xsl:variable name="reg-reference-set" select="descendant::csrreg-reference"/>
  <xsl:comment>Generated from the <xsl:value-of select="title"/> Table</xsl:comment>
  <xsl:text>   
  </xsl:text>

  <xsl:choose>
   <xsl:when test="$internal = 0">
    <xsl:for-each select="$reg-reference-set[not(contains(@audience, 'PMCInternal'))]">
     <xsl:choose>
      <xsl:when test="descendant::csrreg-prefix">
       <xsl:variable name="address-location"
        select="normalize-space(csrreg-address/csrreg-location)"/>
       <xsl:variable name="prefix" select="normalize-space(csrreg-name/csrreg-prefix/xref/text())"/>
       <xsl:variable name="address-offset" select="normalize-space(csrreg-address/csrreg-offset)"/>
       <xsl:variable name="id">
        <xsl:call-template name="substring-after-last">
         <xsl:with-param name="string" select="csrreg-name/csrreg-prefix/xref/@href"/>
         <xsl:with-param name="delimiter" select="'/'"/>
        </xsl:call-template>
       </xsl:variable>
       
 <!-- Determine if the next resource is in the same file or a different file and generate the file variable accordingly -->
       <xsl:variable name="file">
        <xsl:choose>
         <xsl:when test="contains(substring-before(csrreg-name/csrreg-prefix/xref/@href, '#'), '.xml')">
          <xsl:value-of select="$base"/>
          <xsl:value-of select="substring-before(csrreg-name/csrreg-prefix/xref/@href, '#')"/>
         </xsl:when>
         <xsl:otherwise>
          <xsl:value-of select="base-uri()"/>
         </xsl:otherwise>
        </xsl:choose>
       </xsl:variable>
       
       <xsl:variable name="current_nodeset" select="document($file)//*[@id = $id]//registers"/>
    
       <xsl:for-each select="document($file)//*[@id = $id]">
        <xsl:call-template name="generate-registers">
         <xsl:with-param name="address-location" select="$address-location" tunnel="yes"/>
         <xsl:with-param name="prefix" select="$prefix" tunnel="yes"/>
         <xsl:with-param name="address-offset" select="$address-offset" tunnel="yes"/>
        </xsl:call-template>
       </xsl:for-each>

      </xsl:when>
      <xsl:when
       test="csrreg-name/csrreg-instances and count(csrreg-name/csrreg-mnemonic/xref) &gt; 1">
       <xsl:call-template name="interate-mnemonics"/>
      </xsl:when>
      <xsl:when test="csrreg-name/csrreg-instances">
       <xsl:call-template name="interate-instances">
        <xsl:with-param name="current_location">
         <xsl:call-template name="calculate-combined-offset">
          <xsl:with-param name="offset1" select="$address-location"/>
          <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-location)"/>
         </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="current_offset">
         <xsl:call-template name="calculate-combined-offset">
          <xsl:with-param name="offset1" select="$address-offset"/>
          <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-offset)"/>
         </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="current_register_set">
         <xsl:value-of select="csrreg-name/csrreg-mnemonic/xref/@href"/>
        </xsl:with-param>
        <xsl:with-param name="instance_value_start">
         <xsl:value-of select="normalize-space(csrreg-name/csrreg-instances/instance-start)"/>
        </xsl:with-param>
        <xsl:with-param name="instance_value_stop">
         <xsl:value-of select="normalize-space(csrreg-name/csrreg-instances/instance-stop)"/>
        </xsl:with-param>
        <!-- I will preprocess names so that the process-register template does not need to know which instance it is processing -->
        <xsl:with-param name="current_name_set">
         <xsl:value-of select="csrreg-name/csrreg-mnemonic/xref/text()"/>
        </xsl:with-param>
       </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
       <xsl:call-template name="process-register">
        <xsl:with-param name="current_location">
         <xsl:call-template name="calculate-combined-offset">
          <xsl:with-param name="offset1" select="$address-location"/>
          <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-location)"/>
         </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="current_offset">
         <xsl:variable name="temp">
          <xsl:call-template name="calculate-combined-offset">
           <xsl:with-param name="offset1" select="$address-offset"/>
           <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-offset)"/>
          </xsl:call-template>
         </xsl:variable>
         <xsl:message>offset1: <xsl:value-of select="$address-offset"/></xsl:message>
         <xsl:message>offset2: <xsl:value-of select="normalize-space(csrreg-address/csrreg-offset)"
          /></xsl:message>
         <xsl:message>total: <xsl:value-of select="$temp"/></xsl:message>
         <xsl:choose>
          <xsl:when test="$temp = ''">
           <xsl:value-of select="concat('0000', $temp)"/>
           <xsl:message>total2: <xsl:value-of select="concat('0000', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:when test="string-length($temp) = 1">
           <xsl:value-of select="concat('000', $temp)"/>
           <xsl:message>total3: <xsl:value-of select="concat('000', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:when test="string-length($temp) = 2">
           <xsl:value-of select="concat('00', $temp)"/>
           <xsl:message>total4: <xsl:value-of select="concat('00', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:when test="string-length($temp) = 3">
           <xsl:value-of select="concat('0', $temp)"/>
           <xsl:message>total5: <xsl:value-of select="concat('0', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:otherwise>
           <xsl:value-of select="$temp"/>
           <xsl:message>total6: <xsl:value-of select="$temp"/></xsl:message>
          </xsl:otherwise>
         </xsl:choose>
        </xsl:with-param>
        <xsl:with-param name="current_register">
         <xsl:value-of select="csrreg-name/csrreg-mnemonic/xref/@href"/>
        </xsl:with-param>
        <!-- I will preprocess names so that the process-register template does not need to know which instance it is processing -->
        <xsl:with-param name="current_name">
         <xsl:call-template name="process-name">
          <xsl:with-param name="name" select="csrreg-name/csrreg-mnemonic/xref/text()"/>
         </xsl:call-template>
        </xsl:with-param>
       </xsl:call-template>
      </xsl:otherwise>
     </xsl:choose>
    </xsl:for-each>
   </xsl:when>
   <xsl:otherwise>
    <xsl:for-each select="$reg-reference-set">
     <xsl:choose>
      <xsl:when test="descendant::csrreg-prefix">
       <xsl:variable name="address-location"
        select="normalize-space(csrreg-address/csrreg-location)"/>
       <xsl:variable name="prefix" select="normalize-space(csrreg-name/csrreg-prefix/xref/text())"/>
       <xsl:variable name="address-offset" select="normalize-space(csrreg-address/csrreg-offset)"/>
       <xsl:variable name="id">
        <xsl:call-template name="substring-after-last">
         <xsl:with-param name="string" select="csrreg-name/csrreg-prefix/xref/@href"/>
         <xsl:with-param name="delimiter" select="'/'"/>
        </xsl:call-template>
       </xsl:variable>
       <xsl:variable name="file">
        <xsl:value-of select="substring-before(csrreg-name/csrreg-prefix/xref/@href, '#')"/>
       </xsl:variable>
       <!-- Determine is the device map table in is the same topic as the address table or a different topic -->

       <!-- If it contains a period there must be a filename in there -->

       <xsl:for-each select="//*[@id = $id]">
        <xsl:call-template name="generate-registers">
         <xsl:with-param name="address-location" select="$address-location" tunnel="yes"/>
         <xsl:with-param name="prefix" select="$prefix" tunnel="yes"/>
         <xsl:with-param name="address-offset" select="$address-offset" tunnel="yes"/>
        </xsl:call-template>
       </xsl:for-each>

       <!--
       <xsl:for-each select="document($file)//*[@id = $id]">
        <xsl:call-template name="generate-registers">
         <xsl:with-param name="address-location" select="$address-location" tunnel="yes"/>
         <xsl:with-param name="prefix" select="$prefix" tunnel="yes"/>
         <xsl:with-param name="address-offset" select="$address-offset" tunnel="yes"/>
        </xsl:call-template>
       </xsl:for-each>
     -->
      </xsl:when>
      <xsl:when
       test="csrreg-name/csrreg-instances and count(csrreg-name/csrreg-mnemonic/xref) &gt; 1">
       <xsl:call-template name="interate-mnemonics"/>
      </xsl:when>
      <xsl:when test="csrreg-name/csrreg-instances">
       <xsl:call-template name="interate-instances">
        <xsl:with-param name="current_location">
         <xsl:call-template name="calculate-combined-offset">
          <xsl:with-param name="offset1" select="$address-location"/>
          <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-location)"/>
         </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="current_offset">
         <xsl:call-template name="calculate-combined-offset">
          <xsl:with-param name="offset1" select="$address-offset"/>
          <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-offset)"/>
         </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="current_register_set">
         <xsl:value-of select="csrreg-name/csrreg-mnemonic/xref/@href"/>
        </xsl:with-param>
        <xsl:with-param name="instance_value_start">
         <xsl:value-of select="normalize-space(csrreg-name/csrreg-instances/instance-start)"/>
        </xsl:with-param>
        <xsl:with-param name="instance_value_stop">
         <xsl:value-of select="normalize-space(csrreg-name/csrreg-instances/instance-stop)"/>
        </xsl:with-param>
        <!-- I will preprocess names so that the process-register template does not need to know which instance it is processing -->
        <xsl:with-param name="current_name_set">
         <xsl:value-of select="csrreg-name/csrreg-mnemonic/xref/text()"/>
        </xsl:with-param>
       </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
       <xsl:call-template name="process-register">
        <xsl:with-param name="current_location">
         <xsl:call-template name="calculate-combined-offset">
          <xsl:with-param name="offset1" select="$address-location"/>
          <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-location)"/>
         </xsl:call-template>
        </xsl:with-param>
        <xsl:with-param name="current_offset">
         <xsl:variable name="temp">
          <xsl:call-template name="calculate-combined-offset">
           <xsl:with-param name="offset1" select="$address-offset"/>
           <xsl:with-param name="offset2" select="normalize-space(csrreg-address/csrreg-offset)"/>
          </xsl:call-template>
         </xsl:variable>
         <xsl:message>offset1: <xsl:value-of select="$address-offset"/></xsl:message>
         <xsl:message>offset2: <xsl:value-of select="normalize-space(csrreg-address/csrreg-offset)"
          /></xsl:message>
         <xsl:message>total: <xsl:value-of select="$temp"/></xsl:message>
         <xsl:choose>
          <xsl:when test="$temp = ''">
           <xsl:value-of select="concat('0000', $temp)"/>
           <xsl:message>total2: <xsl:value-of select="concat('0000', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:when test="string-length($temp) = 1">
           <xsl:value-of select="concat('000', $temp)"/>
           <xsl:message>total3: <xsl:value-of select="concat('000', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:when test="string-length($temp) = 2">
           <xsl:value-of select="concat('00', $temp)"/>
           <xsl:message>total4: <xsl:value-of select="concat('00', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:when test="string-length($temp) = 3">
           <xsl:value-of select="concat('0', $temp)"/>
           <xsl:message>total5: <xsl:value-of select="concat('0', $temp)"/></xsl:message>
          </xsl:when>
          <xsl:otherwise>
           <xsl:value-of select="$temp"/>
           <xsl:message>total6: <xsl:value-of select="$temp"/></xsl:message>
          </xsl:otherwise>
         </xsl:choose>
        </xsl:with-param>
        <xsl:with-param name="current_register">
         <xsl:value-of select="csrreg-name/csrreg-mnemonic/xref/@href"/>
        </xsl:with-param>
        <!-- I will preprocess names so that the process-register template does not need to know which instance it is processing -->
        <xsl:with-param name="current_name">
         <xsl:call-template name="process-name">
          <xsl:with-param name="name" select="csrreg-name/csrreg-mnemonic/xref/text()"/>
         </xsl:call-template>
        </xsl:with-param>
       </xsl:call-template>
      </xsl:otherwise>
     </xsl:choose>
    </xsl:for-each>
   </xsl:otherwise>
  </xsl:choose>

 </xsl:template>

 <xsl:template name="interate-mnemonics">
  <xsl:param name="interation" select="normalize-space(csrreg-name/csrreg-instances/instance-start)"/>
  <xsl:param name="offset"/>
  <xsl:param name="current_register_count" select="1"/>

  <xsl:param name="address-location" tunnel="yes"/>
  <xsl:param name="prefix" tunnel="yes"/>
  <xsl:param name="address-offset" tunnel="yes"/>

  <xsl:variable name="location"/>

  <xsl:variable name="offset">
   <xsl:choose>
    <xsl:when test="string-length($address-offset) &gt; 0">
     <xsl:call-template name="calculate-combined-offset">
      <xsl:with-param name="offset1">
       <xsl:value-of select="$address-offset"/>
      </xsl:with-param>
      <xsl:with-param name="offset2">
       <xsl:value-of select="normalize-space(csrreg-address/csrreg-offset)"/>
      </xsl:with-param>
     </xsl:call-template>
    </xsl:when>
    <xsl:when test="string-length($offset) &gt; 1">
     <xsl:value-of select="$offset"/>
    </xsl:when>
    <xsl:otherwise>
     <xsl:value-of select="normalize-space(csrreg-address/csrreg-offset)"/>
    </xsl:otherwise>
   </xsl:choose>
  </xsl:variable>

  <xsl:variable name="corrected_location">
   <xsl:choose>
    <xsl:when test="string-length($address-location) &gt; 1">
     <xsl:call-template name="calculate-combined-offset">
      <xsl:with-param name="offset1" select="$address-location"/>
      <xsl:with-param name="offset2" select="csrreg-address/csrreg-location"/>
     </xsl:call-template>
    </xsl:when>
    <xsl:otherwise>
     <xsl:value-of select="csrreg-address/csrreg-location"/>
    </xsl:otherwise>
   </xsl:choose>
  </xsl:variable>

  <!-- This is just the current location with the 0x stripped to make it easier to use for math and substring operations -->

  <xsl:variable name="stripped_location" select="substring-after($corrected_location, '0x')"/>

  <!-- process the register, then decide what to do next -->
  <xsl:if
   test="number($interation) &lt;= number(normalize-space(csrreg-name/csrreg-instances/instance-stop))">
   <xsl:call-template name="process-register">
    <xsl:with-param name="current_location">
     <xsl:value-of select="$corrected_location"/>
    </xsl:with-param>
    <xsl:with-param name="current_offset">
     <xsl:value-of select="$offset"/>
    </xsl:with-param>
    <xsl:with-param name="current_register">
     <xsl:value-of select="csrreg-name/csrreg-mnemonic[$current_register_count]/xref/@href"/>
    </xsl:with-param>
    <!-- I will preprocess names so that the process-register template does not need to know which instance it is processing -->
    <xsl:with-param name="current_name">
     <xsl:call-template name="process-name">
      <xsl:with-param name="name"
       select="csrreg-name/csrreg-mnemonic[$current_register_count]/xref/text()"/>
      <xsl:with-param name="instance" select="number($interation)"/>
     </xsl:call-template>
    </xsl:with-param>
   </xsl:call-template>
  </xsl:if>
  <xsl:choose>
   <xsl:when test="$current_register_count &lt; count(csrreg-name/csrreg-mnemonic)">
    <xsl:call-template name="interate-mnemonics">
     <xsl:with-param name="address-location" tunnel="yes"/>
     <xsl:with-param name="address-offset" tunnel="yes"/>
     <xsl:with-param name="current_register_count" select="$current_register_count + 1"/>
     <xsl:with-param name="offset">
      <xsl:call-template name="calculate-offset">
       <xsl:with-param name="offset" select="$offset"/>
       <xsl:with-param name="location" select="$corrected_location"/>
      </xsl:call-template>
     </xsl:with-param>
     <xsl:with-param name="interation" select="$interation"/>
    </xsl:call-template>
   </xsl:when>
   <xsl:when
    test="number($interation) &lt;= number(normalize-space(csrreg-name/csrreg-instances/instance-stop))">
    <xsl:call-template name="interate-mnemonics">
     <xsl:with-param name="address-location" tunnel="yes"/>
     <xsl:with-param name="address-offset" tunnel="yes"/>
     <xsl:with-param name="current_register_count" select="1"/>
     <xsl:with-param name="offset">
      <xsl:call-template name="calculate-offset">
       <xsl:with-param name="offset" select="$offset"/>
       <xsl:with-param name="location" select="$corrected_location"/>
      </xsl:call-template>
     </xsl:with-param>
     <xsl:with-param name="interation" select="number($interation) + 1"/>
    </xsl:call-template>
   </xsl:when>
  </xsl:choose>
 </xsl:template>

 <xsl:template name="calculate-combined-offset">
  <!-- The Address Map value -->
  <xsl:param name="offset1"/>
  <!-- The XXXX value -->
  <xsl:param name="offset2"/>
  <xsl:param name="base" select="16"/>

  <xsl:variable name="offset1a">
   <xsl:choose>
    <xsl:when test="$offset1 = ''">0</xsl:when>
    <xsl:when test="contains($offset1, '0x')">
     <xsl:value-of select="substring-after($offset1, '0x')"/>
    </xsl:when>
    <xsl:otherwise>
     <xsl:value-of select="$offset1"/>
    </xsl:otherwise>
   </xsl:choose>
  </xsl:variable>

  <xsl:variable name="offset2a">
   <xsl:choose>
    <xsl:when test="$offset2 = ''">0</xsl:when>
    <xsl:when test="contains($offset2, '0x')">
     <xsl:value-of select="substring-after($offset2, '0x')"/>
    </xsl:when>
    <xsl:otherwise>
     <xsl:value-of select="$offset2"/>
    </xsl:otherwise>
   </xsl:choose>
  </xsl:variable>

  <xsl:variable name="offset1_in_decimal">
   <xsl:value-of select="f:hexToDec($offset1a)"/>
  </xsl:variable>

  <xsl:variable name="offset2_in_decimal">
   <xsl:value-of select="f:hexToDec($offset2a)"/>
  </xsl:variable>

  <xsl:variable name="new_offset_in_decimal"
   select="number($offset1_in_decimal) + number($offset2_in_decimal)"/>

  <xsl:variable name="new_offset_in_hex">
   <xsl:value-of select="f:decimalToHex($new_offset_in_decimal)"/>
  </xsl:variable>


  <!-- if the value was a location, return it in 0xX format. otherwise, return stripped -->
  <xsl:choose>
   <xsl:when test="contains($offset2, '0x')">
    <xsl:value-of select="concat('0x', $new_offset_in_hex)"/>
   </xsl:when>
   <xsl:otherwise>
    <xsl:value-of select="$new_offset_in_hex"/>
   </xsl:otherwise>
  </xsl:choose>


 </xsl:template>

 <xsl:template name="calculate-offset">
  <!-- The 0xX value -->
  <xsl:param name="location"/>
  <!-- The XXXX value -->
  <xsl:param name="offset"/>
  <xsl:param name="base" select="16"/>

  <xsl:variable name="hex_value" select="concat(substring-after($location, '0x'), $offset)"/>

  <xsl:variable name="offset_in_decimal">
   <xsl:value-of select="f:hexToDec($hex_value)"/>
  </xsl:variable>

  <xsl:variable name="new_offset_in_decimal" select="number($offset_in_decimal) + 4"/>

  <xsl:variable name="new_offset_in_hex">
   <xsl:value-of select="f:decimalToHex($new_offset_in_decimal)"/>
  </xsl:variable>

  <xsl:variable name="stripped_location" select="substring-after($location, '0x')"/>

  <xsl:value-of select="substring-after(string($new_offset_in_hex), $stripped_location)"/>
 </xsl:template>

 <xsl:template name="interate-instances">
  <xsl:param name="current_location"/>
  <xsl:param name="current_name_set"/>
  <xsl:param name="current_offset"/>
  <xsl:param name="current_register_set"/>
  <xsl:param name="instance_value_start"/>
  <xsl:param name="instance_value_stop"/>
  <xsl:param name="register_count" select="1"/>

  <xsl:variable name="reg_in_set" select="count($current_register_set)"/>

  <!-- process the register, then decide what to do next -->

  <xsl:call-template name="process-register">
   <xsl:with-param name="current_location">
    <xsl:value-of select="$current_location"/>
   </xsl:with-param>
   <xsl:with-param name="current_offset">
    <xsl:value-of select="$current_offset"/>
   </xsl:with-param>
   <xsl:with-param name="current_register">
    <xsl:value-of select="$current_register_set[$register_count]"/>
   </xsl:with-param>
   <!-- I will preprocess names so that the process-register template does not need to know which instance it is processing -->
   <xsl:with-param name="current_name">
    <xsl:call-template name="process-name">
     <xsl:with-param name="name" select="$current_name_set[$register_count]"/>
     <xsl:with-param name="instance" select="$instance_value_start"/>
    </xsl:call-template>
   </xsl:with-param>
  </xsl:call-template>

  <xsl:choose>
   <xsl:when
    test="number($instance_value_start) = number($instance_value_stop) and $register_count = $reg_in_set">
    <!-- All done -->
   </xsl:when>
   <xsl:when test="$register_count &lt; $reg_in_set">
    <xsl:message> 1 Current Offset: <xsl:value-of select="$current_offset"/> 1 Current Location:
      <xsl:value-of select="$current_location"/>
    </xsl:message>
    <xsl:call-template name="interate-instances">
     <xsl:with-param name="current_location" select="$current_location"/>
     <xsl:with-param name="current_name_set" select="$current_name_set"/>
     <xsl:with-param name="current_offset">
      <xsl:call-template name="calculate-offset">
       <xsl:with-param name="offset" select="$current_offset"/>
       <xsl:with-param name="location" select="$current_location"/>
      </xsl:call-template>
     </xsl:with-param>
     <xsl:with-param name="current_register_set" select="$current_register_set"/>
     <xsl:with-param name="instance_value_start" select="$instance_value_start"/>
     <xsl:with-param name="instance_value_stop" select="$instance_value_stop"/>
     <xsl:with-param name="register_count" select="$register_count + 1"/>
    </xsl:call-template>
   </xsl:when>
   <xsl:when test="number($instance_value_start) &lt; number($instance_value_stop)">
    <xsl:message> 2 Current Offset: <xsl:value-of select="$register_count"/> 2 Current Location:
      <xsl:value-of select="$reg_in_set"/>
    </xsl:message>
    <xsl:call-template name="interate-instances">
     <xsl:with-param name="current_location" select="$current_location"/>
     <xsl:with-param name="current_name_set" select="$current_name_set"/>
     <xsl:with-param name="current_offset">
      <xsl:call-template name="calculate-offset">
       <xsl:with-param name="offset" select="$current_offset"/>
       <xsl:with-param name="location" select="$current_location"/>
      </xsl:call-template>
     </xsl:with-param>
     <xsl:with-param name="current_register_set" select="$current_register_set"/>
     <xsl:with-param name="instance_value_start" select="$instance_value_start + 1"/>
     <xsl:with-param name="instance_value_stop" select="$instance_value_stop"/>
    </xsl:call-template>
   </xsl:when>
  </xsl:choose>
 </xsl:template>

 <xsl:template name="process-name">
  <xsl:param name="prefix" tunnel="yes"/>
  <xsl:param name="name"/>
  <xsl:param name="instance" select="100000000000000000000"/>

  <xsl:variable name="pre-prefix">
   <xsl:choose>
    <xsl:when test="$instance &gt; 10000000000000000000">
     <xsl:choose>
      <!-- When there's no real instance value passed, and there are brackets in the  -->
      <xsl:when test="contains($name, '[')">
       <xsl:variable name="front_half">
        <xsl:value-of select="substring-before($name, '[')"/>
       </xsl:variable>
       <xsl:variable name="back_half">
        <xsl:value-of select="substring-after($name, ']')"/>
       </xsl:variable>
       <xsl:variable name="middle">
        <xsl:value-of select="substring-before(substring-after($name, '['), ']')"/>
       </xsl:variable>
       <xsl:value-of select="lower-case(concat($front_half, $middle, $back_half ))"/>
      </xsl:when>
      <xsl:otherwise>
       <xsl:value-of select="lower-case($name)"/>
      </xsl:otherwise>
     </xsl:choose>
    </xsl:when>
    <xsl:otherwise>
     <!-- When there is a valid instance value, use it instead of the number in the bracket -->
     <xsl:choose>
      <xsl:when test="contains($name, '[')">
       <xsl:variable name="front_half">
        <xsl:value-of select="substring-before($name, '[')"/>
       </xsl:variable>
       <xsl:variable name="back_half">
        <xsl:value-of select="substring-after($name, ']')"/>
       </xsl:variable>
       <xsl:variable name="middle">
        <xsl:value-of select="$instance"/>
       </xsl:variable>
       <xsl:value-of select="lower-case(concat($front_half, $middle, $back_half ))"/>
      </xsl:when>
      <xsl:otherwise>
       <!-- If there is no bracket in the field name, just dump the number at the end -->
       <xsl:value-of select="lower-case(concat($name, $instance))"/>
      </xsl:otherwise>
     </xsl:choose>
    </xsl:otherwise>
   </xsl:choose>
  </xsl:variable>

  <xsl:choose>
   <xsl:when test="string-length($prefix) &gt; 1 and contains($pre-prefix, '_')">
    <xsl:value-of select="lower-case(concat($prefix, substring-after($pre-prefix, '_')))"/>
   </xsl:when>
   <xsl:otherwise>
    <xsl:value-of select="$pre-prefix"/>
   </xsl:otherwise>
  </xsl:choose>
 </xsl:template>

 <xsl:template name="substring-after-last">
  <xsl:param name="string"/>
  <xsl:param name="delimiter"/>
  <xsl:choose>
   <xsl:when test="contains($string, $delimiter)">
    <xsl:call-template name="substring-after-last">
     <xsl:with-param name="string" select="substring-after($string, $delimiter)"/>
     <xsl:with-param name="delimiter" select="$delimiter"/>
    </xsl:call-template>
   </xsl:when>
   <xsl:otherwise>
    <xsl:value-of select="$string"/>
   </xsl:otherwise>
  </xsl:choose>
 </xsl:template>

 <xsl:template name="process-register">
  <xsl:param name="current_location"/>
  <xsl:param name="current_name"/>
  <xsl:param name="current_offset"/>
  <xsl:param name="current_register"/>
  <!-- correct the number of characters in the offset -->

  <xsl:variable name="id">
   <xsl:call-template name="substring-after-last">
    <xsl:with-param name="string" select="$current_register"/>
    <xsl:with-param name="delimiter" select="'/'"/>
   </xsl:call-template>
  </xsl:variable>


  <xsl:variable name="local_base">
   <xsl:variable name="temp">
    <xsl:call-template name="substring-before-last">
     <xsl:with-param name="string1" select="base-uri()"/>
     <xsl:with-param name="string2" select="'/'"/>
    </xsl:call-template>
   </xsl:variable>
   <xsl:value-of select="concat($temp, '/')"/>
  </xsl:variable>

  <!-- If the register tables are in the same file as the table defining the device, use the base-uri for forming the path rather than the document-uri -->
  <xsl:variable name="file">
   <xsl:choose>
    <!-- Check to see if the whole freaking path is there first -->
    <xsl:when test="contains(substring-before($current_register, '#'), '.xml') and contains(substring-before($current_register, '#'), 'file:')">
      <xsl:value-of select="substring-before($current_register, '#')"/>
    </xsl:when>
    <!-- Then assume that it might be just a relative path -->
    <xsl:when test="contains(substring-before($current_register, '#'), '.xml')">
     <xsl:value-of select="$local_base"/>
     <xsl:value-of select="substring-before($current_register, '#')"/>
    </xsl:when>
    <!-- Then run up the white flag and hope that it's in the current doumnent. -->
    <xsl:otherwise>
     <xsl:value-of select="base-uri()"/>
    </xsl:otherwise>
   </xsl:choose>
  </xsl:variable>
 
  <xsl:variable name="current_nodeset" select="document($file)//*[@id = $id]//registers"/>

  <xsl:element name="carreg">
   <xsl:attribute name="name">
    <xsl:value-of select="$current_name"/>
   </xsl:attribute>
   <xsl:attribute name="addr">
    <xsl:value-of select="concat($current_location, $current_offset)"/>
   </xsl:attribute>
   <xsl:attribute name="description">
    <xsl:value-of select="$current_nodeset/ancestor::table/title"/>
   </xsl:attribute>
   <!--<xsl:attribute name="default">
    <xsl:call-template name="default-value">
     <xsl:with-param name="nodes" select="$current_nodeset"/>
    </xsl:call-template>
   </xsl:attribute>-->
   <xsl:for-each select="$current_nodeset//register">
    <xsl:choose>
     <xsl:when test="$internal = 0">
      <xsl:if test="not(contains(@audience, 'PMCInternal'))">
       <xsl:element name="field">
        <xsl:attribute name="name">
         <xsl:call-template name="process-fieldname"/>
        </xsl:attribute>
        <!-- Since doubles and singles can't both exist, I should just be able to call both and whichever one is present will resolve -->
        <xsl:attribute name="msbit">
         <xsl:value-of
          select="normalize-space(concat(reg-position/single/text(), reg-position/double/msb/text()))"
         />
        </xsl:attribute>
        <xsl:attribute name="lsbit">
         <xsl:value-of
          select="normalize-space(concat(reg-position/single/text(), reg-position/double/lsb/text()))"
         />
        </xsl:attribute>
        <xsl:attribute name="attr">
         <xsl:value-of select="normalize-space(reg-type)"/>
        </xsl:attribute>
        <xsl:attribute name="default">
         <xsl:choose>
          <xsl:when test="contains(reg-default, '_')">
           <xsl:value-of select="normalize-space(translate(reg-default, '_', ''))"/>
          </xsl:when>
          <xsl:otherwise>
           <xsl:value-of select="normalize-space(reg-default)"/>
          </xsl:otherwise>
         </xsl:choose>
        </xsl:attribute>
       </xsl:element>
      </xsl:if>
     </xsl:when>
     <xsl:otherwise>
      <xsl:element name="field">
       <xsl:attribute name="name">
        <xsl:call-template name="process-fieldname"/>
       </xsl:attribute>
       <!-- Since doubles and singles can't both exist, I should just be able to call both and whichever one is present will resolve -->
       <xsl:attribute name="msbit">
        <xsl:value-of
         select="normalize-space(concat(reg-position/single/text(), reg-position/double/msb/text()))"
        />
       </xsl:attribute>
       <xsl:attribute name="lsbit">
        <xsl:value-of
         select="normalize-space(concat(reg-position/single/text(), reg-position/double/lsb/text()))"
        />
       </xsl:attribute>
       <xsl:attribute name="attr">
        <xsl:value-of select="normalize-space(reg-type)"/>
       </xsl:attribute>
       <xsl:attribute name="default">
        <xsl:choose>
         <xsl:when test="contains(reg-default, '_')">
          <xsl:value-of select="normalize-space(translate(reg-default, '_', ''))"/>
         </xsl:when>
         <xsl:otherwise>
          <xsl:value-of select="normalize-space(reg-default)"/>
         </xsl:otherwise>
        </xsl:choose>
       </xsl:attribute>
      </xsl:element>
     </xsl:otherwise>
    </xsl:choose>
   </xsl:for-each>
  </xsl:element>

 </xsl:template>

 <xsl:template name="process-fieldname">
  <xsl:variable name="name">
   <xsl:value-of select="reg-name"/>
  </xsl:variable>
  <xsl:choose>
   <xsl:when test="contains(lower-case($name), 'reserve')">
    <xsl:value-of
     select="concat(lower-case($name), normalize-space(concat(reg-position/single/text(), reg-position/double/lsb/text())))"
    />
   </xsl:when>
   <xsl:otherwise>
    <xsl:value-of select="lower-case($name)"/>
   </xsl:otherwise>
  </xsl:choose>
 </xsl:template>

 <xsl:template name="substring-before-last">
  <xsl:param name="string1" select="''"/>
  <xsl:param name="string2" select="''"/>

  <xsl:if test="$string1 != '' and $string2 != ''">
   <xsl:variable name="head" select="substring-before($string1, $string2)"/>
   <xsl:variable name="tail" select="substring-after($string1, $string2)"/>
   <xsl:value-of select="$head"/>
   <xsl:if test="contains($tail, $string2)">
    <xsl:value-of select="$string2"/>
    <xsl:call-template name="substring-before-last">
     <xsl:with-param name="string1" select="$tail"/>
     <xsl:with-param name="string2" select="$string2"/>
    </xsl:call-template>
   </xsl:if>
  </xsl:if>
 </xsl:template>

 <!-- This is for calculating the default value for the whole register -->
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

  <xsl:variable name="total_fields" select="count($nodes/register)"/>
  <xsl:variable name="total_nodes" select="count($nodes)"/>

  <xsl:variable name="range">
   <xsl:call-template name="get-range">
    <xsl:with-param name="value_cell" select="$nodes/register[$count_field]/reg-position"/>
   </xsl:call-template>
  </xsl:variable>

  <!-- convert the bit default to binary so that we can prepend it to the mask value -->
  <xsl:variable name="bit_default" as="xs:string">
   <xsl:choose>
    <xsl:when test="number(substring-after($nodes/register[$count_field]/reg-default, '0x')) = 0"
     >0</xsl:when>
    <xsl:when test="contains($nodes/register[$count_field]/reg-default, '0x')">
     <xsl:variable name="temp">
      <xsl:call-template name="math:base-convert">
       <xsl:with-param name="from-base" select="16"/>
       <xsl:with-param name="to-base" select="2"/>
       <xsl:with-param name="value"
        select="substring-after($nodes/register[$count_field]/reg-default, '0x')"/>
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
     <xsl:value-of select="substring('00000000000000000000000000000000', 1, $current_bit)"/>
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
    <xsl:if test="not(xs:integer($running_total + $current_default) &gt; 0)">0x00000000</xsl:if>
   </xsl:when>
   <xsl:when test="$count_field &gt; $total_fields">
    <xsl:call-template name="default-value">
     <xsl:with-param name="nodes" select="$nodes"/>
     <xsl:with-param name="current_bit" select="$current_bit"/>
     <xsl:with-param name="count" select="$count + 1"/>
     <xsl:with-param name="count_field" select="1"/>
     <xsl:with-param name="running_total" select="xs:integer($running_total + $current_default)"/>
    </xsl:call-template>
   </xsl:when>
   <xsl:when test="$count_field &lt;= $total_fields">
    <xsl:call-template name="default-value">
     <xsl:with-param name="nodes" select="$nodes"/>
     <xsl:with-param name="current_bit" select="$current_bit + number($range)"/>
     <xsl:with-param name="count" select="$count"/>
     <xsl:with-param name="count_field" select="$count_field + 1"/>
     <xsl:with-param name="running_total" select="xs:integer($running_total + $current_default)"/>
    </xsl:call-template>
   </xsl:when>
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

 <xsl:template name="form-hex-value">
  <xsl:param name="string"/>
  <xsl:variable name="length" select="string-length($string)"/>
  <xsl:value-of select="lower-case(substring(concat('00000000', $string), $length + 1, 8))"/>
 </xsl:template>

 <!-- Math Functions -->

 <xsl:function name="f:hexToDec">
  <xsl:param name="hex"/>
  <xsl:variable name="dec"
   select="string-length(substring-before('0123456789ABCDEF', substring($hex,1,1)))"/>
  <xsl:choose>
   <xsl:when test="matches($hex, '([0-9]*|[A-F]*)')">
    <xsl:value-of
     select="if ($hex = '') then 0
     else $dec * f:power(16, string-length($hex) - 1) + f:hexToDec(substring($hex,2))"
    />
   </xsl:when>
   <xsl:otherwise>
    <xsl:message>Provided value is not hexadecimal...</xsl:message>
    <xsl:value-of select="$hex"/>
   </xsl:otherwise>
  </xsl:choose>
 </xsl:function>

 <xsl:function name="f:power">
  <xsl:param name="base"/>
  <xsl:param name="exp"/>
  <xsl:sequence
   select="if ($exp lt 0) then f:power(1.0 div $base, -$exp)
   else if ($exp eq 0)
   then 1e0
   else $base * f:power($base, $exp - 1)"
  />
 </xsl:function>

 <xsl:function name="f:decimalToHex">
  <xsl:param name="dec"/>
  <xsl:if test="$dec > 0">
   <xsl:value-of
    select="f:decimalToHex(floor($dec div 16)),substring('0123456789ABCDEF', (($dec mod 16) + 1), 1)"
    separator=""/>
  </xsl:if>
 </xsl:function>


</xsl:stylesheet>
