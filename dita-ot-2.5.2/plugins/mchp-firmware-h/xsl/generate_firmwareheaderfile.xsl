<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
 xmlns:str="http://xsltsl.org/string" xmlns:xs="http://www.w3.org/2001/XMLSchema" xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac" xmlns:math = "http://exslt.org/math"
 exclude-result-prefixes="xs" version="2.0">
 
 <xsl:import href="xsltsl-1.2.1/stdlib.xsl"/>
 <xsl:import href="variables.xsl"/>
 <xsl:import href="create_sets.xsl"/>
 <xsl:import href="hexConversions.xsl"/>
 <xsl:import href="conversionFunctions.xsl"/> 
 <xsl:param name="datatype">u32</xsl:param>
 <xsl:param name="production-path"></xsl:param>
 
 <xsl:variable name="line_feed">
  <xsl:text>        
</xsl:text>
 </xsl:variable>
 
 <xsl:output media-type="text" indent="no" encoding="UTF-8" omit-xml-declaration="yes"/>
 
 <xsl:strip-space elements="*"/>
 
 <xsl:template match="/">
  
  <xsl:result-document method="text" href="{$production-path}PCIeCSRInit.h">   
  <xsl:value-of select="$PCIeCSRInitHeader"/>
  <xsl:variable name="nodeset">
   <xsl:apply-templates mode="variable"/>
  </xsl:variable>
  <xsl:text>
/* This file is autogenerated by pcimCsrInit in EFC/scripts/PCIeMgr */
#ifndef PCIE_CSR_INIT_H_
#define PCIE_CSR_INIT_H_

#include &lt;PCIeCSR.h&gt;

/**
 * @file PCIeCSRInit.h 
 * @brief Contains the PCIe Manager Configuration Space Register initialziation
 *        arrays derived from the PCIe Manager Chapter in the Firmware Architecture Spec.
 *
 */       
   </xsl:text>
   
   <!-- PCIe Manager Register Initialization Values -->
   <xsl:text>    
 /**
 * @brief PCIe Manager Register Initialization Values
 *
 * @defgroup pcim_CSRInit_array_fields PCIe Manager Register Initialization Values
 */
/** @{ */
u32 pcim_CSRInit_array[PCIM_MAX_CSR_SIZE_DW] = {</xsl:text><xsl:call-template name="process-groups">
    <xsl:with-param name="suffix" tunnel="yes">DEFAULT_VALUE</xsl:with-param>
   </xsl:call-template><xsl:text>
    };
/** @} */
   </xsl:text>
   <!-- PCIe Manager Register Write Mask -->
   <xsl:text>
   /**
   * @brief PCIe Manager Register Write Mask
   *
   * @defgroup pcim_CSR_WR_MASK_fields PCIe Manager Register Write Mask
   */
   /** @{ */
   u32 pcim_CSR_WR_MASK[PCIM_MAX_CSR_SIZE_DW] = {</xsl:text><xsl:call-template name="process-groups">
    <xsl:with-param name="suffix" tunnel="yes">WR_MSK</xsl:with-param>
   </xsl:call-template><xsl:text>};
   /** @} */</xsl:text>
   
   <!--  PCIe Manager Register Sticky Mask -->
   
   <xsl:text>
   /**
   * @brief PCIe Manager Register Sticky Mask
   *
   * @defgroup pcim_CSR_STICKY_MASK_fields PCIe Manager Register Sticky Mask
   */
   /** @{ */
   u32 pcim_CSR_STICKY_MASK[PCIM_MAX_CSR_SIZE_DW] = {</xsl:text><xsl:call-template name="process-groups">
    <xsl:with-param name="suffix" tunnel="yes">STICKY_MSK</xsl:with-param>
   </xsl:call-template><xsl:text>
   };
   /** @} */
   
   
   #endif /* PCIE_CSR_INIT_H_*/
   </xsl:text>   
  </xsl:result-document>
 
  <xsl:result-document method="text" href="{$production-path}PCIeCSR.h">  
   <xsl:value-of select="$PCIeCSRHeader"/>
   <xsl:variable name="nodeset">
    <xsl:apply-templates mode="variable"/>
   </xsl:variable>
   <xsl:text>
/* This file is autogenerated */
#ifndef PCIE_CSR_H_
#define PCIE_CSR_H_


/**
 * @file PCIeCSR.h 
 * @brief Contains the PCIe Manager Configuration Space Register definitions
 *        derived from the PCIe Manager Chapter in Firmware Architecture Spec.
 */
 
 
/**
 * @brief PCIe Manager CSR Field Attributes
 *
 * @defgroup pcim_attribute_fields PCIe Manager CSR Field Attributes
 */
/** @{ */
#define CSR_FLD_ATTR_RO                                                  (0)
#define CSR_FLD_ATTR_RW                                                  (1)
#define CSR_FLD_ATTR_RC                                                  (2)
#define CSR_FLD_ATTR_RW1C                                                (3)
#define CSR_FLD_ATTR_RWL                                                 (4)
#define CSR_FLD_ATTR_RWS                                                 (5)
#define CSR_FLD_ATTR_ROS                                                 (6)
#define CSR_FLD_ATTR_RW1CS                                               (7)
#define CSR_FLD_ATTR_RW1                                                 (8)
/** @} */
   </xsl:text>
   
 
   <xsl:call-template name="process-registers"></xsl:call-template>  
   #endif /* PCIE_CSR_H_*/ 
   
  </xsl:result-document>
 
 </xsl:template>
 
 
</xsl:stylesheet>
