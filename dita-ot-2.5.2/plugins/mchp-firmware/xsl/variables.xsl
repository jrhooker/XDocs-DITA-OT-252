<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  xmlns:ditac="http://www.xmlmind.com/ditac/schema/ditac"
    version="2.0">
    
    <xsl:variable name="starting_block">
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
 * Description                  : </xsl:text><xsl:value-of select="/ditac:chunk/topic[1]/title[1]"></xsl:value-of><xsl:text>
 *                                This file is auto-generated, do not modify.
 * 
 * $Revision$
 * $Date$
 * $Author$
 * Release $Name$
 *
 ****************************************************************************/
        </xsl:text>
    </xsl:variable>
    
</xsl:stylesheet>