<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac"
    version="2.0">
    
    <xsl:param name="MAX_LINE_SIZE" select="160"/>
    <xsl:param name="MAX_NUM_UNDERSCORE_FIELDS" select="6"/>
    <xsl:param name="MAX_ABBRV_NAME" select="32"/>
    <xsl:param name="MAX_DESC_TITLE_LENGTH" select="80"/>
    <xsl:param name="PCIM_CSR">PCIeCSR.h</xsl:param>
    <xsl:param name="PCIM_CSR_INIT">PCIeCSRInit.h</xsl:param>
    <xsl:param name="ATTR_NAME_PREFIX">CSR_FLD_ATTR</xsl:param>
   
    <xsl:param name="DEFINE_COL_WIDTH" select="9"/>
    <xsl:param name="OFFSET_COL_WIDTH" select="74"/>
    <xsl:param name="BASE_HEX" select="16"/>
    <xsl:param name="BASE_DEC" select="10"/>
    
    <xsl:param name="EXPECTED_BIT_FIELDS_B4_DESC" select="4"/>
   
    <!-- Expected Number of NVMe Registers -->
    <xsl:param name="NVME_NUM_REGS" select="10"/>
    
    <xsl:param name="CSR_EXCEPTION_SIZE" select="9"/>
    <xsl:param name="CSR_EXCEPTION_OFFSET">0xBEEFBEE4</xsl:param>
   
    <xsl:param name="PRINT_ARRAY_INIT" select="0"/>
    <xsl:param name="PRINT_ARRAY_WMSK" select="1"/>
    <xsl:param name="PRINT_ARRAY_STICKY" select="2"/>
     
    
    <xsl:variable name="PCIeCSRHeader">
        <xsl:text>/****************************************************************************
*
* Copyright (c)  2018 Microchip Technology Inc.
*      All Rights Reserved
*
* Distribution of source code or binaries derived from this file is not
* permitted except as specifically allowed for in the Microchip
* Software License agreement.  All copies of this source code
* modified or unmodified must retain this entire copyright notice and
* comment as is.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* Description                  : </xsl:text><xsl:value-of select="/bookmap/topic[1]/title[1]"></xsl:value-of><xsl:text>
*
* $Revision: 14210 $
* $Date: 2013-11-21 03:15:05 -0800 (Thu, 21 Nov 2013) $
* $Author: hahammot $
* Release $Name$
*
****************************************************************************/
        </xsl:text>
    </xsl:variable>
    
    <xsl:variable name="PCIeCSRInitHeader">
        <xsl:text>/****************************************************************************
*
* Copyright (c)  2018 Microchip Technology Inc.
*      All Rights Reserved
*
* Distribution of source code or binaries derived from this file is not
* permitted except as specifically allowed for in the Microchip
* Software License agreement.  All copies of this source code
* modified or unmodified must retain this entire copyright notice and
* comment as is.
*
* THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* Description                  : </xsl:text><xsl:value-of select="/bookmap/topic[1]/title[1]"></xsl:value-of><xsl:text>
*
* $Revision: 14210 $
* $Date: 2013-11-21 03:15:05 -0800 (Thu, 21 Nov 2013) $
* $Author: hahammot $
* Release $Name$
*
****************************************************************************/
        </xsl:text>
    </xsl:variable>

<xsl:variable name="nvme_block">
    <xsl:text>        
 /**
 * @brief - NVMe Capability  field definitions
 *
 * @defgroup NVMECAP_fields - NVMe Capability 
 */
/** @{ */
#define NVME_FW_BASE_ADDR                                                (0x000001b0)
#define NVME_CAPL_OFFSET                                                 (NVME_FW_BASE_ADDR+NVME_CAP)
#define NVME_CAPU_OFFSET                                                 (NVME_CAPL_OFFSET+4)
#define NVME_VER_OFFSET                                                  (NVME_FW_BASE_ADDR+NVME_VS)
#define NVME_INTMS_OFFSET                                                (NVME_FW_BASE_ADDR+NVME_INTMS)
#define NVME_INTMC_OFFSET                                                (NVME_FW_BASE_ADDR+NVME_INTMC)
#define NVME_CCL_OFFSET                                                  (NVME_FW_BASE_ADDR+NVME_CC)
#define NVME_CCU_OFFSET                                                  (NVME_CCL_OFFSET+4)
#define NVME_CSTS_OFFSET                                                 (NVME_FW_BASE_ADDR+NVME_CSTS)
#define NVME_NSSR_OFFSET                                                 (NVME_FW_BASE_ADDR+NVME_NSSR)
#define NVME_AQA_OFFSET                                                  (NVME_FW_BASE_ADDR+NVME_AQA)
#define NVME_ASQL_OFFSET                                                 (NVME_FW_BASE_ADDR+NVME_ASQ)
#define NVME_ASQU_OFFSET                                                 (NVME_ASQL_OFFSET+4)
#define NVME_ACQL_OFFSET                                                 (NVME_FW_BASE_ADDR+NVME_ACQ)
#define NVME_ACQU_OFFSET                                                 (NVME_ACQL_OFFSET+4)
/** @} */
    </xsl:text>
</xsl:variable>


</xsl:stylesheet>