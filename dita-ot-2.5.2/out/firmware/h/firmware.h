/****************************************************************************
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
 * Description                  : 
 *                                This file is auto-generated, do not modify.
 * 
 * $Revision$
 * $Date$
 * $Author$
 * Release $Name$
 *
 ****************************************************************************/
        
#ifndef _FLASH_INTERFACE_MESSAGES_MESSAGES_H_
#define _FLASH_INTERFACE_MESSAGES_MESSAGES_H_
  
/** 
* @brief Enumerate the opcode for each message
*/
typedef enum {
  FLASH_ADDR_FORMAT_OPCODE = 0,    
  FLASH_CHANNEL_CONFIG_UPDATE_OPCODE = 5,    
  FLASH_ECC_CONTEXT_INFO_UPDATE_OPCODE = 5,    
  ECC_CONTEXT_DATA_OPCODE = 0,    
  FLASH_TIMING_PARAM_UPDATE_OPCODE = 5,    
  FLASH_POWER_CREDIT_UPDATE_OPCODE = 5,    
  FLASH_DYNAMIC_UPDATE_OPCODE = 5,    
  GET_ITERATION_COUNT_OPCODE = 5,    
  READ_HEADER_OPCODE = 0,    
  WRITE_HEADER_OPCODE = 0,    
  FLASH_READ_OPCODE = 1,    
  FLASH_WRITE_OPCODE = 2,    
  FLASH_CONT_OPCODE = 4,    
  FLASH_ERASE_OPCODE = 3,    
  DATA_FRAME_BUFF_TYPE_OPCODE = 0,    
  FLASH_OP_CPL_OPCODE = 1,    
  FLASH_RD_PLANE_CPL_INFO_OPCODE = 0,    
  FLASH_WR_ER_PLANE_CPL_INFO_OPCODE = 0,    
  FLASH_OP_CPL_CONT_OPCODE = 2,    
  FLASH_MEM_WRITE_OPCODE = 255,    
  FLASH_READ_PARAMETER_PAGE_OPCODE = 6,    
  FLASH_READ_ID_OPCODE = 7,    
  FLASH_OP_CPL_DATA_OPCODE = 3,    
  FLASH_SET_FEAT_OPCODE = 8,    
  FLASH_GET_FEAT_OPCODE = 9,    
  FLASH_ADDR_FORMAT_OPCODE = 0,    
  FLASH_CHANNEL_CONFIG_UPDATE_OPCODE = 5,    
  FLASH_ECC_CONTEXT_INFO_UPDATE_OPCODE = 5,    
  ECC_CONTEXT_DATA_OPCODE = 0,    
  FLASH_TIMING_PARAM_UPDATE_OPCODE = 5,    
  FLASH_POWER_CREDIT_UPDATE_OPCODE = 5,    
  FLASH_DYNAMIC_UPDATE_OPCODE = 5,    
  READ_HEADER_OPCODE = 0,    
  E_C_C CODE RATE_OPCODE = 0,    
  WRITE_HEADER_OPCODE = 0,    
  FLASH_READ_OPCODE = 1,    
  FLASH_WRITE_OPCODE = 2,    
  FLASH_CONT_OPCODE = 4,    
  FLASH_ERASE_OPCODE = 3,    
  FLASH_OP_CPL_OPCODE = 1,    
  FLASH_RD_PLANE_CPL_INFO_OPCODE = 0,    
  FLASH_WR_ER_PLANE_CPL_INFO_OPCODE = 0,    
  FLASH_OP_CPL_CONT_OPCODE = 2,    
  FLASH_MEM_WRITE_OPCODE = 255,    
  FLASH_READ_PARAMETER_PAGE_OPCODE = 6,    
  FLASH_READ_ID_OPCODE = 7,    
  FLASH_OP_CPL_DATA_OPCODE = 3,    
  FLASH_SET_FEAT_OPCODE = 8,    
  FLASH_GET_FEAT_OPCODE = 9    
  }flash_interface_messages_opcodes_e;                
/** 
* @brief Macro to create dword0 for message FLASH_ADDR_FORMAT
*/
#define FLASH_ADDR_FORMAT_DW0+(pageNum,blockNum,lunNum) (((pageNum)<<FLASH_ADDR_FORMAT_PAGENUM_LSB )|((blockNum)<<FLASH_ADDR_FORMAT_BLOCKNUM_LSB )|((lunNum)<<FLASH_ADDR_FORMAT_LUNNUM_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_CHANNEL_CONFIG_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_CHANNEL_CONFIG_UPDATE_CNTXT_LSB )|((chan)<<FLASH_CHANNEL_CONFIG_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_CHANNEL_CONFIG_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_CHANNEL_CONFIG_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_CHANNEL_CONFIG_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW4-(subMsgType,numContext,numLun,lunBitPosition) (((subMsgType)<<FLASH_CHANNEL_CONFIG_UPDATE_SUBMSGTYPE_LSB )|((numContext)<<FLASH_CHANNEL_CONFIG_UPDATE_NUMCONTEXT_LSB )|((numLun)<<FLASH_CHANNEL_CONFIG_UPDATE_NUMLUN_LSB )|((lunBitPosition)<<FLASH_CHANNEL_CONFIG_UPDATE_LUNBITPOSITION_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW5-(pageSize) (((pageSize)<<FLASH_CHANNEL_CONFIG_UPDATE_PAGESIZE_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW6-(_1stContext,_1stContextCE,_1stContextLun,_2ndContext,_2ndContextCE,_2ndContextLun) (((_1stContext)<<FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXT_LSB )|((_1stContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTCE_LSB )|((_1stContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTLUN_LSB )|((_2ndContext)<<FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXT_LSB )|((_2ndContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTCE_LSB )|((_2ndContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW7-(_3rdContext,_3rdContextCE,_3rdContextLun,_4thContext,_4thContextCE,_4thContextLun) (((_3rdContext)<<FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXT_LSB )|((_3rdContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTCE_LSB )|((_3rdContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTLUN_LSB )|((_4thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXT_LSB )|((_4thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTCE_LSB )|((_4thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW8-(_5thContext,_5thContextCE,_5thContextLun,_6thContext,_6thContextCE,_6thContextLun) (((_5thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXT_LSB )|((_5thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTCE_LSB )|((_5thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTLUN_LSB )|((_6thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXT_LSB )|((_6thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTCE_LSB )|((_6thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW9-(_7thContext,_7thContextCE,_7thContextLun,_8thContext,_8thContextCE,_8thContextLun) (((_7thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXT_LSB )|((_7thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTCE_LSB )|((_7thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTLUN_LSB )|((_8thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXT_LSB )|((_8thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTCE_LSB )|((_8thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW10-(_9thContext,_9thContextCE,_9thContextLun,_10thContext,_10thContextCE,_10thContextLun) (((_9thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXT_LSB )|((_9thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTCE_LSB )|((_9thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTLUN_LSB )|((_10thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXT_LSB )|((_10thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTCE_LSB )|((_10thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW11-(_11thContext,_11thContextCE,_11thContextLun,_12thContext,_12thContextCE,_12thContextLun) (((_11thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXT_LSB )|((_11thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTCE_LSB )|((_11thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTLUN_LSB )|((_12thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXT_LSB )|((_12thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTCE_LSB )|((_12thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW12-(_13thContext,_13thContextCE,_13thContextLun,_14thContext,_14thContextCE,_14thContextLun) (((_13thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXT_LSB )|((_13thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTCE_LSB )|((_13thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTLUN_LSB )|((_14thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXT_LSB )|((_14thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTCE_LSB )|((_14thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW13-(_15thContext,_15thContextCE,_15thContextLun,_16thContext,_16thContextCE,_16thContextLun) (((_15thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXT_LSB )|((_15thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTCE_LSB )|((_15thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTLUN_LSB )|((_16thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXT_LSB )|((_16thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTCE_LSB )|((_16thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_ECC_CONTEXT_INFO_UPDATE
*/
#define FLASH_ECC_CONTEXT_INFO_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_ECC_CONTEXT_INFO_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CNTXT_LSB )|((chan)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_ECC_CONTEXT_INFO_UPDATE
*/
#define FLASH_ECC_CONTEXT_INFO_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_ECC_CONTEXT_INFO_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_ECC_CONTEXT_INFO_UPDATE
*/
#define FLASH_ECC_CONTEXT_INFO_UPDATE_DW4-(subMsgType,numEntries) (((subMsgType)<<FLASH_ECC_CONTEXT_INFO_UPDATE_SUBMSGTYPE_LSB )|((numEntries)<<FLASH_ECC_CONTEXT_INFO_UPDATE_NUMENTRIES_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message ECC_CONTEXT_DATA
*/
#define ECC_CONTEXT_DATA_DW0+(eccContextNum,eccChunkSize,protectedDataSize) (((eccContextNum)<<ECC_CONTEXT_DATA_ECCCONTEXTNUM_LSB )|((eccChunkSize)<<ECC_CONTEXT_DATA_ECCCHUNKSIZE_LSB )|((protectedDataSize)<<ECC_CONTEXT_DATA_PROTECTEDDATASIZE_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_TIMING_PARAM_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_TIMING_PARAM_UPDATE_CNTXT_LSB )|((chan)<<FLASH_TIMING_PARAM_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_TIMING_PARAM_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_TIMING_PARAM_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_TIMING_PARAM_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW4-(subMsgType,timeSel) (((subMsgType)<<FLASH_TIMING_PARAM_UPDATE_SUBMSGTYPE_LSB )|((timeSel)<<FLASH_TIMING_PARAM_UPDATE_TIMESEL_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW5-(dummyBusyTime,clkHigh2RBLowTime) (((dummyBusyTime)<<FLASH_TIMING_PARAM_UPDATE_DUMMYBUSYTIME_LSB )|((clkHigh2RBLowTime)<<FLASH_TIMING_PARAM_UPDATE_CLKHIGH2RBLOWTIME_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW6-(resetTime) (((resetTime)<<FLASH_TIMING_PARAM_UPDATE_RESETTIME_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW7-(powerOnRstTime) (((powerOnRstTime)<<FLASH_TIMING_PARAM_UPDATE_POWERONRSTTIME_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW8-(interfaceChangeTime) (((interfaceChangeTime)<<FLASH_TIMING_PARAM_UPDATE_INTERFACECHANGETIME_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW9-(featureTime) (((featureTime)<<FLASH_TIMING_PARAM_UPDATE_FEATURETIME_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW10-(rdPollTime,wrPollTime) (((rdPollTime)<<FLASH_TIMING_PARAM_UPDATE_RDPOLLTIME_LSB )|((wrPollTime)<<FLASH_TIMING_PARAM_UPDATE_WRPOLLTIME_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW11-(berPollTime,miscPollTime) (((berPollTime)<<FLASH_TIMING_PARAM_UPDATE_BERPOLLTIME_LSB )|((miscPollTime)<<FLASH_TIMING_PARAM_UPDATE_MISCPOLLTIME_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW12-(maxPollCount) (((maxPollCount)<<FLASH_TIMING_PARAM_UPDATE_MAXPOLLCOUNT_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_POWER_CREDIT_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_POWER_CREDIT_UPDATE_CNTXT_LSB )|((chan)<<FLASH_POWER_CREDIT_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_POWER_CREDIT_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_POWER_CREDIT_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_POWER_CREDIT_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW4-(subMsgType) (((subMsgType)<<FLASH_POWER_CREDIT_UPDATE_SUBMSGTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW5-(readSLCPowerCredit,programSLCPowerCredit) (((readSLCPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_READSLCPOWERCREDIT_LSB )|((programSLCPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_PROGRAMSLCPOWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW6-(erasePowerCredit,readTLCSinglePlanePowerCredit) (((erasePowerCredit)<<FLASH_POWER_CREDIT_UPDATE_ERASEPOWERCREDIT_LSB )|((readTLCSinglePlanePowerCredit)<<FLASH_POWER_CREDIT_UPDATE_READTLCSINGLEPLANEPOWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW7-(readTLCMultiPlanePowerCredit,programTLCPass1PowerCredit) (((readTLCMultiPlanePowerCredit)<<FLASH_POWER_CREDIT_UPDATE_READTLCMULTIPLANEPOWERCREDIT_LSB )|((programTLCPass1PowerCredit)<<FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS1POWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW8-(programTLCPass2PowerCredit,programTLCPass3PowerCredit) (((programTLCPass2PowerCredit)<<FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS2POWERCREDIT_LSB )|((programTLCPass3PowerCredit)<<FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS3POWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW9-(eraseWorkaroundPowerCredit,miscPowerCredit) (((eraseWorkaroundPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_ERASEWORKAROUNDPOWERCREDIT_LSB )|((miscPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_MISCPOWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_DYNAMIC_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_DYNAMIC_UPDATE_CNTXT_LSB )|((chan)<<FLASH_DYNAMIC_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_DYNAMIC_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_DYNAMIC_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_DYNAMIC_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW4-(subMsgType) (((subMsgType)<<FLASH_DYNAMIC_UPDATE_SUBMSGTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW5-(highPriorPollLimit) (((highPriorPollLimit)<<FLASH_DYNAMIC_UPDATE_HIGHPRIORPOLLLIMIT_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW6-(dmpDDRBuffAddr) (((dmpDDRBuffAddr)<<FLASH_DYNAMIC_UPDATE_DMPDDRBUFFADDR_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW7-(dmpBRAMBuffAddr) (((dmpBRAMBuffAddr)<<FLASH_DYNAMIC_UPDATE_DMPBRAMBUFFADDR_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message GET_ITERATION_COUNT
*/
#define GET_ITERATION_COUNT_DW0+(cntxt,chan) (((msgType)<<GET_ITERATION_COUNT_MSGTYPE_LSB )|((cntxt)<<GET_ITERATION_COUNT_CNTXT_LSB )|((chan)<<GET_ITERATION_COUNT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message GET_ITERATION_COUNT
*/
#define GET_ITERATION_COUNT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<GET_ITERATION_COUNT_CHMSGNODEADDR_LSB )|((chain)<<GET_ITERATION_COUNT_CHAIN_LSB )|((outMsgQ)<<GET_ITERATION_COUNT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message GET_ITERATION_COUNT
*/
#define GET_ITERATION_COUNT_DW4-(subMsgType,reset) (((subMsgType)<<GET_ITERATION_COUNT_SUBMSGTYPE_LSB )|((reset)<<GET_ITERATION_COUNT_RESET_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message READ_HEADER
*/
#define READ_HEADER_DW0+(planeNum,numBuffers,lastBufferSpan,numECCChunk,startECCChunk,startDumpCount,hdrSig) (((planeNum)<<READ_HEADER_PLANENUM_LSB )|((numBuffers)<<READ_HEADER_NUMBUFFERS_LSB )|((lastBufferSpan)<<READ_HEADER_LASTBUFFERSPAN_LSB )|((numECCChunk)<<READ_HEADER_NUMECCCHUNK_LSB )|((startECCChunk)<<READ_HEADER_STARTECCCHUNK_LSB )|((startDumpCount)<<READ_HEADER_STARTDUMPCOUNT_LSB )|((hdrSig)<<READ_HEADER_HDRSIG_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message WRITE_HEADER
*/
#define WRITE_HEADER_DW0+(planeNum,numBuffers,lastBufferSpan,numECCChunk,lastDataFrameLength,hdrSig) (((planeNum)<<WRITE_HEADER_PLANENUM_LSB )|((numBuffers)<<WRITE_HEADER_NUMBUFFERS_LSB )|((lastBufferSpan)<<WRITE_HEADER_LASTBUFFERSPAN_LSB )|((numECCChunk)<<WRITE_HEADER_NUMECCCHUNK_LSB )|((lastDataFrameLength)<<WRITE_HEADER_LASTDATAFRAMELENGTH_LSB )|((hdrSig)<<WRITE_HEADER_HDRSIG_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_READ
*/
#define FLASH_READ_DW0+(cntxt,chan) (((msgType)<<FLASH_READ_MSGTYPE_LSB )|((cntxt)<<FLASH_READ_CNTXT_LSB )|((chan)<<FLASH_READ_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_READ
*/
#define FLASH_READ_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_READ_CHMSGNODEADDR_LSB )|((chain)<<FLASH_READ_CHAIN_LSB )|((outMsgQ)<<FLASH_READ_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_READ
*/
#define FLASH_READ_DW8-(eccCodeRateIndex,maxIter,LLR0,LLR1) (((eccCodeRateIndex)<<FLASH_READ_ECCCODERATEINDEX_LSB )|((maxIter)<<FLASH_READ_MAXITER_LSB )|((LLR0)<<FLASH_READ_LLR0_LSB )|((LLR1)<<FLASH_READ_LLR1_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_READ
*/
#define FLASH_READ_DW9-(scramblerSeed,readRetry,numPlane,dfBuffOperation,blockType) (((scramblerSeed)<<FLASH_READ_SCRAMBLERSEED_LSB )|((readRetry)<<FLASH_READ_READRETRY_LSB )|((numPlane)<<FLASH_READ_NUMPLANE_LSB )|((dfBuffOperation)<<FLASH_READ_DFBUFFOPERATION_LSB )|((blockType)<<FLASH_READ_BLOCKTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_READ
*/
#define FLASH_READ_DW10-(pageReadTime,readHdrCount) (((pageReadTime)<<FLASH_READ_PAGEREADTIME_LSB )|((readHdrCount)<<FLASH_READ_READHDRCOUNT_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_READ
*/
#define FLASH_READ_DW11-(firstDFOffset,dataFrameLength) (((firstDFOffset)<<FLASH_READ_FIRSTDFOFFSET_LSB )|((dataFrameLength)<<FLASH_READ_DATAFRAMELENGTH_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_READ
*/
#define FLASH_READ_DW12-(rawBuffer) (((rawBuffer)<<FLASH_READ_RAWBUFFER_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_READ
*/
#define FLASH_READ_DW13-(readHeader0) (((readHeader0)<<FLASH_READ_READHEADER0_LSB ))    
                  
/** 
* @brief Macro to create dword14 for message FLASH_READ
*/
#define FLASH_READ_DW14-(dataFrameBuffer0) (((dataFrameBuffer0)<<FLASH_READ_DATAFRAMEBUFFER0_LSB ))    
                  
/** 
* @brief Macro to create dword15 for message FLASH_READ
*/
#define FLASH_READ_DW15-(readMsgDW15) (((readMsgDW15)<<FLASH_READ_READMSGDW15_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW0+(cntxt,chan,xorCalcID,xorCalcStripeLast,xorCalcOp) (((msgType)<<FLASH_WRITE_MSGTYPE_LSB )|((cntxt)<<FLASH_WRITE_CNTXT_LSB )|((chan)<<FLASH_WRITE_CHAN_LSB )|((xorCalcID)<<FLASH_WRITE_XORCALCID_LSB )|((xorCalcStripeLast)<<FLASH_WRITE_XORCALCSTRIPELAST_LSB )|((xorCalcOp)<<FLASH_WRITE_XORCALCOP_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_WRITE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_WRITE_CHAIN_LSB )|((outMsgQ)<<FLASH_WRITE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW8-(eccCodeRateIndex) (((eccCodeRateIndex)<<FLASH_WRITE_ECCCODERATEINDEX_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW9-(scramblerSeed,numPlane,dfBuffOperation,blockType) (((scramblerSeed)<<FLASH_WRITE_SCRAMBLERSEED_LSB )|((numPlane)<<FLASH_WRITE_NUMPLANE_LSB )|((dfBuffOperation)<<FLASH_WRITE_DFBUFFOPERATION_LSB )|((blockType)<<FLASH_WRITE_BLOCKTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW10-(pageProgTime,writeHdrCount) (((pageProgTime)<<FLASH_WRITE_PAGEPROGTIME_LSB )|((writeHdrCount)<<FLASH_WRITE_WRITEHDRCOUNT_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW11-(firstDFOffset,dataFrameLength) (((firstDFOffset)<<FLASH_WRITE_FIRSTDFOFFSET_LSB )|((dataFrameLength)<<FLASH_WRITE_DATAFRAMELENGTH_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW12-(writeHeader0) (((writeHeader0)<<FLASH_WRITE_WRITEHEADER0_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW13-(dataFrameBuffType) (((dataFrameBuffType)<<FLASH_WRITE_DATAFRAMEBUFFTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword14 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW14-(dataFrameBuffAddr) (((dataFrameBuffAddr)<<FLASH_WRITE_DATAFRAMEBUFFADDR_LSB ))    
                  
/** 
* @brief Macro to create dword15 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW15-(writeMsgDW15) (((writeMsgDW15)<<FLASH_WRITE_WRITEMSGDW15_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_CONT
*/
#define FLASH_CONT_DW0+(cntxt,chan) (((msgType)<<FLASH_CONT_MSGTYPE_LSB )|((cntxt)<<FLASH_CONT_CNTXT_LSB )|((chan)<<FLASH_CONT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_CONT
*/
#define FLASH_CONT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_CONT_CHMSGNODEADDR_LSB )|((chain)<<FLASH_CONT_CHAIN_LSB )|((outMsgQ)<<FLASH_CONT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW0+(cntxt,chan) (((msgType)<<FLASH_ERASE_MSGTYPE_LSB )|((cntxt)<<FLASH_ERASE_CNTXT_LSB )|((chan)<<FLASH_ERASE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_ERASE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_ERASE_CHAIN_LSB )|((outMsgQ)<<FLASH_ERASE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW8 ()    
                  
/** 
* @brief Macro to create dword9 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW9-(numPlane,blockType) (((numPlane)<<FLASH_ERASE_NUMPLANE_LSB )|((blockType)<<FLASH_ERASE_BLOCKTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW10-(blockEraseTime) (((blockEraseTime)<<FLASH_ERASE_BLOCKERASETIME_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message DATA_FRAME_BUFF_TYPE
*/
#define DATA_FRAME_BUFF_TYPE_DW0+(dfBuffType0,dfBuffType1,dfBuffType2,dfBuffType3,dfBuffType4,dfBuffType5,dfBuffType6,dfBuffType7,dfBuffType8,numBuffTypes) (((dfBuffType0)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE0_LSB )|((dfBuffType1)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE1_LSB )|((dfBuffType2)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE2_LSB )|((dfBuffType3)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE3_LSB )|((dfBuffType4)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE4_LSB )|((dfBuffType5)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE5_LSB )|((dfBuffType6)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE6_LSB )|((dfBuffType7)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE7_LSB )|((dfBuffType8)<<DATA_FRAME_BUFF_TYPE_DFBUFFTYPE8_LSB )|((numBuffTypes)<<DATA_FRAME_BUFF_TYPE_NUMBUFFTYPES_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW0+(outMsgQ,status,erasedPage,planeNum,retries) (((msgType)<<FLASH_OP_CPL_MSGTYPE_LSB )|((outMsgQ)<<FLASH_OP_CPL_OUTMSGQ_LSB )|((status)<<FLASH_OP_CPL_STATUS_LSB )|((erasedPage)<<FLASH_OP_CPL_ERASEDPAGE_LSB )|((planeNum)<<FLASH_OP_CPL_PLANENUM_LSB )|((retries)<<FLASH_OP_CPL_RETRIES_LSB ))    
                  
/** 
* @brief Macro to create dword3 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW3-(planeCplInfo) (((planeCplInfo)<<FLASH_OP_CPL_PLANECPLINFO_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW4-(eccChunkErrVector,planeMaxZErrM,maxZErrMChunkNum,planeTotalZErrM) (((eccChunkErrVector)<<FLASH_OP_CPL_ECCCHUNKERRVECTOR_LSB )|((planeMaxZErrM)<<FLASH_OP_CPL_PLANEMAXZERRM_LSB )|((maxZErrMChunkNum)<<FLASH_OP_CPL_MAXZERRMCHUNKNUM_LSB )|((planeTotalZErrM)<<FLASH_OP_CPL_PLANETOTALZERRM_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW5-(dataFrameBuffType) (((dataFrameBuffType)<<FLASH_OP_CPL_DATAFRAMEBUFFTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_RD_PLANE_CPL_INFO
*/
#define FLASH_RD_PLANE_CPL_INFO_DW0+(planeMaxEccErrors,maxErrorChunkNum,planeTotalEccErrors) (((planeMaxEccErrors)<<FLASH_RD_PLANE_CPL_INFO_PLANEMAXECCERRORS_LSB )|((maxErrorChunkNum)<<FLASH_RD_PLANE_CPL_INFO_MAXERRORCHUNKNUM_LSB )|((planeTotalEccErrors)<<FLASH_RD_PLANE_CPL_INFO_PLANETOTALECCERRORS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_WR_ER_PLANE_CPL_INFO
*/
#define FLASH_WR_ER_PLANE_CPL_INFO_DW0+(plane0status,plane1status,plane2status,plane3status) (((plane0status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE0STATUS_LSB )|((plane1status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE1STATUS_LSB )|((plane2status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE2STATUS_LSB )|((plane3status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE3STATUS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_OP_CPL_CONT
*/
#define FLASH_OP_CPL_CONT_DW0+(outMsgQ,planeNum) (((msgType)<<FLASH_OP_CPL_CONT_MSGTYPE_LSB )|((outMsgQ)<<FLASH_OP_CPL_CONT_OUTMSGQ_LSB )|((planeNum)<<FLASH_OP_CPL_CONT_PLANENUM_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW0+(numDwords) (((msgType)<<FLASH_MEM_WRITE_MSGTYPE_LSB )|((numDwords)<<FLASH_MEM_WRITE_NUMDWORDS_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW1-(multicastVector) (((multicastVector)<<FLASH_MEM_WRITE_MULTICASTVECTOR_LSB ))    
                  
/** 
* @brief Macro to create dword2 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW2-(flashChProcAddr) (((flashChProcAddr)<<FLASH_MEM_WRITE_FLASHCHPROCADDR_LSB ))    
                  
/** 
* @brief Macro to create dword3 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW3-(dataDWord0) (((dataDWord0)<<FLASH_MEM_WRITE_DATADWORD0_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW4-(dataDWord1) (((dataDWord1)<<FLASH_MEM_WRITE_DATADWORD1_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW5-(dataDWord2) (((dataDWord2)<<FLASH_MEM_WRITE_DATADWORD2_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW6-(dataDWord3) (((dataDWord3)<<FLASH_MEM_WRITE_DATADWORD3_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW7-(dataDWord4) (((dataDWord4)<<FLASH_MEM_WRITE_DATADWORD4_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW8-(dataDWord5) (((dataDWord5)<<FLASH_MEM_WRITE_DATADWORD5_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW9-(dataDWord6) (((dataDWord6)<<FLASH_MEM_WRITE_DATADWORD6_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW10-(dataDWord7) (((dataDWord7)<<FLASH_MEM_WRITE_DATADWORD7_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW11-(dataDWord8) (((dataDWord8)<<FLASH_MEM_WRITE_DATADWORD8_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW12-(dataDWord9) (((dataDWord9)<<FLASH_MEM_WRITE_DATADWORD9_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW13-(dataDWord10) (((dataDWord10)<<FLASH_MEM_WRITE_DATADWORD10_LSB ))    
                  
/** 
* @brief Macro to create dword14 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW14-(dataDWord11) (((dataDWord11)<<FLASH_MEM_WRITE_DATADWORD11_LSB ))    
                  
/** 
* @brief Macro to create dword15 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW15 ()    
                  
/** 
* @brief Macro to create dword0 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW0+(cntxt,chan) (((msgType)<<FLASH_READ_PARAMETER_PAGE_MSGTYPE_LSB )|((cntxt)<<FLASH_READ_PARAMETER_PAGE_CNTXT_LSB )|((chan)<<FLASH_READ_PARAMETER_PAGE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_READ_PARAMETER_PAGE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_READ_PARAMETER_PAGE_CHAIN_LSB )|((outMsgQ)<<FLASH_READ_PARAMETER_PAGE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW4-(Address,pageReadTime) (((Address)<<FLASH_READ_PARAMETER_PAGE_ADDRESS_LSB )|((pageReadTime)<<FLASH_READ_PARAMETER_PAGE_PAGEREADTIME_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW5-(dfBuffOperation) (((dfBuffOperation)<<FLASH_READ_PARAMETER_PAGE_DFBUFFOPERATION_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW6-(startOffset,dataFrameLength) (((startOffset)<<FLASH_READ_PARAMETER_PAGE_STARTOFFSET_LSB )|((dataFrameLength)<<FLASH_READ_PARAMETER_PAGE_DATAFRAMELENGTH_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW7-(dataFrameBuffer) (((dataFrameBuffer)<<FLASH_READ_PARAMETER_PAGE_DATAFRAMEBUFFER_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_READ_ID
*/
#define FLASH_READ_ID_DW0+(cntxt,chan) (((msgType)<<FLASH_READ_ID_MSGTYPE_LSB )|((cntxt)<<FLASH_READ_ID_CNTXT_LSB )|((chan)<<FLASH_READ_ID_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_READ_ID
*/
#define FLASH_READ_ID_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_READ_ID_CHMSGNODEADDR_LSB )|((chain)<<FLASH_READ_ID_CHAIN_LSB )|((outMsgQ)<<FLASH_READ_ID_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_READ_ID
*/
#define FLASH_READ_ID_DW4-(Address) (((Address)<<FLASH_READ_ID_ADDRESS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_OP_CPL_DATA
*/
#define FLASH_OP_CPL_DATA_DW0+(outMsgQ,size,status) (((msgType)<<FLASH_OP_CPL_DATA_MSGTYPE_LSB )|((outMsgQ)<<FLASH_OP_CPL_DATA_OUTMSGQ_LSB )|((size)<<FLASH_OP_CPL_DATA_SIZE_LSB )|((status)<<FLASH_OP_CPL_DATA_STATUS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW0+(cntxt,chan) (((msgType)<<FLASH_SET_FEAT_MSGTYPE_LSB )|((cntxt)<<FLASH_SET_FEAT_CNTXT_LSB )|((chan)<<FLASH_SET_FEAT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_SET_FEAT_CHMSGNODEADDR_LSB )|((chain)<<FLASH_SET_FEAT_CHAIN_LSB )|((outMsgQ)<<FLASH_SET_FEAT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW4-(address) (((address)<<FLASH_SET_FEAT_ADDRESS_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW5-(parameters) (((parameters)<<FLASH_SET_FEAT_PARAMETERS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_GET_FEAT
*/
#define FLASH_GET_FEAT_DW0+(cntxt,chan) (((msgType)<<FLASH_GET_FEAT_MSGTYPE_LSB )|((cntxt)<<FLASH_GET_FEAT_CNTXT_LSB )|((chan)<<FLASH_GET_FEAT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_GET_FEAT
*/
#define FLASH_GET_FEAT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_GET_FEAT_CHMSGNODEADDR_LSB )|((chain)<<FLASH_GET_FEAT_CHAIN_LSB )|((outMsgQ)<<FLASH_GET_FEAT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_GET_FEAT
*/
#define FLASH_GET_FEAT_DW4-(address) (((address)<<FLASH_GET_FEAT_ADDRESS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_ADDR_FORMAT
*/
#define FLASH_ADDR_FORMAT_DW0+(pageNum,blockNum,lunNum) (((pageNum)<<FLASH_ADDR_FORMAT_PAGENUM_LSB )|((blockNum)<<FLASH_ADDR_FORMAT_BLOCKNUM_LSB )|((lunNum)<<FLASH_ADDR_FORMAT_LUNNUM_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_CHANNEL_CONFIG_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_CHANNEL_CONFIG_UPDATE_CNTXT_LSB )|((chan)<<FLASH_CHANNEL_CONFIG_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_CHANNEL_CONFIG_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_CHANNEL_CONFIG_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_CHANNEL_CONFIG_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW4-(subMsgType,numContext,numLun,lunBitPosition) (((subMsgType)<<FLASH_CHANNEL_CONFIG_UPDATE_SUBMSGTYPE_LSB )|((numContext)<<FLASH_CHANNEL_CONFIG_UPDATE_NUMCONTEXT_LSB )|((numLun)<<FLASH_CHANNEL_CONFIG_UPDATE_NUMLUN_LSB )|((lunBitPosition)<<FLASH_CHANNEL_CONFIG_UPDATE_LUNBITPOSITION_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW5-(pageSize) (((pageSize)<<FLASH_CHANNEL_CONFIG_UPDATE_PAGESIZE_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW6-(_1stContext,_1stContextCE,_1stContextLun,_2ndContext,_2ndContextCE,_2ndContextLun) (((_1stContext)<<FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXT_LSB )|((_1stContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTCE_LSB )|((_1stContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTLUN_LSB )|((_2ndContext)<<FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXT_LSB )|((_2ndContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTCE_LSB )|((_2ndContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW7-(_3rdContext,_3rdContextCE,_3rdContextLun,_4thContext,_4thContextCE,_4thContextLun) (((_3rdContext)<<FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXT_LSB )|((_3rdContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTCE_LSB )|((_3rdContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTLUN_LSB )|((_4thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXT_LSB )|((_4thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTCE_LSB )|((_4thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW8-(_5thContext,_5thContextCE,_5thContextLun,_6thContext,_6thContextCE,_6thContextLun) (((_5thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXT_LSB )|((_5thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTCE_LSB )|((_5thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTLUN_LSB )|((_6thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXT_LSB )|((_6thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTCE_LSB )|((_6thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW9-(_7thContext,_7thContextCE,_7thContextLun,_8thContext,_8thContextCE,_8thContextLun) (((_7thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXT_LSB )|((_7thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTCE_LSB )|((_7thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTLUN_LSB )|((_8thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXT_LSB )|((_8thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTCE_LSB )|((_8thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW10-(_9thContext,_9thContextCE,_9thContextLun,_10thContext,_10thContextCE,_10thContextLun) (((_9thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXT_LSB )|((_9thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTCE_LSB )|((_9thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTLUN_LSB )|((_10thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXT_LSB )|((_10thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTCE_LSB )|((_10thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW11-(_11thContext,_11thContextCE,_11thContextLun,_12thContext,_12thContextCE,_12thContextLun) (((_11thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXT_LSB )|((_11thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTCE_LSB )|((_11thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTLUN_LSB )|((_12thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXT_LSB )|((_12thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTCE_LSB )|((_12thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW12-(_13thContext,_13thContextCE,_13thContextLun,_14thContext,_14thContextCE,_14thContextLun) (((_13thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXT_LSB )|((_13thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTCE_LSB )|((_13thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTLUN_LSB )|((_14thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXT_LSB )|((_14thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTCE_LSB )|((_14thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_CHANNEL_CONFIG_UPDATE
*/
#define FLASH_CHANNEL_CONFIG_UPDATE_DW13-(_15thContext,_15thContextCE,_15thContextLun,_16thContext,_16thContextCE,_16thContextLun) (((_15thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXT_LSB )|((_15thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTCE_LSB )|((_15thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTLUN_LSB )|((_16thContext)<<FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXT_LSB )|((_16thContextCE)<<FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTCE_LSB )|((_16thContextLun)<<FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTLUN_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_ECC_CONTEXT_INFO_UPDATE
*/
#define FLASH_ECC_CONTEXT_INFO_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_ECC_CONTEXT_INFO_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CNTXT_LSB )|((chan)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_ECC_CONTEXT_INFO_UPDATE
*/
#define FLASH_ECC_CONTEXT_INFO_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_ECC_CONTEXT_INFO_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_ECC_CONTEXT_INFO_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_ECC_CONTEXT_INFO_UPDATE
*/
#define FLASH_ECC_CONTEXT_INFO_UPDATE_DW4-(subMsgType,numEntries) (((subMsgType)<<FLASH_ECC_CONTEXT_INFO_UPDATE_SUBMSGTYPE_LSB )|((numEntries)<<FLASH_ECC_CONTEXT_INFO_UPDATE_NUMENTRIES_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message ECC_CONTEXT_DATA
*/
#define ECC_CONTEXT_DATA_DW0+(eccContextNum,eccChunkSize,protectedDataSize) (((eccContextNum)<<ECC_CONTEXT_DATA_ECCCONTEXTNUM_LSB )|((eccChunkSize)<<ECC_CONTEXT_DATA_ECCCHUNKSIZE_LSB )|((protectedDataSize)<<ECC_CONTEXT_DATA_PROTECTEDDATASIZE_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_TIMING_PARAM_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_TIMING_PARAM_UPDATE_CNTXT_LSB )|((chan)<<FLASH_TIMING_PARAM_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_TIMING_PARAM_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_TIMING_PARAM_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_TIMING_PARAM_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW4-(subMsgType,timeSel) (((subMsgType)<<FLASH_TIMING_PARAM_UPDATE_SUBMSGTYPE_LSB )|((timeSel)<<FLASH_TIMING_PARAM_UPDATE_TIMESEL_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW5-(dummyBusyTime,clkHigh2RBLowTime) (((dummyBusyTime)<<FLASH_TIMING_PARAM_UPDATE_DUMMYBUSYTIME_LSB )|((clkHigh2RBLowTime)<<FLASH_TIMING_PARAM_UPDATE_CLKHIGH2RBLOWTIME_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW6-(resetTime) (((resetTime)<<FLASH_TIMING_PARAM_UPDATE_RESETTIME_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW7-(powerOnRstTime) (((powerOnRstTime)<<FLASH_TIMING_PARAM_UPDATE_POWERONRSTTIME_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW8-(interfaceChangeTime) (((interfaceChangeTime)<<FLASH_TIMING_PARAM_UPDATE_INTERFACECHANGETIME_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW9-(featureTime) (((featureTime)<<FLASH_TIMING_PARAM_UPDATE_FEATURETIME_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW10-(rdPollTime,wrPollTime) (((rdPollTime)<<FLASH_TIMING_PARAM_UPDATE_RDPOLLTIME_LSB )|((wrPollTime)<<FLASH_TIMING_PARAM_UPDATE_WRPOLLTIME_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW11-(berPollTime,miscPollTime) (((berPollTime)<<FLASH_TIMING_PARAM_UPDATE_BERPOLLTIME_LSB )|((miscPollTime)<<FLASH_TIMING_PARAM_UPDATE_MISCPOLLTIME_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_TIMING_PARAM_UPDATE
*/
#define FLASH_TIMING_PARAM_UPDATE_DW12-(maxPollCount) (((maxPollCount)<<FLASH_TIMING_PARAM_UPDATE_MAXPOLLCOUNT_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_POWER_CREDIT_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_POWER_CREDIT_UPDATE_CNTXT_LSB )|((chan)<<FLASH_POWER_CREDIT_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_POWER_CREDIT_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_POWER_CREDIT_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_POWER_CREDIT_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW4-(subMsgType) (((subMsgType)<<FLASH_POWER_CREDIT_UPDATE_SUBMSGTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW5-(readPowerCredit,programPowerCredit) (((readPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_READPOWERCREDIT_LSB )|((programPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_PROGRAMPOWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_POWER_CREDIT_UPDATE
*/
#define FLASH_POWER_CREDIT_UPDATE_DW6-(erasePowerCredit,miscPowerCredit) (((erasePowerCredit)<<FLASH_POWER_CREDIT_UPDATE_ERASEPOWERCREDIT_LSB )|((miscPowerCredit)<<FLASH_POWER_CREDIT_UPDATE_MISCPOWERCREDIT_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW0+(cntxt,chan) (((msgType)<<FLASH_DYNAMIC_UPDATE_MSGTYPE_LSB )|((cntxt)<<FLASH_DYNAMIC_UPDATE_CNTXT_LSB )|((chan)<<FLASH_DYNAMIC_UPDATE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_DYNAMIC_UPDATE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_DYNAMIC_UPDATE_CHAIN_LSB )|((outMsgQ)<<FLASH_DYNAMIC_UPDATE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW4-(subMsgType) (((subMsgType)<<FLASH_DYNAMIC_UPDATE_SUBMSGTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_DYNAMIC_UPDATE
*/
#define FLASH_DYNAMIC_UPDATE_DW5-(highPriorPollLimit) (((highPriorPollLimit)<<FLASH_DYNAMIC_UPDATE_HIGHPRIORPOLLLIMIT_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message READ_HEADER
*/
#define READ_HEADER_DW0+(startECCChunk,numECCHeaders,pageOffset) (((startECCChunk)<<READ_HEADER_STARTECCCHUNK_LSB )|((numECCHeaders)<<READ_HEADER_NUMECCHEADERS_LSB )|((pageOffset)<<READ_HEADER_PAGEOFFSET_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message E_C_C CODE RATE
*/
#define E_C_C CODE RATE_DW0+(planeNum,numBuffers,numECCChunk,lastBufferSpans,sizeECCChunk,sizeProtData) (((planeNum)<<E_C_C CODE RATE_PLANENUM_LSB )|((numBuffers)<<E_C_C CODE RATE_NUMBUFFERS_LSB )|((numECCChunk)<<E_C_C CODE RATE_NUMECCCHUNK_LSB )|((lastBufferSpans)<<E_C_C CODE RATE_LASTBUFFERSPANS_LSB )|((sizeECCChunk)<<E_C_C CODE RATE_SIZEECCCHUNK_LSB )|((sizeProtData)<<E_C_C CODE RATE_SIZEPROTDATA_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message WRITE_HEADER
*/
#define WRITE_HEADER_DW0+(planeNum,numBuffers,numECCChunk,startECCChunk,sizeECCChunk,sizeProtData) (((planeNum)<<WRITE_HEADER_PLANENUM_LSB )|((numBuffers)<<WRITE_HEADER_NUMBUFFERS_LSB )|((numECCChunk)<<WRITE_HEADER_NUMECCCHUNK_LSB )|((startECCChunk)<<WRITE_HEADER_STARTECCCHUNK_LSB )|((sizeECCChunk)<<WRITE_HEADER_SIZEECCCHUNK_LSB )|((sizeProtData)<<WRITE_HEADER_SIZEPROTDATA_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_READ
*/
#define FLASH_READ_DW0+(cntxt,chan) (((msgType)<<FLASH_READ_MSGTYPE_LSB )|((cntxt)<<FLASH_READ_CNTXT_LSB )|((chan)<<FLASH_READ_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_READ
*/
#define FLASH_READ_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_READ_CHMSGNODEADDR_LSB )|((chain)<<FLASH_READ_CHAIN_LSB )|((outMsgQ)<<FLASH_READ_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_READ
*/
#define FLASH_READ_DW6-(eccCodeRateIndex,maxIter,LLR0,LLR1) (((eccCodeRateIndex)<<FLASH_READ_ECCCODERATEINDEX_LSB )|((maxIter)<<FLASH_READ_MAXITER_LSB )|((LLR0)<<FLASH_READ_LLR0_LSB )|((LLR1)<<FLASH_READ_LLR1_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_READ
*/
#define FLASH_READ_DW7-(scramblerSeed,readRetry,numPlane,dfBuffOperation,blockType) (((scramblerSeed)<<FLASH_READ_SCRAMBLERSEED_LSB )|((readRetry)<<FLASH_READ_READRETRY_LSB )|((numPlane)<<FLASH_READ_NUMPLANE_LSB )|((dfBuffOperation)<<FLASH_READ_DFBUFFOPERATION_LSB )|((blockType)<<FLASH_READ_BLOCKTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_READ
*/
#define FLASH_READ_DW8-(pageReadTime,readHdrCount) (((pageReadTime)<<FLASH_READ_PAGEREADTIME_LSB )|((readHdrCount)<<FLASH_READ_READHDRCOUNT_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_READ
*/
#define FLASH_READ_DW9-(firstDFOffset,dataFrameLength) (((firstDFOffset)<<FLASH_READ_FIRSTDFOFFSET_LSB )|((dataFrameLength)<<FLASH_READ_DATAFRAMELENGTH_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_READ
*/
#define FLASH_READ_DW10-(rawBuffer) (((rawBuffer)<<FLASH_READ_RAWBUFFER_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_READ
*/
#define FLASH_READ_DW11-(readHeader0) (((readHeader0)<<FLASH_READ_READHEADER0_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_READ
*/
#define FLASH_READ_DW12-(eccHeader0) (((eccHeader0)<<FLASH_READ_ECCHEADER0_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_READ
*/
#define FLASH_READ_DW13-(dataFrameBuffer0) (((dataFrameBuffer0)<<FLASH_READ_DATAFRAMEBUFFER0_LSB ))    
                  
/** 
* @brief Macro to create dword14 for message FLASH_READ
*/
#define FLASH_READ_DW14-(readMsgDW14) (((readMsgDW14)<<FLASH_READ_READMSGDW14_LSB ))    
                  
/** 
* @brief Macro to create dword15 for message FLASH_READ
*/
#define FLASH_READ_DW15-(readMsgDW15) (((readMsgDW15)<<FLASH_READ_READMSGDW15_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW0+(cntxt,chan,xorCalcID,xorCalcStripeLast,xorCalcOp) (((msgType)<<FLASH_WRITE_MSGTYPE_LSB )|((cntxt)<<FLASH_WRITE_CNTXT_LSB )|((chan)<<FLASH_WRITE_CHAN_LSB )|((xorCalcID)<<FLASH_WRITE_XORCALCID_LSB )|((xorCalcStripeLast)<<FLASH_WRITE_XORCALCSTRIPELAST_LSB )|((xorCalcOp)<<FLASH_WRITE_XORCALCOP_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_WRITE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_WRITE_CHAIN_LSB )|((outMsgQ)<<FLASH_WRITE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW6-(eccCodeRateIndex) (((eccCodeRateIndex)<<FLASH_WRITE_ECCCODERATEINDEX_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW7-(scramblerSeed,numPlane,dfBuffOperation,blockType) (((scramblerSeed)<<FLASH_WRITE_SCRAMBLERSEED_LSB )|((numPlane)<<FLASH_WRITE_NUMPLANE_LSB )|((dfBuffOperation)<<FLASH_WRITE_DFBUFFOPERATION_LSB )|((blockType)<<FLASH_WRITE_BLOCKTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW8-(pageProgTime,writeHdrCount) (((pageProgTime)<<FLASH_WRITE_PAGEPROGTIME_LSB )|((writeHdrCount)<<FLASH_WRITE_WRITEHDRCOUNT_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW9-(firstDFOffset,dataFrameLength) (((firstDFOffset)<<FLASH_WRITE_FIRSTDFOFFSET_LSB )|((dataFrameLength)<<FLASH_WRITE_DATAFRAMELENGTH_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW10-(writeHeader0) (((writeHeader0)<<FLASH_WRITE_WRITEHEADER0_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW11-(dataFrameBuffer0) (((dataFrameBuffer0)<<FLASH_WRITE_DATAFRAMEBUFFER0_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW12-(writeMsgDW12) (((writeMsgDW12)<<FLASH_WRITE_WRITEMSGDW12_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW13-(writeMsgDW13) (((writeMsgDW13)<<FLASH_WRITE_WRITEMSGDW13_LSB ))    
                  
/** 
* @brief Macro to create dword14 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW14-(writeMsgDW14) (((writeMsgDW14)<<FLASH_WRITE_WRITEMSGDW14_LSB ))    
                  
/** 
* @brief Macro to create dword15 for message FLASH_WRITE
*/
#define FLASH_WRITE_DW15-(writeMsgDW15) (((writeMsgDW15)<<FLASH_WRITE_WRITEMSGDW15_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_CONT
*/
#define FLASH_CONT_DW0+(cntxt,chan) (((msgType)<<FLASH_CONT_MSGTYPE_LSB )|((cntxt)<<FLASH_CONT_CNTXT_LSB )|((chan)<<FLASH_CONT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_CONT
*/
#define FLASH_CONT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_CONT_CHMSGNODEADDR_LSB )|((chain)<<FLASH_CONT_CHAIN_LSB )|((outMsgQ)<<FLASH_CONT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW0+(cntxt,chan) (((msgType)<<FLASH_ERASE_MSGTYPE_LSB )|((cntxt)<<FLASH_ERASE_CNTXT_LSB )|((chan)<<FLASH_ERASE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_ERASE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_ERASE_CHAIN_LSB )|((outMsgQ)<<FLASH_ERASE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW6 ()    
                  
/** 
* @brief Macro to create dword7 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW7-(numPlane,blockType) (((numPlane)<<FLASH_ERASE_NUMPLANE_LSB )|((blockType)<<FLASH_ERASE_BLOCKTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_ERASE
*/
#define FLASH_ERASE_DW8-(blockEraseTime) (((blockEraseTime)<<FLASH_ERASE_BLOCKERASETIME_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW0+(outMsgQ,status,erasedPage,planeNum,retries) (((msgType)<<FLASH_OP_CPL_MSGTYPE_LSB )|((outMsgQ)<<FLASH_OP_CPL_OUTMSGQ_LSB )|((status)<<FLASH_OP_CPL_STATUS_LSB )|((erasedPage)<<FLASH_OP_CPL_ERASEDPAGE_LSB )|((planeNum)<<FLASH_OP_CPL_PLANENUM_LSB )|((retries)<<FLASH_OP_CPL_RETRIES_LSB ))    
                  
/** 
* @brief Macro to create dword3 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW3-(planeCplInfo) (((planeCplInfo)<<FLASH_OP_CPL_PLANECPLINFO_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW4-(eccChunkErrVector,planeMaxZErrM,maxZErrMChunkNum,planeTotalZErrM) (((eccChunkErrVector)<<FLASH_OP_CPL_ECCCHUNKERRVECTOR_LSB )|((planeMaxZErrM)<<FLASH_OP_CPL_PLANEMAXZERRM_LSB )|((maxZErrMChunkNum)<<FLASH_OP_CPL_MAXZERRMCHUNKNUM_LSB )|((planeTotalZErrM)<<FLASH_OP_CPL_PLANETOTALZERRM_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_OP_CPL
*/
#define FLASH_OP_CPL_DW5-(dataFrameBuffType) (((dataFrameBuffType)<<FLASH_OP_CPL_DATAFRAMEBUFFTYPE_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_RD_PLANE_CPL_INFO
*/
#define FLASH_RD_PLANE_CPL_INFO_DW0+(planeMaxEccErrors,maxErrorChunkNum,planeTotalEccErrors) (((planeMaxEccErrors)<<FLASH_RD_PLANE_CPL_INFO_PLANEMAXECCERRORS_LSB )|((maxErrorChunkNum)<<FLASH_RD_PLANE_CPL_INFO_MAXERRORCHUNKNUM_LSB )|((planeTotalEccErrors)<<FLASH_RD_PLANE_CPL_INFO_PLANETOTALECCERRORS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_WR_ER_PLANE_CPL_INFO
*/
#define FLASH_WR_ER_PLANE_CPL_INFO_DW0+(plane0status,plane1status,plane2status,plane3status) (((plane0status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE0STATUS_LSB )|((plane1status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE1STATUS_LSB )|((plane2status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE2STATUS_LSB )|((plane3status)<<FLASH_WR_ER_PLANE_CPL_INFO_PLANE3STATUS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_OP_CPL_CONT
*/
#define FLASH_OP_CPL_CONT_DW0+(outMsgQ,planeNum) (((msgType)<<FLASH_OP_CPL_CONT_MSGTYPE_LSB )|((outMsgQ)<<FLASH_OP_CPL_CONT_OUTMSGQ_LSB )|((planeNum)<<FLASH_OP_CPL_CONT_PLANENUM_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW0+(numDwords) (((msgType)<<FLASH_MEM_WRITE_MSGTYPE_LSB )|((numDwords)<<FLASH_MEM_WRITE_NUMDWORDS_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW1-(multicastVector) (((multicastVector)<<FLASH_MEM_WRITE_MULTICASTVECTOR_LSB ))    
                  
/** 
* @brief Macro to create dword2 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW2-(flashChProcAddr) (((flashChProcAddr)<<FLASH_MEM_WRITE_FLASHCHPROCADDR_LSB ))    
                  
/** 
* @brief Macro to create dword3 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW3-(dataDWord0) (((dataDWord0)<<FLASH_MEM_WRITE_DATADWORD0_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW4-(dataDWord1) (((dataDWord1)<<FLASH_MEM_WRITE_DATADWORD1_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW5-(dataDWord2) (((dataDWord2)<<FLASH_MEM_WRITE_DATADWORD2_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW6-(dataDWord3) (((dataDWord3)<<FLASH_MEM_WRITE_DATADWORD3_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW7-(dataDWord4) (((dataDWord4)<<FLASH_MEM_WRITE_DATADWORD4_LSB ))    
                  
/** 
* @brief Macro to create dword8 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW8-(dataDWord5) (((dataDWord5)<<FLASH_MEM_WRITE_DATADWORD5_LSB ))    
                  
/** 
* @brief Macro to create dword9 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW9-(dataDWord6) (((dataDWord6)<<FLASH_MEM_WRITE_DATADWORD6_LSB ))    
                  
/** 
* @brief Macro to create dword10 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW10-(dataDWord7) (((dataDWord7)<<FLASH_MEM_WRITE_DATADWORD7_LSB ))    
                  
/** 
* @brief Macro to create dword11 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW11-(dataDWord8) (((dataDWord8)<<FLASH_MEM_WRITE_DATADWORD8_LSB ))    
                  
/** 
* @brief Macro to create dword12 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW12-(dataDWord9) (((dataDWord9)<<FLASH_MEM_WRITE_DATADWORD9_LSB ))    
                  
/** 
* @brief Macro to create dword13 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW13-(dataDWord10) (((dataDWord10)<<FLASH_MEM_WRITE_DATADWORD10_LSB ))    
                  
/** 
* @brief Macro to create dword14 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW14-(dataDWord11) (((dataDWord11)<<FLASH_MEM_WRITE_DATADWORD11_LSB ))    
                  
/** 
* @brief Macro to create dword15 for message FLASH_MEM_WRITE
*/
#define FLASH_MEM_WRITE_DW15 ()    
                  
/** 
* @brief Macro to create dword0 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW0+(cntxt,chan) (((msgType)<<FLASH_READ_PARAMETER_PAGE_MSGTYPE_LSB )|((cntxt)<<FLASH_READ_PARAMETER_PAGE_CNTXT_LSB )|((chan)<<FLASH_READ_PARAMETER_PAGE_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_READ_PARAMETER_PAGE_CHMSGNODEADDR_LSB )|((chain)<<FLASH_READ_PARAMETER_PAGE_CHAIN_LSB )|((outMsgQ)<<FLASH_READ_PARAMETER_PAGE_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW4-(Address,pageReadTime) (((Address)<<FLASH_READ_PARAMETER_PAGE_ADDRESS_LSB )|((pageReadTime)<<FLASH_READ_PARAMETER_PAGE_PAGEREADTIME_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW5-(dfBuffOperation) (((dfBuffOperation)<<FLASH_READ_PARAMETER_PAGE_DFBUFFOPERATION_LSB ))    
                  
/** 
* @brief Macro to create dword6 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW6-(startOffset,dataFrameLength) (((startOffset)<<FLASH_READ_PARAMETER_PAGE_STARTOFFSET_LSB )|((dataFrameLength)<<FLASH_READ_PARAMETER_PAGE_DATAFRAMELENGTH_LSB ))    
                  
/** 
* @brief Macro to create dword7 for message FLASH_READ_PARAMETER_PAGE
*/
#define FLASH_READ_PARAMETER_PAGE_DW7-(dataFrameBuffer) (((dataFrameBuffer)<<FLASH_READ_PARAMETER_PAGE_DATAFRAMEBUFFER_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_READ_ID
*/
#define FLASH_READ_ID_DW0+(cntxt,chan) (((msgType)<<FLASH_READ_ID_MSGTYPE_LSB )|((cntxt)<<FLASH_READ_ID_CNTXT_LSB )|((chan)<<FLASH_READ_ID_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_READ_ID
*/
#define FLASH_READ_ID_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_READ_ID_CHMSGNODEADDR_LSB )|((chain)<<FLASH_READ_ID_CHAIN_LSB )|((outMsgQ)<<FLASH_READ_ID_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_READ_ID
*/
#define FLASH_READ_ID_DW4-(Address) (((Address)<<FLASH_READ_ID_ADDRESS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_OP_CPL_DATA
*/
#define FLASH_OP_CPL_DATA_DW0+(outMsgQ,size,status) (((msgType)<<FLASH_OP_CPL_DATA_MSGTYPE_LSB )|((outMsgQ)<<FLASH_OP_CPL_DATA_OUTMSGQ_LSB )|((size)<<FLASH_OP_CPL_DATA_SIZE_LSB )|((status)<<FLASH_OP_CPL_DATA_STATUS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW0+(cntxt,chan) (((msgType)<<FLASH_SET_FEAT_MSGTYPE_LSB )|((cntxt)<<FLASH_SET_FEAT_CNTXT_LSB )|((chan)<<FLASH_SET_FEAT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_SET_FEAT_CHMSGNODEADDR_LSB )|((chain)<<FLASH_SET_FEAT_CHAIN_LSB )|((outMsgQ)<<FLASH_SET_FEAT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW4-(address) (((address)<<FLASH_SET_FEAT_ADDRESS_LSB ))    
                  
/** 
* @brief Macro to create dword5 for message FLASH_SET_FEAT
*/
#define FLASH_SET_FEAT_DW5-(parameters) (((parameters)<<FLASH_SET_FEAT_PARAMETERS_LSB ))    
                  
/** 
* @brief Macro to create dword0 for message FLASH_GET_FEAT
*/
#define FLASH_GET_FEAT_DW0+(cntxt,chan) (((msgType)<<FLASH_GET_FEAT_MSGTYPE_LSB )|((cntxt)<<FLASH_GET_FEAT_CNTXT_LSB )|((chan)<<FLASH_GET_FEAT_CHAN_LSB ))    
                  
/** 
* @brief Macro to create dword1 for message FLASH_GET_FEAT
*/
#define FLASH_GET_FEAT_DW1-(chMsgNodeAddr,chain,outMsgQ) (((chMsgNodeAddr)<<FLASH_GET_FEAT_CHMSGNODEADDR_LSB )|((chain)<<FLASH_GET_FEAT_CHAIN_LSB )|((outMsgQ)<<FLASH_GET_FEAT_OUTMSGQ_LSB ))    
                  
/** 
* @brief Macro to create dword4 for message FLASH_GET_FEAT
*/
#define FLASH_GET_FEAT_DW4-(address) (((address)<<FLASH_GET_FEAT_ADDRESS_LSB ))    
  
/** 
* @brief Structure declaration for the FlashAddrFormat message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 6:0  
        * Page Number
        * Based on the number of pages in a flash block, the number of bits allocated for page number will change.
        */
         u32 pageNum : 7;
        /**
        * DWORD:0   BITS: 19:7  
        * Block Number
        * Based on the number of blocks in a flash LUN, the number of bits allocated for block number will change.
        */
         u32 blockNum : 13;
        /**
        * DWORD:0   BITS: 23:20  
        * Lun Number
        * Based on the number of LUNs in a flash target, the number of bits allocated for LUN number will change.
        */
         u32 lunNum : 4;
        /**
        * DWORD:0   BITS: 31:24  
        * Reserved
        */
         u32 reservedDW0B31_24 : 8;
     };
  u32 dw[1];
} flash_addr_format_t ; 
/** 
* @brief Structure declaration for the FlashChannelConfigUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 8:4  
        * Number of contexts
        * The number of contexts per flash channel. The flash channel processor supports 16 contexts, allowing up to 16 flash logical units to perform read/program/erase operations in parallel.
        */
         u32 numContext : 5;
        /**
        * DWORD:4   BITS: 12:9  
        * The number of LUNs
        * The number of LUNs per CE.
        */
         u32 numLun : 4;
        /**
        * DWORD:4   BITS: 18:13  
        * The LUN bit position
        * The LUN bit position in the flash address.
        */
         u32 lunBitPosition : 6;
        /**
        * DWORD:4   BITS: 31:19  
        * Reserved
        */
         u32 reservedDW4B31_19 : 13;
        /**
        * DWORD:5   BITS: 15:0  
        * Page Size
        * The flash page size including the spares in DWords
        */
         u32 pageSize : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Reserved
        */
         u32 reservedDW5B31_16 : 16;
        /**
        * DWORD:6   BITS: 3:0  
        * First Context Number
        * The first context number in the flash channel controller.
        */
         u32 _1stContext : 4;
        /**
        * DWORD:6   BITS: 7:4  
        * First Context CE Number
        * Chip enable mapped to the first context
        */
         u32 _1stContextCE : 4;
        /**
        * DWORD:6   BITS: 11:8  
        * First Context LUN Number
        * The first context LUN number within the first context CE
        */
         u32 _1stContextLun : 4;
        /**
        * DWORD:6   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW6B15_12 : 4;
        /**
        * DWORD:6   BITS: 19:16  
        * Second Context Number
        * The second context number in the flash channel controller.
        */
         u32 _2ndContext : 4;
        /**
        * DWORD:6   BITS: 23:20  
        * Second Context CE Number
        * Chip enable mapped to the second context
        */
         u32 _2ndContextCE : 4;
        /**
        * DWORD:6   BITS: 27:24  
        * Second Context LUN Number
        * The second context LUN number within the second context CE
        */
         u32 _2ndContextLun : 4;
        /**
        * DWORD:6   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW6B31_28 : 4;
        /**
        * DWORD:7   BITS: 3:0  
        * Third Context Number
        * The third context in the flash channel controller.
        */
         u32 _3rdContext : 4;
        /**
        * DWORD:7   BITS: 7:4  
        * Third Context CE Number
        * Chip enable mapped to the third context
        */
         u32 _3rdContextCE : 4;
        /**
        * DWORD:7   BITS: 11:8  
        * Third Context LUN Number
        * The third context LUN number within the third context CE
        */
         u32 _3rdContextLun : 4;
        /**
        * DWORD:7   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW7B15_12 : 4;
        /**
        * DWORD:7   BITS: 19:16  
        * Fourth Context Number
        * The fourth context in the flash channel controller.
        */
         u32 _4thContext : 4;
        /**
        * DWORD:7   BITS: 23:20  
        * Fourth Context CE Number
        * Chip enable mapped to the fourth context
        */
         u32 _4thContextCE : 4;
        /**
        * DWORD:7   BITS: 27:24  
        * Fourth Context LUN Number
        * The fourth context LUN number within the fourth context CE
        */
         u32 _4thContextLun : 4;
        /**
        * DWORD:7   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW7B31_28 : 4;
        /**
        * DWORD:8   BITS: 3:0  
        * Fifth Context Number
        * The fifth context in the flash channel controller.
        */
         u32 _5thContext : 4;
        /**
        * DWORD:8   BITS: 7:4  
        * Fifth Context CE Number
        * Chip enable mapped to the fifth context
        */
         u32 _5thContextCE : 4;
        /**
        * DWORD:8   BITS: 11:8  
        * Fifth Context LUN Number
        * The fifth context LUN number within the fifth context CE
        */
         u32 _5thContextLun : 4;
        /**
        * DWORD:8   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW8B15_12 : 4;
        /**
        * DWORD:8   BITS: 19:16  
        * Sixth Context Number
        * The sixth context in the flash channel controller.
        */
         u32 _6thContext : 4;
        /**
        * DWORD:8   BITS: 23:20  
        * Sixth Context CE Number
        * Chip enable mapped to the sixth context
        */
         u32 _6thContextCE : 4;
        /**
        * DWORD:8   BITS: 27:24  
        * Sixth Context LUN Number
        * Thesixthcontext LUN number within the sixth context CE
        */
         u32 _6thContextLun : 4;
        /**
        * DWORD:8   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW8B31_28 : 4;
        /**
        * DWORD:9   BITS: 3:0  
        * Seventh Context Number
        * The seventh context in the flash channel controller.
        */
         u32 _7thContext : 4;
        /**
        * DWORD:9   BITS: 7:4  
        * Seventh Context CE Number
        * Chip enable mapped to the seventh context
        */
         u32 _7thContextCE : 4;
        /**
        * DWORD:9   BITS: 11:8  
        * Seventh Context LUN Number
        * The seventh context LUN number within the seventh context CE
        */
         u32 _7thContextLun : 4;
        /**
        * DWORD:9   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW9B15_12 : 4;
        /**
        * DWORD:9   BITS: 19:16  
        * Eighth Context Number
        * The eighth context in the flash channel controller.
        */
         u32 _8thContext : 4;
        /**
        * DWORD:9   BITS: 23:20  
        * Eighth Context CE Number
        * Chip enable mapped to the eighth context
        */
         u32 _8thContextCE : 4;
        /**
        * DWORD:9   BITS: 27:24  
        * Eighth Context LUN Number
        * The eighth context LUN number within the eighth context CE
        */
         u32 _8thContextLun : 4;
        /**
        * DWORD:9   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW9B31_28 : 4;
        /**
        * DWORD:10   BITS: 3:0  
        * Ninth Context Number
        * The ninth context in the flash channel controller.
        */
         u32 _9thContext : 4;
        /**
        * DWORD:10   BITS: 7:4  
        * Ninth Context CE Number
        * Chip enable mapped to the ninth context
        */
         u32 _9thContextCE : 4;
        /**
        * DWORD:10   BITS: 11:8  
        * Ninth Context LUN Number
        * The ninth context LUN number within the ninth context CE
        */
         u32 _9thContextLun : 4;
        /**
        * DWORD:10   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW10B15_12 : 4;
        /**
        * DWORD:10   BITS: 19:16  
        * Tenth Context Number
        * The tenth context in the flash channel controller.
        */
         u32 _10thContext : 4;
        /**
        * DWORD:10   BITS: 23:20  
        * Tenth Context CE Number
        * Chip enable mapped to the tenth context
        */
         u32 _10thContextCE : 4;
        /**
        * DWORD:10   BITS: 27:24  
        * Tenth Context LUN Number
        * The tenth context LUN number within the tenth context CE
        */
         u32 _10thContextLun : 4;
        /**
        * DWORD:10   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW10B31_28 : 4;
        /**
        * DWORD:11   BITS: 3:0  
        * Eleventh Context Number
        * The eleventh context in the flash channel controller.
        */
         u32 _11thContext : 4;
        /**
        * DWORD:11   BITS: 7:4  
        * Eleventh Context CE Number
        * Chip enable mapped to the eleventh context
        */
         u32 _11thContextCE : 4;
        /**
        * DWORD:11   BITS: 11:8  
        * Eleventh Context LUN Number
        * The eleventh context LUN number within the eleventh context CE
        */
         u32 _11thContextLun : 4;
        /**
        * DWORD:11   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW11B15_12 : 4;
        /**
        * DWORD:11   BITS: 19:16  
        * Twelfth Context Number
        * The twelfth context in the flash channel controller.
        */
         u32 _12thContext : 4;
        /**
        * DWORD:11   BITS: 23:20  
        * Twelfth Context CE Number
        * Chip enable mapped to the twelfth context
        */
         u32 _12thContextCE : 4;
        /**
        * DWORD:11   BITS: 27:24  
        * Twelfth Context LUN Number
        * The twelfth context LUN number within the twelfth context CE
        */
         u32 _12thContextLun : 4;
        /**
        * DWORD:11   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW11B31_28 : 4;
        /**
        * DWORD:12   BITS: 3:0  
        * Thirteenth Context Number
        * The thirteenth context in the flash channel controller.
        */
         u32 _13thContext : 4;
        /**
        * DWORD:12   BITS: 7:4  
        * Thirteenth Context CE Number
        * Chip enable mapped to the thirteenth context
        */
         u32 _13thContextCE : 4;
        /**
        * DWORD:12   BITS: 11:8  
        * Thirteenth Context LUN Number
        * The thirteenth context LUN number within thirteenth context CE
        */
         u32 _13thContextLun : 4;
        /**
        * DWORD:12   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW12B15_12 : 4;
        /**
        * DWORD:12   BITS: 19:16  
        * Fourteenth Context Number
        * The fourteenth context in the flash channel controller.
        */
         u32 _14thContext : 4;
        /**
        * DWORD:12   BITS: 23:20  
        * Fourteenth Context CE Number
        * Chip enable mapped to the fourteenth context
        */
         u32 _14thContextCE : 4;
        /**
        * DWORD:12   BITS: 27:24  
        * Fourteenth Context LUN Number
        * The fourteenth Context LUN number within the fourteenth context CE
        */
         u32 _14thContextLun : 4;
        /**
        * DWORD:12   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW12B31_28 : 4;
        /**
        * DWORD:13   BITS: 3:0  
        * Fifteenth Context Number
        * The fifteenth context in the flash channel controller.
        */
         u32 _15thContext : 4;
        /**
        * DWORD:13   BITS: 7:4  
        * Fifteenth Context CE Number
        * Chip enable mapped to the fifteenth context
        */
         u32 _15thContextCE : 4;
        /**
        * DWORD:13   BITS: 11:8  
        * Fifteenth Context LUN Number
        * The fifteenth context LUN number within the fifteenth context CE
        */
         u32 _15thContextLun : 4;
        /**
        * DWORD:13   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW13B15_12 : 4;
        /**
        * DWORD:13   BITS: 19:16  
        * Sixteenth Context Number
        * The sixteenth context number in the flash channel controller.
        */
         u32 _16thContext : 4;
        /**
        * DWORD:13   BITS: 23:20  
        * Sixteenth Context CE Number
        * Chip enable mapped to the sixteenth context
        */
         u32 _16thContextCE : 4;
        /**
        * DWORD:13   BITS: 27:24  
        * Sixteenth Context LUN Number
        * The sixteenth context LUN number within sixteenth context CE
        */
         u32 _16thContextLun : 4;
        /**
        * DWORD:13   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW13B31_28 : 4;
        /**
        * DWORD:15:14  
        * Reserved
        */
         u32 reservedDW15_14B31_0[2];
     };
  u32 dw[16];
} flash_channel_config_update_t ; 
/** 
* @brief Structure declaration for the FlashEccContextInfoUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the Flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the Flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 7:4  
        * Number of ECC Context Data entries.
        * This field indicates the number of ECC context data entries that are valid.
        */
         u32 numEntries : 4;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:15:5  
        * ECC Context Data
        * This field contain ECC context data such as context number, protected data size, and ECC chunk size.
        */
         u32 eccContextData[11];
     };
  u32 dw[16];
} flash_ecc_context_info_update_t ; 
/** 
* @brief Structure declaration for the EccContextData message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 3:0  
        * ECC Context Number
        */
         u32 eccContextNum : 4;
        /**
        * DWORD:0   BITS: 17:4  
        * ECC Chunk Size
        * This field contains the ECC chunk size in DWords for a given ECC context number
        */
         u32 eccChunkSize : 14;
        /**
        * DWORD:0   BITS: 31:18  
        * Protected Data Size.
        * This field contains the protected data size in DWords for a given ECC context number.
        */
         u32 protectedDataSize : 14;
     };
  u32 dw[1];
} ecc_context_data_t ; 
/** 
* @brief Structure declaration for the FlashTimingParamUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the Flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the Flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 4  
        * Timing Select
        * This field selects the Flash Timing (FT) register used for the Flash operations.
        *- 0 Timing mode 0 selects FT0xxx timing mode register values
        *- 1 Timing mode 1 selects FT1xxx timing mode register values
        */
         u32 timeSel : 1;
        /**
        * DWORD:4   BITS: 31:5  
        * Reserved
        */
         u32 reservedDW4B31_5 : 27;
        /**
        * DWORD:5   BITS: 15:0  
        * Dummy Busy Time
        * This field specifies the dummy busy time (tDBSY) in units of Flash I/O clock cycles.
        */
         u32 dummyBusyTime : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Clock High to R/B Low Time
        * This field specifies the CLK high to R/B low (tWB) in units of Flash I/O clock cycles
        */
         u32 clkHigh2RBLowTime : 16;
        /**
        * DWORD:6   BITS: 31:0  
        * Device Reset Time
        * This field specifies the reset time (tRST) in units of Flash I/O clock cycles
        */
         u32 resetTime;
        /**
        * DWORD:7   BITS: 31:0  
        * Power on Reset Time
        * This field specifies the power on reset time (tPOR) in units of flash I/O clock cycles
        */
         u32 powerOnRstTime;
        /**
        * DWORD:8   BITS: 31:0  
        * Interface Change Time
        * This field specifies the busy time to change interface (tITC) in units of flash I/O clock cycles
        */
         u32 interfaceChangeTime;
        /**
        * DWORD:9   BITS: 31:0  
        * Feature Time
        * This field specifies the Set/Get feature busy time (tFEAT) in units of flash I/O clock cycles
        */
         u32 featureTime;
        /**
        * DWORD:10   BITS: 15:0  
        * Poll Read Time
        * This field specifies the read poll time in units of flash I/O clock cycles
        */
         u32 rdPollTime : 16;
        /**
        * DWORD:10   BITS: 31:16  
        * Poll Write Time
        * This field specifies the program poll time in units of flash I/O clock cycles
        */
         u32 wrPollTime : 16;
        /**
        * DWORD:11   BITS: 15:0  
        * Poll Block Erase Time
        * This field specifies the block erase poll time in units of flash I/O clock cycles
        */
         u32 berPollTime : 16;
        /**
        * DWORD:11   BITS: 31:16  
        * Miscellaneous Polling Time
        * This field specifies the miscellaneous Polling time used by Set/Get Feature, Read Parameter Page commands, etc
        */
         u32 miscPollTime : 16;
        /**
        * DWORD:12   BITS: 7:0  
        * Max Poll Count
        * This field specifies the maximum number of polling retries.
        */
         u32 maxPollCount : 8;
        /**
        * DWORD:12   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW12B31_8 : 24;
        /**
        * DWORD:15:13  
        * Reserved
        */
         u32 reservedDW15_13B31_0[3];
     };
  u32 dw[16];
} flash_timing_param_update_t ; 
/** 
* @brief Structure declaration for the FlashPowerCreditUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 31:4  
        * Reserved
        */
         u32 reservedDW4B31_4 : 28;
        /**
        * DWORD:5   BITS: 15:0  
        * Read SLC Power Credit
        * This field specifies the power units for an SLC Read command, which includes the flash array read power and I/O burst read power.
        */
         u32 readSLCPowerCredit : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Program SLC Power Credit
        * This field specifies the power units for an SLC Program command, which includes the flash array program power and I/O burst read power.
        */
         u32 programSLCPowerCredit : 16;
        /**
        * DWORD:6   BITS: 15:0  
        * Erase Power Credit
        * This field specifies the power units for the erase command.
        */
         u32 erasePowerCredit : 16;
        /**
        * DWORD:6   BITS: 31:16  
        * Read TLC Single Plane Power Credit
        * This field specifies the power units for a single plane TLC Read command, which includes the flash array read power and I/O burst read power.
        */
         u32 readTLCSinglePlanePowerCredit : 16;
        /**
        * DWORD:7   BITS: 15:0  
        * Read TLC Multi Plane Power Credit
        * This field specifies the power units for a multiple plane TLC Read command, which includes the flash array read power and I/O burst read power.
        */
         u32 readTLCMultiPlanePowerCredit : 16;
        /**
        * DWORD:7   BITS: 31:16  
        * Program TLC Pass 1 Power Credit
        * This field specifies the power units for the first pass of a TLC Program command, which includes the flash array program power and I/O burst read power.
        */
         u32 programTLCPass1PowerCredit : 16;
        /**
        * DWORD:8   BITS: 15:0  
        * Program TLC Pass 2 Power Credit
        * This field specifies the power units for the second pass of a TLC Program command, which includes the flash array program power and I/O burst read power.
        */
         u32 programTLCPass2PowerCredit : 16;
        /**
        * DWORD:8   BITS: 31:16  
        * Program TLC Pass 3 Power Credit
        * This field specifies the power units for the third pass of a TLC Program command, which includes the flash array program power and I/O burst read power.
        */
         u32 programTLCPass3PowerCredit : 16;
        /**
        * DWORD:9   BITS: 15:0  
        * Erase Workaround Power Credit
        * This field specifies the power units for the erase workaround command.
        */
         u32 eraseWorkaroundPowerCredit : 16;
        /**
        * DWORD:9   BITS: 31:16  
        * Miscellaneous Power Credit
        * This specifies the maximum power used by any other commands like Read Status, Set Feature, Get feature, etc
        */
         u32 miscPowerCredit : 16;
        /**
        * DWORD:15:10  
        * Reserved
        */
         u32 reservedDW15_10B31_0[6];
     };
  u32 dw[16];
} flash_power_credit_update_t ; 
/** 
* @brief Structure declaration for the FlashDynamicUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 31:4  
        * Reserved
        */
         u32 reservedDW4B31_4 : 28;
        /**
        * DWORD:5   BITS: 15:0  
        * High Priority Poll Limit
        * This field specifies the poll limit for the high priority message processing.
        */
         u32 highPriorPollLimit : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Reserved
        */
         u32 reservedDW5B31_16 : 16;
        /**
        * DWORD:6   BITS: 31:0  
        * DDR Dump Buffer Address
        * This field contains the DDR Buffer Address that shall be used by microcode to dump the data.
        */
         u32 dmpDDRBuffAddr;
        /**
        * DWORD:7   BITS: 31:0  
        * BRAM Dump Buffer Address
        * This field contains the BRAM Buffer Address that shall be used by microcode to dump the data.
        */
         u32 dmpBRAMBuffAddr;
        /**
        * DWORD:15:8  
        * Reserved
        */
         u32 reservedDW15_8B31_0[8];
     };
  u32 dw[16];
} flash_dynamic_update_t ; 
/** 
* @brief Structure declaration for the GetIterationCount message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        *- 6 (IterationCountInfo) Get Iteration Count Info
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 4  
        * Reset ecc iteration count Statistics
        * When this bit is set,the minimum,maximum,average ECC iteration counters are initialized to 0.
        */
         u32 reset : 1;
        /**
        * DWORD:4   BITS: 31:5  
        * Reserved
        */
         u32 reservedDW4B31_5 : 27;
        /**
        * DWORD:15:8  
        * Reserved
        */
         u32 reservedDW15_8B31_0[8];
     };
  u32 dw[16];
} get_iteration_count_t ; 
/** 
* @brief Structure declaration for the ReadHeader message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 2:0  
        * Plane Number
        * The plane number of the current read header. It may not be physical plane number. The microcode uses this field to get corresponding flash address provided in the flash read messages.
        */
         u32 planeNum : 3;
        /**
        * DWORD:0   BITS: 6:3  
        * Number of buffers
        * Number of buffers involved in current read header.
        */
         u32 numBuffers : 4;
        /**
        * DWORD:0   BITS: 7  
        * Last buffer spans to next plane.
        * Flag to indicate the last buffer spans to the next plane.
        */
         u32 lastBufferSpan : 1;
        /**
        * DWORD:0   BITS: 11:8  
        * Number of ECC Chunks
        * The number of ECC chunks involved in current read header.
        */
         u32 numECCChunk : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Starting ECC Chunk number
        * The starting ECC chunk number of the current read header.
        */
         u32 startECCChunk : 4;
        /**
        * DWORD:0   BITS: 30:16  
        * Start Dump Count
        * The number of dwords to be dumped in the first ECC chunk (Starting ECC chunk) of the current read header..
        */
         u32 startDumpCount : 15;
        /**
        * DWORD:0   BITS: 31  
        * Header signature
        * Read/Write header signature
        */
         u32 hdrSig : 1;
     };
  u32 dw[1];
} read_header_t ; 
/** 
* @brief Structure declaration for the WriteHeader message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 2:0  
        * Plane Number
        * The plane number of the current write header. It may not be physical plane number. The microcode uses this field to get the corresponding flash address provided in the flash write message.
        */
         u32 planeNum : 3;
        /**
        * DWORD:0   BITS: 6:3  
        * Number of buffers
        * The number of buffers involved in the current write header.
        */
         u32 numBuffers : 4;
        /**
        * DWORD:0   BITS: 7  
        * Last buffer spans to next plane.
        * Flag to indicate the last buffer spans to the next plane.
        */
         u32 lastBufferSpan : 1;
        /**
        * DWORD:0   BITS: 11:8  
        * Number of ECC Chunks
        * The number of ECC chunks involved in the current write header.
        */
         u32 numECCChunk : 4;
        /**
        * DWORD:0   BITS: 27:12  
        * Last Data Frame Length
        * The last data frame dword length in the current write header.
        */
         u32 lastDataFrameLength : 16;
        /**
        * DWORD:0   BITS: 30:28  
        * Reserved
        */
         u32 reservedDW0B30_28 : 3;
        /**
        * DWORD:0   BITS: 31  
        * Header signature
        * Read/Write header signature
        */
         u32 hdrSig : 1;
     };
  u32 dw[1];
} write_header_t ; 
/** 
* @brief Structure declaration for the FlashRead message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:4  
        * Flash Address
        * This field encodes the physical flash address of the page to be read for different planes.
        */
         u32 flashAddr[4];
        /**
        * DWORD:8   BITS: 3:0  
        * ECC Code Rate Index
        * This field specifies the ECC code rate index used for ECC encode and decode operations
        * An ECC code rate index of zero indicates a raw bulk data transfer
        */
         u32 eccCodeRateIndex : 4;
        /**
        * DWORD:8   BITS: 7:4  
        * Reserved
        */
         u32 reservedDW8B7_4 : 4;
        /**
        * DWORD:8   BITS: 15:8  
        * Max Iterations
        * This field specifies the maximum number of iterations to be completed before the LDPC decoder declares an uncorrectable ECC error.
        * A value of zero means 256 iterations.
        * The value of this field is ignored during raw bulk data transfers and ECC encode operations
        */
         u32 maxIter : 8;
        /**
        * DWORD:8   BITS: 23:16  
        * Log Likelihood Ratio for a Received Zero
        * This field contains the Log Likelihood Ratio (LLR) used by LDPC decode operations for a bit value of zero read from NAND.
        * The LLR is six bits in size. The value of the top two bits of this field is ignored.
        * The value of this field is ignored during raw bulk data transfers and ECC encode operations
        */
         u32 lLR0 : 8;
        /**
        * DWORD:8   BITS: 31:24  
        * Log Likelihood Ratio for a Received One
        * This field contains the Log Likelihood Ratio (LLR) used by LDPC decode operations for a bit value of one read from NAND.
        * The LLR is six bits in size. The value of the top two bits of this field is ignored.
        * The value of this field is ignored during raw bulk data transfers and ECC encode operations
        */
         u32 lLR1 : 8;
        /**
        * DWORD:9   BITS: 15:0  
        * Scrambler Seed
        * This field contains the seed value used by the scrambler .
        */
         u32 scramblerSeed : 16;
        /**
        * DWORD:9   BITS: 23:16  
        * Read Retry Option
        * This field contains the read retry option to be used during NAND read operation.
        */
         u32 readRetry : 8;
        /**
        * DWORD:9   BITS: 27:24  
        * Number Of Planes
        * This field indicates the number of planes involved in current operation.
        */
         u32 numPlane : 4;
        /**
        * DWORD:9   BITS: 28  
        * Data Frame Buffer Operation
        *- 0 - Don't allocate data frame buffer
        *- 1 - Allocate data frame buffer.
        */
         u32 dfBuffOperation : 1;
        /**
        * DWORD:9   BITS: 30:29  
        * Reserved
        */
         u32 reservedDW9B30_29 : 2;
        /**
        * DWORD:9   BITS: 31  
        * Block Type
        *- 0 - MLC
        *- 1 - SLC
        */
         u32 blockType : 1;
        /**
        * DWORD:10   BITS: 23:0  
        * Page Read Time
        * This field specifies the page read time in units of flash controller clock cycles
        */
         u32 pageReadTime : 24;
        /**
        * DWORD:10   BITS: 31:24  
        * Read Header Count
        * This field contains the number of read headers involved in the current read operation
        */
         u32 readHdrCount : 8;
        /**
        * DWORD:11   BITS: 15:0  
        * First Data Frame Offset
        * This field contains the first data frame buffer dword offset.
        * When the data frame spanned two physical pages, the first data frame buffer offset represents the offset of the first data frame buffer to transfer the data.
        */
         u32 firstDFOffset : 16;
        /**
        * DWORD:11   BITS: 31:16  
        * Data Frame Length
        * This field contains the data frame length in dwords.
        */
         u32 dataFrameLength : 16;
        /**
        * DWORD:12   BITS: 31:0  
        * Raw Buffer
        * This field contains the raw buffer line address.
        * The raw buffer address is used when there is a ECC error. Raw data (ECC chunk data) is transferred to the raw buffer if a raw buffer is given. Otherwise, raw data is dropped and never transferred to the CMU. A non-zero value indicates a raw buffer is given.
        */
         u32 rawBuffer;
        /**
        * DWORD:13   BITS: 31:0  
        * Read Header
        * This field contains the read header.
        */
         u32 readHeader0;
        /**
        * DWORD:14   BITS: 31:0  
        * Data Frame Buffer 0
        * This field contains the data frame buffer 0 line address associated with readHeader0
        */
         u32 dataFrameBuffer0;
        /**
        * DWORD:15   BITS: 31:0  
        * Read Message DWord 15
        * Depending on number of buffers in readHeaderx, this field contains another read header or the data frame buffer line address
        */
         u32 readMsgDW15;
     };
  u32 dw[16];
} flash_read_t ; 
/** 
* @brief Structure declaration for the FlashWrite message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 20:17  
        * Reserved
        */
         u32 reservedDW0B20_17 : 4;
        /**
        * DWORD:0   BITS: 29:21  
        * XOR Calculator ID
        * This field specifies the XOR calculator flow ID.
        * The value of this field is ignored when the XORCalcOp field value is set to NOP.
        * The XOR Calculator ID field is translated when processed by the XOR calculator. When received by a Flash channel processor, this field contains the XOR context ID.
        */
         u32 xorCalcID : 9;
        /**
        * DWORD:0   BITS: 30  
        * Last Request of a XOR Calculator Flow ID Stripe
        * This field indicates whether this is the last request of a Flow ID stripe.
        *- 0 (NOTLAST) First or middle operation of a Flow ID stripe
        *- 1 (LAST) Last operation of a Flow ID stripe
        * The value of this field is ignored then the XORCalcOp field value is set to NOP.
        */
         u32 xorCalcStripeLast : 1;
        /**
        * DWORD:0   BITS: 31  
        * XOR Calculation Operation
        * This field encodes
        * whether a XOR calculator operation is perform as a side effect of request message processing.
        *- 0 (NOP) No operation
        *- 1 (XORCALC) XOR calculator operation
        */
         u32 xorCalcOp : 1;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:4  
        * Flash Address
        * This field encodes the physical flash address of the page to be written for different planes.
        */
         u32 flashAddr[4];
        /**
        * DWORD:8   BITS: 3:0  
        * ECC Code Rate Index
        * This field specifies the ECC code rate index used for ECC encode and decode operations
        * An ECC code rate index of zero indicates a raw bulk data transfer
        */
         u32 eccCodeRateIndex : 4;
        /**
        * DWORD:8   BITS: 31:4  
        * Reserved
        */
         u32 reservedDW8B31_4 : 28;
        /**
        * DWORD:9   BITS: 15:0  
        * Scrambler Seed
        * This field contains the seed value used by the scrambler .
        */
         u32 scramblerSeed : 16;
        /**
        * DWORD:9   BITS: 23:16  
        * Reserved
        */
         u32 reservedDW9B23_16 : 8;
        /**
        * DWORD:9   BITS: 27:24  
        * Number Of Planes
        * This field indicates the number of planes involved in the current operation.
        */
         u32 numPlane : 4;
        /**
        * DWORD:9   BITS: 28  
        * Data Frame Buffer Operation
        *- 0 - Don't free the data frame buffer
        *- 1 - Free the data frame buffer after successful flash operation.
        */
         u32 dfBuffOperation : 1;
        /**
        * DWORD:9   BITS: 30:29  
        * Reserved
        */
         u32 reservedDW9B30_29 : 2;
        /**
        * DWORD:9   BITS: 31  
        * Block Type
        *- 0 - MLC
        *- 1 - SLC
        */
         u32 blockType : 1;
        /**
        * DWORD:10   BITS: 23:0  
        * Page Program Time
        * This field specifies the page program time in units of flash controller clock cycles
        */
         u32 pageProgTime : 24;
        /**
        * DWORD:10   BITS: 31:24  
        * Write Header Count
        * This field contains the number of write headers involved in the current write operation
        */
         u32 writeHdrCount : 8;
        /**
        * DWORD:11   BITS: 15:0  
        * First Data Frame Offset
        * This field contains the first data frame buffer dword offset.
        * When the data frame spanned two physical pages, the first data frame buffer offset represents offset of the first data frame buffer to transfer the data.
        */
         u32 firstDFOffset : 16;
        /**
        * DWORD:11   BITS: 31:16  
        * Data Frame Length
        * This field contains the data frame length in dwords.
        */
         u32 dataFrameLength : 16;
        /**
        * DWORD:12   BITS: 31:0  
        * Write header 0
        * This field contains the write header.
        */
         u32 writeHeader0;
        /**
        * DWORD:13   BITS: 31:0  
        * Data Buffer Type
        * This field contains data frame buffer types of buffers in the current header to be freed.
        * Note: When the data frame buffer is not freed, this field is reserved.
        */
         u32 dataFrameBuffType;
        /**
        * DWORD:14   BITS: 31:0  
        * Data Frame Buffer Addr
        * This field contains the data frame buffer line address associated with writeHeader0
        */
         u32 dataFrameBuffAddr;
        /**
        * DWORD:15   BITS: 31:0  
        * Write Message DWord 15
        * Depending on the number of buffers in the writeHeaderx, this field contains another write header or the data frame buffer line address
        */
         u32 writeMsgDW15;
     };
  u32 dw[16];
} flash_write_t ; 
/** 
* @brief Structure declaration for the FlashCont message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:15:2  
        * Depending on number of buffers in readHeaderX/WriteHeaderX, this field contain another read header/write header or a data frame buffer line address or the dataFrameBuffType(Flash Write only).
        */
         u32 contHeader[14];
     };
  u32 dw[16];
} flash_cont_t ; 
/** 
* @brief Structure declaration for the FlashErase message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:4  
        * Flash Address
        * This field encodes the physical flash address of the page to be erased.
        */
         u32 flashAddr[4];
        /**
        * DWORD:8   BITS: 31:0  
        * Reserved
        */
         u32 reservedDW8B31_0;
        /**
        * DWORD:9   BITS: 23:0  
        * Reserved
        */
         u32 reservedDW9B23_0 : 24;
        /**
        * DWORD:9   BITS: 27:24  
        * Number Of Planes
        * This field indicates the number of planes involved in the current operation.
        */
         u32 numPlane : 4;
        /**
        * DWORD:9   BITS: 30:28  
        * Reserved.
        */
         u32 reservedDW9B30_28 : 3;
        /**
        * DWORD:9   BITS: 31  
        * Block Type
        *- 0 - MLC
        *- 1 - SLC
        */
         u32 blockType : 1;
        /**
        * DWORD:10   BITS: 23:0  
        * Block Erase Time
        * This field specifies the block erase time in units of flash controller clock cycles.
        * The erase Polling time is fixed in Microcode.
        */
         u32 blockEraseTime : 24;
        /**
        * DWORD:10   BITS: 31:24  
        * Reserved
        */
         u32 reservedDW10B31_24 : 8;
        /**
        * DWORD:15:11  
        * Reserved
        */
         u32 reservedDW15_11B31_0[5];
     };
  u32 dw[16];
} flash_erase_t ; 
/** 
* @brief Structure declaration for the dataFrameBuffType message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 2:0  
        * Data Buffer Type 0
        * This field contains the data frame buffer type of buffer0.
        */
         u32 dfBuffType0 : 3;
        /**
        * DWORD:0   BITS: 5:3  
        * Data Buffer Type 1
        * This field contains the data frame buffer type of buffer1.
        */
         u32 dfBuffType1 : 3;
        /**
        * DWORD:0   BITS: 8:6  
        * Data Buffer Type 2
        * This field contains the data frame buffer type of buffer2.
        */
         u32 dfBuffType2 : 3;
        /**
        * DWORD:0   BITS: 11:9  
        * Data Buffer Type 3
        * This field contains the data frame buffer type of buffer3.
        */
         u32 dfBuffType3 : 3;
        /**
        * DWORD:0   BITS: 14:12  
        * Data Buffer Type 4
        * This field contains the data frame buffer type of buffer4.
        */
         u32 dfBuffType4 : 3;
        /**
        * DWORD:0   BITS: 17:15  
        * Data Buffer Type 5
        * This field contains the data frame buffer type of buffer5.
        */
         u32 dfBuffType5 : 3;
        /**
        * DWORD:0   BITS: 20:18  
        * Data Buffer Type 6
        * This field contains the data frame buffer type of buffer6.
        */
         u32 dfBuffType6 : 3;
        /**
        * DWORD:0   BITS: 23:21  
        * Data Buffer Type 7
        * This field contains the data frame buffer type of buffer7.
        */
         u32 dfBuffType7 : 3;
        /**
        * DWORD:0   BITS: 26:24  
        * Data Buffer Type 8
        * This field contains the data frame buffer type of buffer8.
        */
         u32 dfBuffType8 : 3;
        /**
        * DWORD:0   BITS: 31:27  
        * Number of Buffer Types
        * This field contains the number of buffer types that are valid in this dword.
        */
         u32 numBuffTypes : 5;
     };
  u32 dw[1];
} data_frame_buff_type_t ; 
/** 
* @brief Structure declaration for the FlashOpCpl message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field encodes the completion message type.
        *- 1 FlashOpCpl
        *- 2 FlashOpCplCont
        *- 3 FlashOpCplData
        *- 4 - 253 Microcode specific
        *- 254 (FlashEccCpl) Flash ECC Completion
        *- 255 (Auto) Hardware auto generated completion message
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Outbound Message Queue
        * This field specifies the index of the Flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Reserved
        */
         u32 reservedDW0B15_12 : 4;
        /**
        * DWORD:0   BITS: 19:16  
        * Status
        * This field encodes global status of the operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 status : 4;
        /**
        * DWORD:0   BITS: 20  
        * Erased Page
        * This bit is set if the percentage of bits in the ECC Chunk prior to LDPC correction that had a value of one was greater than the threshold specified by the erased page ECC chunk threshold (ERASEDTH) field in the ECC Control (ECCCTL) register.
        */
         u32 erasedPage : 1;
        /**
        * DWORD:0   BITS: 23:21  
        * Plane Number
        * Plane number for which this completion belongs
        */
         u32 planeNum : 3;
        /**
        * DWORD:0   BITS: 31:24  
        * Number Retries
        * If the status field indicates completion without error , then this field contains the total number poll retries required before it was determined that the flash operation completed. In all other cases, the contents of this field are undefined. A value of zero in this field indicates that no retries were required and that the Flash device indicated completion the first time it was polledNumber of Planes
        */
         u32 retries : 8;
        /**
        * DWORD:2:1  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:3   BITS: 31:0  
        * Plane Completion Information
        * The plane completion information varies for flash read/ flash write/flash erase messages. Refer to the discusssion of FlashRdPlaneCplInfo and FlashWrErPlaneCplInfo for the format of this dword.
        */
         u32 planeCplInfo;
        /**
        * DWORD:4   BITS: 15:0  
        * ECC Chunk Error Vector
        * Error vector for a total of 8 chunks. Each error chunk information is 2 bits.
        *- 0 (OK) Operation completed without error
        *- 1 (EccErr) Uncorrectable ECC error detected
        *- 2 (CrcErr) CRC mismatch
        *- 3 (ScramblerErr) Scrambler seed mismatch
        */
         u32 eccChunkErrVector : 16;
        /**
        * DWORD:4   BITS: 19:16  
        * Plane Max ZErrM
        * The maximum number of ZErrM bit errors in a specific ECC chunk within this plane.
        */
         u32 planeMaxZErrM : 4;
        /**
        * DWORD:4   BITS: 23:20  
        * Max ZErrM chunk Number
        * The ECC chunk number that contains the most ZErrM bit errors within this plane.
        */
         u32 maxZErrMChunkNum : 4;
        /**
        * DWORD:4   BITS: 31:24  
        * Plane Total ZErrM
        * The total number of ZErrM bit errors accumulated over all the ECC chunks within this plane
        */
         u32 planeTotalZErrM : 8;
        /**
        * DWORD:5   BITS: 31:0  
        * Data Buffer Type
        * This field contains the data frame buffer type for allocated buffers in current plane.
        * Note: When a data frame buffer is not allocated, this field is reserved.
        */
         u32 dataFrameBuffType;
        /**
        * DWORD:7:6  
        * Data Frame Buffer Controller Memory Line Address
        * This field contains the controller memory line address that points to the start of data frame 0. The memory line address is equal to the 37-bit controller memory byte address of the memory line shifted right six bits.
        * Note: When a data frame buffer is not allocated, this field is reserved.
        */
         u32 dfBuf[2];
     };
  u32 dw[8];
} flash_op_cpl_t ; 
/** 
* @brief Structure declaration for the FlashRdPlaneCplInfo message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 11:0  
        * Plane Max ECC Errors
        * The maximum number of ECC bit errors in a specific ECC chunk within this plane
        */
         u32 planeMaxEccErrors : 12;
        /**
        * DWORD:0   BITS: 15:12  
        * Max Error Chunk Number
        * The ECC chunk number that contains the most ECC bit errors within this plane
        */
         u32 maxErrorChunkNum : 4;
        /**
        * DWORD:0   BITS: 31:16  
        * Plane Total ECC Errors
        * The total number of ECC bit errors accumulated over all the ECC chunks within this plane
        */
         u32 planeTotalEccErrors : 16;
     };
  u32 dw[1];
} flash_rd_plane_cpl_info_t ; 
/** 
* @brief Structure declaration for the FlashWrErPlaneCplInfo message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 3:0  
        * Plane 0 Status
        * This field encodes the status of the plane 0 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane0status : 4;
        /**
        * DWORD:0   BITS: 7:4  
        * Plane 1 Status
        * This field encodes the status of the plane 1 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane1status : 4;
        /**
        * DWORD:0   BITS: 11:8  
        * Plane 2 Status
        * This field encodes the status of the plane 2 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane2status : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Plane 3 Status
        * This field encodes the status of the plane 3 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane3status : 4;
        /**
        * DWORD:0   BITS: 31:16  
        * Reserved
        */
         u32 reservedDW0B31_16 : 16;
     };
  u32 dw[1];
} flash_wr_er_plane_cpl_info_t ; 
/** 
* @brief Structure declaration for the FlashOpCplCont message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field encodes the completion message type.
        *- 1 FlashOpCpl
        *- 2 FlashOpCplCont
        *- 3 FlashOpCplData
        *- 4 - 253 Microcode specific
        *- 254 (FlashEccCpl) Flash ECC Completion
        *- 255 (Auto) Hardware auto generated completion message
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:0   BITS: 20:12  
        * Reserved
        */
         u32 reservedDW0B20_12 : 9;
        /**
        * DWORD:0   BITS: 23:21  
        * Plane Number
        * The plane number associated with the current completion.
        */
         u32 planeNum : 3;
        /**
        * DWORD:0   BITS: 31:24  
        * Reserved
        */
         u32 reservedDW0B31_24 : 8;
        /**
        * DWORD:2:1  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:3  
        * Data Frame Buffer Controller Memory Line Address
        * This field contains the controller memory line address that points to the start of data frame 0. The memory line address is equal to the 37-bit controller memory byte address of the memory line shifted right six bits.
        */
         u32 dfBuf[5];
     };
  u32 dw[8];
} flash_op_cpl_cont_t ; 
/** 
* @brief Structure declaration for the FlashMemWrite message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field must be set to a value of 255 in a flashMemWriterequest message.
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Number of dwords contained in the message request
        * This field specifies the number of valid dwords in this message request. The values zero as well as 13 through 16 are reserved and causes the message to be discarded.
        */
         u32 numDwords : 4;
        /**
        * DWORD:0   BITS: 31:12  
        * Reserved
        */
         u32 reservedDW0B31_12 : 20;
        /**
        * DWORD:1   BITS: 31:0  
        * Flash Channel Processor Multicast Vector
        * Each bit in this field corresponds to a flash channel processor (i.e., bit zero corresponds to flash channel processor zero, bit one corresponds to flash channel processor one, and son on). When a bit in this field set, the message request is sent to the corresponding flash channel processor.
        */
         u32 multicastVector;
        /**
        * DWORD:2   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW2B1_0 : 2;
        /**
        * DWORD:2   BITS: 31:2  
        * Flash Channel Processor Address
        * This field specifies the starting dword address location in Flash Channel Processor address space (i.e.,D-Mem or I-Mem) where the data contained in this message is written.
        */
         u32 flashChProcAddr : 30;
        /**
        * DWORD:3   BITS: 31:0  
        * Data DWord 0
        */
         u32 dataDWord0;
        /**
        * DWORD:4   BITS: 31:0  
        * Data DWord 1
        */
         u32 dataDWord1;
        /**
        * DWORD:5   BITS: 31:0  
        * Data DWord 2
        */
         u32 dataDWord2;
        /**
        * DWORD:6   BITS: 31:0  
        * Data DWord 3
        */
         u32 dataDWord3;
        /**
        * DWORD:7   BITS: 31:0  
        * Data DWord 4
        */
         u32 dataDWord4;
        /**
        * DWORD:8   BITS: 31:0  
        * Data DWord 5
        */
         u32 dataDWord5;
        /**
        * DWORD:9   BITS: 31:0  
        * Data DWord 6
        */
         u32 dataDWord6;
        /**
        * DWORD:10   BITS: 31:0  
        * Data DWord 7
        */
         u32 dataDWord7;
        /**
        * DWORD:11   BITS: 31:0  
        * Data DWord 8
        */
         u32 dataDWord8;
        /**
        * DWORD:12   BITS: 31:0  
        * Data DWord 9
        */
         u32 dataDWord9;
        /**
        * DWORD:13   BITS: 31:0  
        * Data DWord 10
        */
         u32 dataDWord10;
        /**
        * DWORD:14   BITS: 31:0  
        * Data DWord 11
        */
         u32 dataDWord11;
        /**
        * DWORD:15   BITS: 31:0  
        * Reserved
        */
         u32 reservedDW15B31_0;
     };
  u32 dw[16];
} flash_mem_write_t ; 
/** 
* @brief Structure declaration for the FlashReadParameterPage message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes theflash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Read Parameter Page Address
        * This field encodes the one byte address for the Read Parameter page command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Page Read Time
        * This field specifies the page read time in units of flash controller clock cycles
        */
         u32 pageReadTime : 24;
        /**
        * DWORD:5   BITS: 0  
        * Data Frame Buffer Operation
        *- 0 - Don't allocate data frame buffer
        *- 1 - Allocate data frame buffer.
        */
         u32 dfBuffOperation : 1;
        /**
        * DWORD:5   BITS: 31:1  
        * Reserved
        */
         u32 reservedDW5B31_1 : 31;
        /**
        * DWORD:6   BITS: 15:0  
        * Start Page Offset
        * This field contains the start dword offset to read parameters
        */
         u32 startOffset : 16;
        /**
        * DWORD:6   BITS: 31:16  
        * Data Frame Length
        * This field contains the data frame length in dwords.
        */
         u32 dataFrameLength : 16;
        /**
        * DWORD:7   BITS: 31:0  
        * Data Frame Buffer
        * This field contains data frame buffer line address.This field is not valid if dfBuffOperation of dword 5 is set.
        */
         u32 dataFrameBuffer;
        /**
        * DWORD:15:8  
        * Reserved
        */
         u32 reservedDW15_8B31_0[8];
     };
  u32 dw[16];
} flash_read_parameter_page_t ; 
/** 
* @brief Structure declaration for the FlashReadId message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Read ID Address
        * This field encodes the one byte address for the Read ID command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:15:5  
        * Reserved
        */
         u32 reservedDW15_5B31_0[11];
     };
  u32 dw[16];
} flash_read_id_t ; 
/** 
* @brief Structure declaration for the FlashOpCplData message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field encodes the completion message type.
        *- 1 FlashOpCpl
        *- 2 FlashOpCplCont
        *- 3 FlashOpCplData
        *- 4 - 253 Microcode specific
        *- 254 (FlashEccCpl) Flash ECC Completion
        *- 255 (Auto) Hardware auto generated completion message
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Reserved
        */
         u32 reservedDW0B15_12 : 4;
        /**
        * DWORD:0   BITS: 23:16  
        * Number of bytes
        * Number of bytes valid from dword[3]
        */
         u32 size : 8;
        /**
        * DWORD:0   BITS: 31:24  
        * Status
        * This field encodes status of the operation
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 status : 8;
        /**
        * DWORD:2:1  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:3  
        * Return data
        * Return data in bytes
        */
         u32 data[5];
     };
  u32 dw[8];
} flash_op_cpl_data_t ; 
/** 
* @brief Structure declaration for the FlashSetFeat message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Set Feature Address
        * This field encodes the one byte address for the Set Feature command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:5   BITS: 31:0  
        * Sub Feature Parameters
        * This field encodes the sub feature parameters to be set. The parameters P1, P2, P3 and P4 are in order of LSB to MSB.
        */
         u32 parameters;
        /**
        * DWORD:15:6  
        * Reserved
        */
         u32 reservedDW15_6B31_0[10];
     };
  u32 dw[16];
} flash_set_feat_t ; 
/** 
* @brief Structure declaration for the FlashGetFeat message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Get Feature Address
        * This field encodes the one byte address for the Get Feature command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:15:5  
        * Reserved
        */
         u32 reservedDW15_5B31_0[11];
     };
  u32 dw[16];
} flash_get_feat_t ; 
/** 
* @brief Structure declaration for the FlashAddrFormat message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 6:0  
        * Page Number
        * Based on the number of pages in a flash block, the number of bits allocated for page number will change.
        */
         u32 pageNum : 7;
        /**
        * DWORD:0   BITS: 19:7  
        * Block Number
        * Based on the number of blocks in a flash LUN, the number of bits allocated for block number will change.
        */
         u32 blockNum : 13;
        /**
        * DWORD:0   BITS: 23:20  
        * Lun Number
        * Based on the number of LUNs in a flash target, the number of bits allocated for LUN number will change.
        */
         u32 lunNum : 4;
        /**
        * DWORD:0   BITS: 31:24  
        * Reserved
        */
         u32 reservedDW0B31_24 : 8;
     };
  u32 dw[1];
} flash_addr_format_t ; 
/** 
* @brief Structure declaration for the FlashChannelConfigUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 8:4  
        * Number of contexts
        * The number of contexts per flash channel. The flash channel processor supports 16 contexts, allowing up to 16 flash logical units to perform read/program/erase operations in parallel.
        */
         u32 numContext : 5;
        /**
        * DWORD:4   BITS: 12:9  
        * The number of LUNs
        * The number of LUNs per CE.
        */
         u32 numLun : 4;
        /**
        * DWORD:4   BITS: 18:13  
        * The LUN bit position
        * The LUN bit position in the flash address.
        */
         u32 lunBitPosition : 6;
        /**
        * DWORD:4   BITS: 31:19  
        * Reserved
        */
         u32 reservedDW4B31_19 : 13;
        /**
        * DWORD:5   BITS: 15:0  
        * Page Size
        * The flash page size including the spares in DWords
        */
         u32 pageSize : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Reserved
        */
         u32 reservedDW5B31_16 : 16;
        /**
        * DWORD:6   BITS: 3:0  
        * First Context Number
        * The first context number in the flash channel controller.
        */
         u32 _1stContext : 4;
        /**
        * DWORD:6   BITS: 7:4  
        * First Context CE Number
        * Chip enable mapped to the first context
        */
         u32 _1stContextCE : 4;
        /**
        * DWORD:6   BITS: 11:8  
        * First Context LUN Number
        * The first context LUN number within the first context CE
        */
         u32 _1stContextLun : 4;
        /**
        * DWORD:6   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW6B15_12 : 4;
        /**
        * DWORD:6   BITS: 19:16  
        * Second Context Number
        * The second context number in the flash channel controller.
        */
         u32 _2ndContext : 4;
        /**
        * DWORD:6   BITS: 23:20  
        * Second Context CE Number
        * Chip enable mapped to the second context
        */
         u32 _2ndContextCE : 4;
        /**
        * DWORD:6   BITS: 27:24  
        * Second Context LUN Number
        * The second context LUN number within the second context CE
        */
         u32 _2ndContextLun : 4;
        /**
        * DWORD:6   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW6B31_28 : 4;
        /**
        * DWORD:7   BITS: 3:0  
        * Third Context Number
        * The third context in the flash channel controller.
        */
         u32 _3rdContext : 4;
        /**
        * DWORD:7   BITS: 7:4  
        * Third Context CE Number
        * Chip enable mapped to the third context
        */
         u32 _3rdContextCE : 4;
        /**
        * DWORD:7   BITS: 11:8  
        * Third Context LUN Number
        * The third context LUN number within the third context CE
        */
         u32 _3rdContextLun : 4;
        /**
        * DWORD:7   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW7B15_12 : 4;
        /**
        * DWORD:7   BITS: 19:16  
        * Fourth Context Number
        * The fourth context in the flash channel controller.
        */
         u32 _4thContext : 4;
        /**
        * DWORD:7   BITS: 23:20  
        * Fourth Context CE Number
        * Chip enable mapped to the fourth context
        */
         u32 _4thContextCE : 4;
        /**
        * DWORD:7   BITS: 27:24  
        * Fourth Context LUN Number
        * The fourth context LUN number within the fourth context CE
        */
         u32 _4thContextLun : 4;
        /**
        * DWORD:7   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW7B31_28 : 4;
        /**
        * DWORD:8   BITS: 3:0  
        * Fifth Context Number
        * The fifth context in the flash channel controller.
        */
         u32 _5thContext : 4;
        /**
        * DWORD:8   BITS: 7:4  
        * Fifth Context CE Number
        * Chip enable mapped to the fifth context
        */
         u32 _5thContextCE : 4;
        /**
        * DWORD:8   BITS: 11:8  
        * Fifth Context LUN Number
        * The fifth context LUN number within the fifth context CE
        */
         u32 _5thContextLun : 4;
        /**
        * DWORD:8   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW8B15_12 : 4;
        /**
        * DWORD:8   BITS: 19:16  
        * Sixth Context Number
        * The sixth context in the flash channel controller.
        */
         u32 _6thContext : 4;
        /**
        * DWORD:8   BITS: 23:20  
        * Sixth Context CE Number
        * Chip enable mapped to the sixth context
        */
         u32 _6thContextCE : 4;
        /**
        * DWORD:8   BITS: 27:24  
        * Sixth Context LUN Number
        * Thesixth context LUN number within the sixth context CE
        */
         u32 _6thContextLun : 4;
        /**
        * DWORD:8   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW8B31_28 : 4;
        /**
        * DWORD:9   BITS: 3:0  
        * Seventh Context Number
        * The seventh context in the flash channel controller.
        */
         u32 _7thContext : 4;
        /**
        * DWORD:9   BITS: 7:4  
        * Seventh Context CE Number
        * Chip enable mapped to the seventh context
        */
         u32 _7thContextCE : 4;
        /**
        * DWORD:9   BITS: 11:8  
        * Seventh Context LUN Number
        * The seventh context LUN number within the seventh context CE
        */
         u32 _7thContextLun : 4;
        /**
        * DWORD:9   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW9B15_12 : 4;
        /**
        * DWORD:9   BITS: 19:16  
        * Eighth Context Number
        * The eighth context in the flash channel controller.
        */
         u32 _8thContext : 4;
        /**
        * DWORD:9   BITS: 23:20  
        * Eighth Context CE Number
        * Chip enable mapped to the eighth context
        */
         u32 _8thContextCE : 4;
        /**
        * DWORD:9   BITS: 27:24  
        * Eighth Context LUN Number
        * The eighth context LUN number within the eighth context CE
        */
         u32 _8thContextLun : 4;
        /**
        * DWORD:9   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW9B31_28 : 4;
        /**
        * DWORD:10   BITS: 3:0  
        * Ninth Context Number
        * The ninth context in the flash channel controller.
        */
         u32 _9thContext : 4;
        /**
        * DWORD:10   BITS: 7:4  
        * Ninth Context CE Number
        * Chip enable mapped to the ninth context
        */
         u32 _9thContextCE : 4;
        /**
        * DWORD:10   BITS: 11:8  
        * Ninth Context LUN Number
        * The ninth context LUN number within the ninth context CE
        */
         u32 _9thContextLun : 4;
        /**
        * DWORD:10   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW10B15_12 : 4;
        /**
        * DWORD:10   BITS: 19:16  
        * Tenth Context Number
        * The tenth context in the flash channel controller.
        */
         u32 _10thContext : 4;
        /**
        * DWORD:10   BITS: 23:20  
        * Tenth Context CE Number
        * Chip enable mapped to the tenth context
        */
         u32 _10thContextCE : 4;
        /**
        * DWORD:10   BITS: 27:24  
        * Tenth Context LUN Number
        * The tenth context LUN number within the tenth context CE
        */
         u32 _10thContextLun : 4;
        /**
        * DWORD:10   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW10B31_28 : 4;
        /**
        * DWORD:11   BITS: 3:0  
        * Eleventh Context Number
        * The eleventh context in the flash channel controller.
        */
         u32 _11thContext : 4;
        /**
        * DWORD:11   BITS: 7:4  
        * Eleventh Context CE Number
        * Chip enable mapped to the eleventh context
        */
         u32 _11thContextCE : 4;
        /**
        * DWORD:11   BITS: 11:8  
        * Eleventh Context LUN Number
        * The eleventh context LUN number within the eleventh context CE
        */
         u32 _11thContextLun : 4;
        /**
        * DWORD:11   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW11B15_12 : 4;
        /**
        * DWORD:11   BITS: 19:16  
        * Twelfth Context Number
        * The twelfth context in the flash channel controller.
        */
         u32 _12thContext : 4;
        /**
        * DWORD:11   BITS: 23:20  
        * Twelfth Context CE Number
        * Chip enable mapped to the twelfth context
        */
         u32 _12thContextCE : 4;
        /**
        * DWORD:11   BITS: 27:24  
        * Twelfth Context LUN Number
        * The twelfth context LUN number within the twelfth context CE
        */
         u32 _12thContextLun : 4;
        /**
        * DWORD:11   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW11B31_28 : 4;
        /**
        * DWORD:12   BITS: 3:0  
        * Thirteenth Context Number
        * The thirteenth context in the flash channel controller.
        */
         u32 _13thContext : 4;
        /**
        * DWORD:12   BITS: 7:4  
        * Thirteenth Context CE Number
        * Chip enable mapped to the thirteenth context
        */
         u32 _13thContextCE : 4;
        /**
        * DWORD:12   BITS: 11:8  
        * Thirteenth Context LUN Number
        * The thirteenth context LUN number within thirteenth context CE
        */
         u32 _13thContextLun : 4;
        /**
        * DWORD:12   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW12B15_12 : 4;
        /**
        * DWORD:12   BITS: 19:16  
        * Fourteenth Context Number
        * The fourteenth context in the flash channel controller.
        */
         u32 _14thContext : 4;
        /**
        * DWORD:12   BITS: 23:20  
        * Fourteenth Context CE Number
        * Chip enable mapped to the fourteenth context
        */
         u32 _14thContextCE : 4;
        /**
        * DWORD:12   BITS: 27:24  
        * Fourteenth Context LUN Number
        * The fourteenth Context LUN number within the fourteenth context CE
        */
         u32 _14thContextLun : 4;
        /**
        * DWORD:12   BITS: 31:28  
        * Reserved.
        */
         u32 reservedDW12B31_28 : 4;
        /**
        * DWORD:13   BITS: 3:0  
        * Fifteenth Context Number
        * The fifteenth context in the flash channel controller.
        */
         u32 _15thContext : 4;
        /**
        * DWORD:13   BITS: 7:4  
        * Fifteenth Context CE Number
        * Chip enable mapped to the fifteenth context
        */
         u32 _15thContextCE : 4;
        /**
        * DWORD:13   BITS: 11:8  
        * Fifteenth Context LUN Number
        * The fifteenth context LUN number within the fifteenth context CE
        */
         u32 _15thContextLun : 4;
        /**
        * DWORD:13   BITS: 15:12  
        * Reserved.
        */
         u32 reservedDW13B15_12 : 4;
        /**
        * DWORD:13   BITS: 19:16  
        * Sixteenth Context Number
        * The sixteenth context number in the flash channel controller.
        */
         u32 _16thContext : 4;
        /**
        * DWORD:13   BITS: 23:20  
        * Sixteenth Context CE Number
        * Chip enable mapped to the sixteenth context
        */
         u32 _16thContextCE : 4;
        /**
        * DWORD:13   BITS: 27:24  
        * Sixteenth Context LUN Number
        * The sixteenth context LUN number within sixteenth context CE
        */
         u32 _16thContextLun : 4;
        /**
        * DWORD:13   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW13B31_28 : 4;
        /**
        * DWORD:15:14  
        * Reserved
        */
         u32 reservedDW15_14B31_0[2];
     };
  u32 dw[16];
} flash_channel_config_update_t ; 
/** 
* @brief Structure declaration for the FlashEccContextInfoUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the Flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the Flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 7:4  
        * Number of ECC Context Data entries.
        * This field indicates the number of ECC context data entries that are valid.
        */
         u32 numEntries : 4;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:15:5  
        * ECC Context Data
        * This field contain ECC context data such as context number, protected data size, and ECC chunk size.
        */
         u32 eccContextData[11];
     };
  u32 dw[16];
} flash_ecc_context_info_update_t ; 
/** 
* @brief Structure declaration for the EccContextData message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 3:0  
        * ECC Context Number
        */
         u32 eccContextNum : 4;
        /**
        * DWORD:0   BITS: 17:4  
        * ECC Chunk Size
        * This field contains the ECC chunk size in DWords for a given ECC context number
        */
         u32 eccChunkSize : 14;
        /**
        * DWORD:0   BITS: 31:18  
        * Protected Data Size.
        * This field contains the protected data size in DWords for a given ECC context number.
        */
         u32 protectedDataSize : 14;
     };
  u32 dw[1];
} ecc_context_data_t ; 
/** 
* @brief Structure declaration for the FlashTimingParamUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the Flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the Flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 4  
        * Timing Select
        * This field selects the Flash Timing (FT) register used for the Flash operations.
        *- 0 Timing mode 0 selects FT0xxx timing mode register values
        *- 1 Timing mode 1 selects FT1xxx timing mode register values
        */
         u32 timeSel : 1;
        /**
        * DWORD:4   BITS: 31:5  
        * Reserved
        */
         u32 reservedDW4B31_5 : 27;
        /**
        * DWORD:5   BITS: 15:0  
        * Dummy Busy Time
        * This field specifies the dummy busy time (tDBSY) in units of Flash I/O clock cycles.
        */
         u32 dummyBusyTime : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Clock High to R/B Low Time
        * This field specifies the CLK high to R/B low (tWB) in units of Flash I/O clock cycles
        */
         u32 clkHigh2RBLowTime : 16;
        /**
        * DWORD:6   BITS: 31:0  
        * Device Reset Time
        * This field specifies the reset time (tRST) in units of Flash I/O clock cycles
        */
         u32 resetTime;
        /**
        * DWORD:7   BITS: 31:0  
        * Power on Reset Time
        * This field specifies the power on reset time (tPOR) in units of flash I/O clock cycles
        */
         u32 powerOnRstTime;
        /**
        * DWORD:8   BITS: 31:0  
        * Interface Change Time
        * This field specifies the busy time to change interface (tITC) in units of flash I/O clock cycles
        */
         u32 interfaceChangeTime;
        /**
        * DWORD:9   BITS: 31:0  
        * Feature Time
        * This field specifies the Set/Get feature busy time (tFEAT) in units of flash I/O clock cycles
        */
         u32 featureTime;
        /**
        * DWORD:10   BITS: 15:0  
        * Poll Read Time
        * This field specifies the read poll time in units of flash I/O clock cycles
        */
         u32 rdPollTime : 16;
        /**
        * DWORD:10   BITS: 31:16  
        * Poll Write Time
        * This field specifies the program poll time in units of flash I/O clock cycles
        */
         u32 wrPollTime : 16;
        /**
        * DWORD:11   BITS: 15:0  
        * Poll Block Erase Time
        * This field specifies the block erase poll time in units of flash I/O clock cycles
        */
         u32 berPollTime : 16;
        /**
        * DWORD:11   BITS: 31:16  
        * Miscellaneous Polling Time
        * This field specifies the miscellaneous Polling time used by Set/Get Feature, Read Parameter Page commands, etc
        */
         u32 miscPollTime : 16;
        /**
        * DWORD:12   BITS: 7:0  
        * Max Poll Count
        * This field specifies the maximum number of polling retries.
        */
         u32 maxPollCount : 8;
        /**
        * DWORD:12   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW12B31_8 : 24;
        /**
        * DWORD:15:13  
        * Reserved
        */
         u32 reservedDW15_13B31_0[3];
     };
  u32 dw[16];
} flash_timing_param_update_t ; 
/** 
* @brief Structure declaration for the FlashPowerCreditUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 31:4  
        * Reserved
        */
         u32 reservedDW4B31_4 : 28;
        /**
        * DWORD:5   BITS: 15:0  
        * Read Power Credit
        * This field specifies the power units for the Read command, which includes the flash array read power and I/O burst read power.
        */
         u32 readPowerCredit : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Program Power Credit
        * This field specifies the power units for the Program command, which includes the flash array program power and I/O burst read power.
        */
         u32 programPowerCredit : 16;
        /**
        * DWORD:6   BITS: 15:0  
        * Erase Power Credit
        * This field specifies the power units for the erase command.
        */
         u32 erasePowerCredit : 16;
        /**
        * DWORD:6   BITS: 31:16  
        * Miscellaneous Power Credit
        * This specifies the maximum power used by any other commands like Read Status, Set Feature, Get feature, etc
        */
         u32 miscPowerCredit : 16;
        /**
        * DWORD:15:7  
        * Reserved
        */
         u32 reservedDW15_7B31_0[9];
     };
  u32 dw[16];
} flash_power_credit_update_t ; 
/** 
* @brief Structure declaration for the FlashDynamicUpdate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 3:0  
        * Sub Message type
        * This field encodes the request sub message type. The value of this field is microcode specific.
        *- 1 (ChannelConfig) Flash Channel Configuration update
        *- 2 (ECCContextInfo) Flash ECC Context information update
        *- 3 (TimerParam) Flash Timing Parameter update
        *- 4 (PowerCredit) Flash Power Credit update
        *- 5 (Dynamic) Flash Dynamic Parameters update
        */
         u32 subMsgType : 4;
        /**
        * DWORD:4   BITS: 31:4  
        * Reserved
        */
         u32 reservedDW4B31_4 : 28;
        /**
        * DWORD:5   BITS: 15:0  
        * High Priority Poll Limit
        * This field specifies the poll limit for the high priority message processing.
        */
         u32 highPriorPollLimit : 16;
        /**
        * DWORD:5   BITS: 31:16  
        * Reserved
        */
         u32 reservedDW5B31_16 : 16;
        /**
        * DWORD:15:6  
        * Reserved
        */
         u32 reservedDW15_6B31_0[10];
     };
  u32 dw[16];
} flash_dynamic_update_t ; 
/** 
* @brief Structure declaration for the ReadHeader message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 6:0  
        * Reserved
        */
         u32 reservedDW0B6_0 : 7;
        /**
        * DWORD:0   BITS: 9:7  
        * Start ECC chunk
        * The index of the first ECC chunk that is part of the read operation.
        */
         u32 startECCChunk : 3;
        /**
        * DWORD:0   BITS: 10:10  
        * Reserved
        */
         u32 reservedDW0B10_10 : 1;
        /**
        * DWORD:0   BITS: 15:11  
        * Number of ECC Headers
        * The number of ECC headers following the read header that help describe the read operation. This number must be non-zero.
        */
         u32 numECCHeaders : 5;
        /**
        * DWORD:0   BITS: 30:16  
        * Page Offset
        * The starting location (in dwords) for the read operation. This is also the column address.
        */
         u32 pageOffset : 15;
        /**
        * DWORD:0   BITS: 31:31  
        * Reserved
        */
         u32 reservedDW0B31_31 : 1;
     };
  u32 dw[1];
} read_header_t ; 
/** 
* @brief Structure declaration for the ECC code rate message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 0  
        * Plane Number
        * The plane number of the current read operation. It may not be physical plane number. The microcode uses this field to get the corresponding flash address provided in the flash read message.
        */
         u32 planeNum : 1;
        /**
        * DWORD:0   BITS: 3:1  
        * Number of buffers
        * The number of data frame buffers involved with the current read header.
        */
         u32 numBuffers : 3;
        /**
        * DWORD:0   BITS: 6:4  
        * Number of ECC Chunks
        * The number of ECC chunks involved with the current read header. The value 0 indicates a raw mode access.
        */
         u32 numECCChunk : 3;
        /**
        * DWORD:0   BITS: 7  
        * last Buffer Spans
        * The last buffer straddles two planes and requires two operations to be fully accessed.
        */
         u32 lastBufferSpans : 1;
        /**
        * DWORD:0   BITS: 9:8  
        * Reserved
        */
         u32 reservedDW0B9_8 : 2;
        /**
        * DWORD:0   BITS: 20:10  
        * The size (in dwords) of the ECC chunk.
        */
         u32 sizeECCChunk : 11;
        /**
        * DWORD:0   BITS: 31:21  
        * The size (in dwords) of the protected data within the ECC chunk.
        */
         u32 sizeProtData : 11;
     };
  u32 dw[1];
} e_c_c code rate_t ; 
/** 
* @brief Structure declaration for the WriteHeader message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 0  
        * Plane Number
        * The plane number of the current write header. It may not be physical plane number. The microcode uses this field to get the corresponding flash address provided in the flash write message.
        */
         u32 planeNum : 1;
        /**
        * DWORD:0   BITS: 3:1  
        * Number of buffers
        * The number of data frame buffers involved with the current write header.
        */
         u32 numBuffers : 3;
        /**
        * DWORD:0   BITS: 6:4  
        * Number of ECC Chunks
        * The number of ECC chunks involved with the current write header. The value 0 indicates a raw mode access.
        */
         u32 numECCChunk : 3;
        /**
        * DWORD:0   BITS: 9:7  
        * Start ECC chunk
        * The index of the first ECC chunk that is part of the write operation.
        */
         u32 startECCChunk : 3;
        /**
        * DWORD:0   BITS: 20:10  
        * The size (in dwords) of the ECC chunk.
        */
         u32 sizeECCChunk : 11;
        /**
        * DWORD:0   BITS: 31:21  
        * The size (in dwords) of the protected data within the ECC chunk.
        */
         u32 sizeProtData : 11;
     };
  u32 dw[1];
} write_header_t ; 
/** 
* @brief Structure declaration for the FlashRead message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:5:4  
        * Flash Address
        * This field encodes the physical flash address of the page to be read for different planes.
        */
         u32 flashAddr[2];
        /**
        * DWORD:6   BITS: 3:0  
        * ECC Code Rate Index
        * This field specifies the ECC code rate index used for ECC encode and decode operations
        * An ECC code rate index of 15 is used for the dynamic code rate format.
        */
         u32 eccCodeRateIndex : 4;
        /**
        * DWORD:6   BITS: 7:4  
        * Reserved
        */
         u32 reservedDW6B7_4 : 4;
        /**
        * DWORD:6   BITS: 15:8  
        * Max Iterations
        * This field specifies the maximum number of iterations to be completed before the LDPC decoder declares an uncorrectable ECC error.
        * A value of zero means 256 iterations.
        * The value of this field is ignored during raw bulk data transfers and ECC encode operations
        */
         u32 maxIter : 8;
        /**
        * DWORD:6   BITS: 23:16  
        * Log Likelihood Ratio for a Received Zero
        * This field contains the Log Likelihood Ratio (LLR) used by LDPC decode operations for a bit value of zero read from NAND.
        * The LLR is six bits in size. The value of the top two bits of this field is ignored.
        * The value of this field is ignored during raw bulk data transfers and ECC encode operations
        */
         u32 lLR0 : 8;
        /**
        * DWORD:6   BITS: 31:24  
        * Log Likelihood Ratio for a Received One
        * This field contains the Log Likelihood Ratio (LLR) used by LDPC decode operations for a bit value of one read from NAND.
        * The LLR is six bits in size. The value of the top two bits of this field is ignored.
        * The value of this field is ignored during raw bulk data transfers and ECC encode operations
        */
         u32 lLR1 : 8;
        /**
        * DWORD:7   BITS: 15:0  
        * Scrambler Seed
        * This field contains the seed value used by the scrambler.
        */
         u32 scramblerSeed : 16;
        /**
        * DWORD:7   BITS: 23:16  
        * Read Retry Option
        * This field contains the read retry option to be used during NAND read operation.
        */
         u32 readRetry : 8;
        /**
        * DWORD:7   BITS: 27:24  
        * Number Of Planes
        * This field indicates the number of planes involved in current operation.
        */
         u32 numPlane : 4;
        /**
        * DWORD:7   BITS: 28  
        * Data Frame Buffer Operation
        *- 0 - Don't allocate data frame buffer
        *- 1 - Allocate data frame buffer.
        */
         u32 dfBuffOperation : 1;
        /**
        * DWORD:7   BITS: 30:29  
        * Reserved
        */
         u32 reservedDW7B30_29 : 2;
        /**
        * DWORD:7   BITS: 31  
        * Block Type
        *- 0 - MLC
        *- 1 - SLC
        */
         u32 blockType : 1;
        /**
        * DWORD:8   BITS: 23:0  
        * Page Read Time
        * This field specifies the page read time in units of flash controller clock cycles
        */
         u32 pageReadTime : 24;
        /**
        * DWORD:8   BITS: 31:24  
        * Read Header Count
        * This field contains the number of read headers involved in the current read operation
        */
         u32 readHdrCount : 8;
        /**
        * DWORD:9   BITS: 15:0  
        * First Data Frame Offset
        * This field contains the first data frame buffer dword offset.
        * When the data frame spanned two physical pages, the first data frame buffer offset represents the offset of the first data frame buffer to transfer the data.
        */
         u32 firstDFOffset : 16;
        /**
        * DWORD:9   BITS: 31:16  
        * Data Frame Length
        * This field contains the data frame length in dwords.
        */
         u32 dataFrameLength : 16;
        /**
        * DWORD:10   BITS: 31:0  
        * Raw Buffer
        * This field contains the raw buffer line address.
        * The raw buffer address is used when there is a ECC error. Raw data (ECC chunk data) is transferred to the raw buffer if a raw buffer is given. Otherwise, raw data is dropped and never transferred to the CMU. A non-zero value indicates a raw buffer is given.
        */
         u32 rawBuffer;
        /**
        * DWORD:11   BITS: 31:0  
        * Read Header
        * This field contains the read header.
        */
         u32 readHeader0;
        /**
        * DWORD:12   BITS: 31:0  
        * ECC Header
        * This field contains an ECC header
        */
         u32 eccHeader0;
        /**
        * DWORD:13   BITS: 31:0  
        * Data Frame Buffer 0
        * This field contains the data frame buffer line address
        */
         u32 dataFrameBuffer0;
        /**
        * DWORD:14   BITS: 31:0  
        * Read Message DWord 14
        * Depending on the number of buffers in the ECC HeaderX, this field contains another read header or a data frame buffer line address
        */
         u32 readMsgDW14;
        /**
        * DWORD:15   BITS: 31:0  
        * Read Message DWord 15
        * Depending on the number of buffers in the ECC HeaderX, this field contains another read header, an ECC header or the data frame buffer line address
        */
         u32 readMsgDW15;
     };
  u32 dw[16];
} flash_read_t ; 
/** 
* @brief Structure declaration for the FlashWrite message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 20:17  
        * Reserved
        */
         u32 reservedDW0B20_17 : 4;
        /**
        * DWORD:0   BITS: 29:21  
        * XOR Calculator ID
        * This field specifies the XOR calculator flow ID.
        * The value of this field is ignored when the XORCalcOp field value is set to NOP.
        * The XOR Calculator ID field is translated when processed by the XOR calculator. When received by a Flash channel processor, this field contains the XOR context ID.
        */
         u32 xorCalcID : 9;
        /**
        * DWORD:0   BITS: 30  
        * Last Request of a XOR Calculator Flow ID Stripe
        * This field indicates whether this is the last request of a Flow ID stripe.
        *- 0 (NOTLAST) First or middle operation of a Flow ID stripe
        *- 1 (LAST) Last operation of a Flow ID stripe
        * The value of this field is ignored then the XORCalcOp field value is set to NOP.
        */
         u32 xorCalcStripeLast : 1;
        /**
        * DWORD:0   BITS: 31  
        * XOR Calculation Operation
        * This field encodes
        * whether a XOR calculator operation is perform as a side effect of request message processing.
        *- 0 (NOP) No operation
        *- 1 (XORCALC) XOR calculator operation
        */
         u32 xorCalcOp : 1;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:5:4  
        * Flash Address
        * This field encodes the physical flash address of the page to be written for different planes.
        */
         u32 flashAddr[2];
        /**
        * DWORD:6   BITS: 3:0  
        * ECC Code Rate Index
        * This field specifies the ECC code rate index used for ECC encode and decode operations
        * An ECC code rate index of 15 is used for the dynamic code rate format.
        */
         u32 eccCodeRateIndex : 4;
        /**
        * DWORD:6   BITS: 31:4  
        * Reserved
        */
         u32 reservedDW6B31_4 : 28;
        /**
        * DWORD:7   BITS: 15:0  
        * Scrambler Seed
        * This field contains the seed value used by the scrambler .
        */
         u32 scramblerSeed : 16;
        /**
        * DWORD:7   BITS: 23:16  
        * Reserved
        */
         u32 reservedDW7B23_16 : 8;
        /**
        * DWORD:7   BITS: 27:24  
        * Number Of Planes
        * This field indicates the number of planes involved in the current operation.
        */
         u32 numPlane : 4;
        /**
        * DWORD:7   BITS: 28  
        * Data Frame Buffer Operation
        *- 0 - Don't free the data frame buffer
        *- 1 - Free the data frame buffer after successful flash operation.
        */
         u32 dfBuffOperation : 1;
        /**
        * DWORD:7   BITS: 30:29  
        * Reserved
        */
         u32 reservedDW7B30_29 : 2;
        /**
        * DWORD:7   BITS: 31  
        * Block Type
        *- 0 - MLC
        *- 1 - SLC
        */
         u32 blockType : 1;
        /**
        * DWORD:8   BITS: 23:0  
        * Page Program Time
        * This field specifies the page program time in units of flash controller clock cycles
        */
         u32 pageProgTime : 24;
        /**
        * DWORD:8   BITS: 31:24  
        * Write Header Count
        * This field contains the number of write headers involved in the current write operation
        */
         u32 writeHdrCount : 8;
        /**
        * DWORD:9   BITS: 15:0  
        * First Data Frame Offset
        * This field contains the first data frame buffer dword offset.
        * When the data frame spanned two physical pages, the first data frame buffer offset represents offset of the first data frame buffer to transfer the data.
        */
         u32 firstDFOffset : 16;
        /**
        * DWORD:9   BITS: 31:16  
        * Data Frame Length
        * This field contains the data frame length in dwords.
        */
         u32 dataFrameLength : 16;
        /**
        * DWORD:10   BITS: 31:0  
        * Write header 0
        * This field contains the write header.
        */
         u32 writeHeader0;
        /**
        * DWORD:11   BITS: 31:0  
        * Data Frame Buffer 0
        * This field contains the first data frame buffer line address
        */
         u32 dataFrameBuffer0;
        /**
        * DWORD:12   BITS: 31:0  
        * Write Message DWord 12
        * Depending on the number of buffers in the writeHeaderX, this field contains another write header or a data frame buffer line address
        */
         u32 writeMsgDW12;
        /**
        * DWORD:13   BITS: 31:0  
        * Write Message DWord 13
        * Depending on the number of buffers in the writeHeaderX, this field contains another write header or the data frame buffer line address
        */
         u32 writeMsgDW13;
        /**
        * DWORD:14   BITS: 31:0  
        * Write Message DWord 14
        * Depending on the number of buffers in the writeHeaderX, this field contains another write header or a data frame buffer line address
        */
         u32 writeMsgDW14;
        /**
        * DWORD:15   BITS: 31:0  
        * Write Message DWord 15
        * Depending on the number of buffers in the writeHeaderX, this field contains another write header or the data frame buffer line address
        */
         u32 writeMsgDW15;
     };
  u32 dw[16];
} flash_write_t ; 
/** 
* @brief Structure declaration for the FlashCont message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:15:2  
        * Depending on number of buffers in readHeaderX/WriteHeaderX, this field contain another read header/write header, ECC code rate, or a data frame buffer line address.
        */
         u32 contHeader[14];
     };
  u32 dw[16];
} flash_cont_t ; 
/** 
* @brief Structure declaration for the FlashErase message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:5:4  
        * Flash Address
        * This field encodes the physical flash address of the page to be erased.
        */
         u32 flashAddr[2];
        /**
        * DWORD:6   BITS: 31:0  
        * Reserved
        */
         u32 reservedDW6B31_0;
        /**
        * DWORD:7   BITS: 23:0  
        * Reserved
        */
         u32 reservedDW7B23_0 : 24;
        /**
        * DWORD:7   BITS: 27:24  
        * Number Of Planes
        * This field indicates the number of planes involved in the current operation.
        */
         u32 numPlane : 4;
        /**
        * DWORD:7   BITS: 30:28  
        * Reserved.
        */
         u32 reservedDW7B30_28 : 3;
        /**
        * DWORD:7   BITS: 31  
        * Block Type
        *- 0 - MLC
        *- 1 - SLC
        */
         u32 blockType : 1;
        /**
        * DWORD:8   BITS: 23:0  
        * Block Erase Time
        * This field specifies the block erase time in units of flash controller clock cycles.
        * The erase Polling time is fixed in Microcode.
        */
         u32 blockEraseTime : 24;
        /**
        * DWORD:8   BITS: 31:24  
        * Reserved
        */
         u32 reservedDW8B31_24 : 8;
        /**
        * DWORD:15:11  
        * Reserved
        */
         u32 reservedDW15_11B31_0[5];
     };
  u32 dw[16];
} flash_erase_t ; 
/** 
* @brief Structure declaration for the FlashOpCpl message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field encodes the completion message type.
        *- 1 FlashOpCpl
        *- 2 FlashOpCplCont
        *- 3 FlashOpCplData
        *- 4 - 253 Microcode specific
        *- 254 (FlashEccCpl) Flash ECC Completion
        *- 255 (Auto) Hardware auto generated completion message
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Outbound Message Queue
        * This field specifies the index of the Flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Reserved
        */
         u32 reservedDW0B15_12 : 4;
        /**
        * DWORD:0   BITS: 19:16  
        * Status
        * This field encodes global status of the operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 status : 4;
        /**
        * DWORD:0   BITS: 20  
        * Erased Page
        * This bit is set if the percentage of bits in the ECC Chunk prior to LDPC correction that had a value of one was greater than the threshold specified by the erased page ECC chunk threshold (ERASEDTH) field in the ECC Control (ECCCTL) register.
        */
         u32 erasedPage : 1;
        /**
        * DWORD:0   BITS: 23:21  
        * Plane Number
        * Plane number for which this completion belongs
        */
         u32 planeNum : 3;
        /**
        * DWORD:0   BITS: 31:24  
        * Number Retries
        * If the status field indicates completion without error , then this field contains the total number poll retries required before it was determined that the flash operation completed. In all other cases, the contents of this field are undefined. A value of zero in this field indicates that no retries were required and that the Flash device indicated completion the first time it was polledNumber of Planes
        */
         u32 retries : 8;
        /**
        * DWORD:2:1  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:3   BITS: 31:0  
        * Plane Completion Information
        * The plane completion information varies for flash read/ flash write/flash erase messages. Refer to the discusssion of FlashRdPlaneCplInfo and FlashWrErPlaneCplInfo for the format of this dword.
        */
         u32 planeCplInfo;
        /**
        * DWORD:4   BITS: 15:0  
        * ECC Chunk Error Vector
        * Error vector for a total of 8 chunks. Each error chunk information is 2 bits.
        *- 0 (OK) Operation completed without error
        *- 1 (EccErr) Uncorrectable ECC error detected
        *- 2 (CrcErr) CRC mismatch
        *- 3 (ScramblerErr) Scrambler seed mismatch
        */
         u32 eccChunkErrVector : 16;
        /**
        * DWORD:4   BITS: 19:16  
        * Plane Max ZErrM
        * The maximum number of ZErrM bit errors in a specific ECC chunk within this plane.
        */
         u32 planeMaxZErrM : 4;
        /**
        * DWORD:4   BITS: 23:20  
        * Max ZErrM chunk Number
        * The ECC chunk number that contains the most ZErrM bit errors within this plane.
        */
         u32 maxZErrMChunkNum : 4;
        /**
        * DWORD:4   BITS: 31:24  
        * Plane Total ZErrM
        * The total number of ZErrM bit errors accumulated over all the ECC chunks within this plane
        */
         u32 planeTotalZErrM : 8;
        /**
        * DWORD:5   BITS: 31:0  
        * Data Buffer Type
        * This field contains the data frame buffer type for allocated buffers in current plane.
        * Note: When a data frame buffer is not allocated, this field is reserved.
        */
         u32 dataFrameBuffType;
        /**
        * DWORD:7:6  
        * Data Frame Buffer Controller Memory Line Address
        * This field contains the controller memory line address that points to the start of data frame 0. The memory line address is equal to the 37-bit controller memory byte address of the memory line shifted right six bits.
        * Note: When a data frame buffer is not allocated, this field is reserved.
        */
         u32 dfBuf[2];
     };
  u32 dw[8];
} flash_op_cpl_t ; 
/** 
* @brief Structure declaration for the FlashRdPlaneCplInfo message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 11:0  
        * Plane Max ECC Errors
        * The maximum number of ECC bit errors in a specific ECC chunk within this plane
        */
         u32 planeMaxEccErrors : 12;
        /**
        * DWORD:0   BITS: 15:12  
        * Max Error Chunk Number
        * The ECC chunk number that contains the most ECC bit errors within this plane
        */
         u32 maxErrorChunkNum : 4;
        /**
        * DWORD:0   BITS: 31:16  
        * Plane Total ECC Errors
        * The total number of ECC bit errors accumulated over all the ECC chunks within this plane
        */
         u32 planeTotalEccErrors : 16;
     };
  u32 dw[1];
} flash_rd_plane_cpl_info_t ; 
/** 
* @brief Structure declaration for the FlashWrErPlaneCplInfo message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 3:0  
        * Plane 0 Status
        * This field encodes the status of the plane 0 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane0status : 4;
        /**
        * DWORD:0   BITS: 7:4  
        * Plane 1 Status
        * This field encodes the status of the plane 1 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane1status : 4;
        /**
        * DWORD:0   BITS: 11:8  
        * Plane 2 Status
        * This field encodes the status of the plane 2 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane2status : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Plane 3 Status
        * This field encodes the status of the plane 3 operation:
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 4 (EccErr) Uncorrectable ECC error detected
        *- 5 (CrcErr) CRC mismatch
        *- 6 (ScramblerErr) Scrambler seed mismatch
        *- 7 (XferSzErr) Transfer size error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 plane3status : 4;
        /**
        * DWORD:0   BITS: 31:16  
        * Reserved
        */
         u32 reservedDW0B31_16 : 16;
     };
  u32 dw[1];
} flash_wr_er_plane_cpl_info_t ; 
/** 
* @brief Structure declaration for the FlashOpCplCont message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field encodes the completion message type.
        *- 1 FlashOpCpl
        *- 2 FlashOpCplCont
        *- 3 FlashOpCplData
        *- 4 - 253 Microcode specific
        *- 254 (FlashEccCpl) Flash ECC Completion
        *- 255 (Auto) Hardware auto generated completion message
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:0   BITS: 20:12  
        * Reserved
        */
         u32 reservedDW0B20_12 : 9;
        /**
        * DWORD:0   BITS: 23:21  
        * Plane Number
        * The plane number associated with the current completion.
        */
         u32 planeNum : 3;
        /**
        * DWORD:0   BITS: 31:24  
        * Reserved
        */
         u32 reservedDW0B31_24 : 8;
        /**
        * DWORD:2:1  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:3  
        * Data Frame Buffer Controller Memory Line Address
        * This field contains the controller memory line address that points to the start of data frame 0. The memory line address is equal to the 37-bit controller memory byte address of the memory line shifted right six bits.
        */
         u32 dfBuf[5];
     };
  u32 dw[8];
} flash_op_cpl_cont_t ; 
/** 
* @brief Structure declaration for the FlashMemWrite message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field must be set to a value of 255 in a flashMemWriterequest message.
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Number of dwords contained in the message request
        * This field specifies the number of valid dwords in this message request. The values zero as well as 13 through 16 are reserved and causes the message to be discarded.
        */
         u32 numDwords : 4;
        /**
        * DWORD:0   BITS: 31:12  
        * Reserved
        */
         u32 reservedDW0B31_12 : 20;
        /**
        * DWORD:1   BITS: 31:0  
        * Flash Channel Processor Multicast Vector
        * Each bit in this field corresponds to a flash channel processor (i.e., bit zero corresponds to flash channel processor zero, bit one corresponds to flash channel processor one, and so on). When a bit in this field set, the message request is sent to the corresponding flash channel processor.
        */
         u32 multicastVector;
        /**
        * DWORD:2   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW2B1_0 : 2;
        /**
        * DWORD:2   BITS: 31:2  
        * Flash Channel Processor Address
        * This field specifies the starting dword address location in Flash Channel Processor address space (i.e.,D-Mem or I-Mem) where the data contained in this message is written.
        */
         u32 flashChProcAddr : 30;
        /**
        * DWORD:3   BITS: 31:0  
        * Data DWord 0
        */
         u32 dataDWord0;
        /**
        * DWORD:4   BITS: 31:0  
        * Data DWord 1
        */
         u32 dataDWord1;
        /**
        * DWORD:5   BITS: 31:0  
        * Data DWord 2
        */
         u32 dataDWord2;
        /**
        * DWORD:6   BITS: 31:0  
        * Data DWord 3
        */
         u32 dataDWord3;
        /**
        * DWORD:7   BITS: 31:0  
        * Data DWord 4
        */
         u32 dataDWord4;
        /**
        * DWORD:8   BITS: 31:0  
        * Data DWord 5
        */
         u32 dataDWord5;
        /**
        * DWORD:9   BITS: 31:0  
        * Data DWord 6
        */
         u32 dataDWord6;
        /**
        * DWORD:10   BITS: 31:0  
        * Data DWord 7
        */
         u32 dataDWord7;
        /**
        * DWORD:11   BITS: 31:0  
        * Data DWord 8
        */
         u32 dataDWord8;
        /**
        * DWORD:12   BITS: 31:0  
        * Data DWord 9
        */
         u32 dataDWord9;
        /**
        * DWORD:13   BITS: 31:0  
        * Data DWord 10
        */
         u32 dataDWord10;
        /**
        * DWORD:14   BITS: 31:0  
        * Data DWord 11
        */
         u32 dataDWord11;
        /**
        * DWORD:15   BITS: 31:0  
        * Reserved
        */
         u32 reservedDW15B31_0;
     };
  u32 dw[16];
} flash_mem_write_t ; 
/** 
* @brief Structure declaration for the FlashReadParameterPage message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes theflash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Read Parameter Page Address
        * This field encodes the one byte address for the Read Parameter page command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Page Read Time
        * This field specifies the page read time in units of flash controller clock cycles
        */
         u32 pageReadTime : 24;
        /**
        * DWORD:5   BITS: 0  
        * Data Frame Buffer Operation
        *- 0 - Don't allocate data frame buffer
        *- 1 - Allocate data frame buffer.
        */
         u32 dfBuffOperation : 1;
        /**
        * DWORD:5   BITS: 31:1  
        * Reserved
        */
         u32 reservedDW5B31_1 : 31;
        /**
        * DWORD:6   BITS: 15:0  
        * Start Page Offset
        * This field contains the start dword offset to read parameters
        */
         u32 startOffset : 16;
        /**
        * DWORD:6   BITS: 31:16  
        * Data Frame Length
        * This field contains the data frame length in dwords.
        */
         u32 dataFrameLength : 16;
        /**
        * DWORD:7   BITS: 31:0  
        * Data Frame Buffer
        * This field contains data frame buffer line address.This field is not valid if dfBuffOperation of dword 5 is set.
        */
         u32 dataFrameBuffer;
        /**
        * DWORD:15:8  
        * Reserved
        */
         u32 reservedDW15_8B31_0[8];
     };
  u32 dw[16];
} flash_read_parameter_page_t ; 
/** 
* @brief Structure declaration for the FlashReadId message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Read ID Address
        * This field encodes the one byte address for the Read ID command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:15:5  
        * Reserved
        */
         u32 reservedDW15_5B31_0[11];
     };
  u32 dw[16];
} flash_read_id_t ; 
/** 
* @brief Structure declaration for the FlashOpCplData message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message Type
        * This field encodes the completion message type.
        *- 1 FlashOpCpl
        *- 2 FlashOpCplCont
        *- 3 FlashOpCplData
        *- 4 - 253 Microcode specific
        *- 254 (FlashEccCpl) Flash ECC Completion
        *- 255 (Auto) Hardware auto generated completion message
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:0   BITS: 15:12  
        * Reserved
        */
         u32 reservedDW0B15_12 : 4;
        /**
        * DWORD:0   BITS: 23:16  
        * Number of bytes
        * Number of bytes valid from dword[3]
        */
         u32 size : 8;
        /**
        * DWORD:0   BITS: 31:24  
        * Status
        * This field encodes status of the operation
        *- 0 (OK) Operation completed without error
        *- 1 (Disabled) Unit is disabled
        *- 2 (Malformed) Malformed request
        *- 3 (FatalError) Fatal Error
        *- 8 (FlashErr) Flash error
        *- 9 (DIErr) Data integrity error
        *- 10 (ProcError) Processing Error
        *- 11 (PollingError) Polling Error
        *- 13 (Conflict) Conflicting messages
        *- 14 (Aborted) Operation aborted
        *- 15 (TargetError) Target Error
        */
         u32 status : 8;
        /**
        * DWORD:2:1  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:7:3  
        * Return data
        * Return data in bytes
        */
         u32 data[5];
     };
  u32 dw[8];
} flash_op_cpl_data_t ; 
/** 
* @brief Structure declaration for the FlashSetFeat message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of the flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Set Feature Address
        * This field encodes the one byte address for the Set Feature command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:5   BITS: 31:0  
        * Sub Feature Parameters
        * This field encodes the sub feature parameters to be set. The parameters P1, P2, P3 and P4 are in order of LSB to MSB.
        */
         u32 parameters;
        /**
        * DWORD:15:6  
        * Reserved
        */
         u32 reservedDW15_6B31_0[10];
     };
  u32 dw[16];
} flash_set_feat_t ; 
/** 
* @brief Structure declaration for the FlashGetFeat message
*/
 typedef union
  {
  struct
      { 
        /**
        * DWORD:0   BITS: 7:0  
        * Message type
        * This field encodes the request message type. The value of this field is microcode specific.
        *- 1 (Read) Flash Read
        *- 2 (Write) Flash Write
        *- 3 (Erase) Flash Block Erase
        *- 4 (Continue) Flash Continuous Request
        *- 5 (FlashConfig) Flash Configuration update
        *- 6 (ReadParamPg) Flash Read Parameter Page
        *- 7 (ReadId) Flash Read Id
        *- 8 (SetFeature) Flash Set Feature
        *- 9 (GetFeature) Flash Get Feature
        */
         u32 msgType : 8;
        /**
        * DWORD:0   BITS: 11:8  
        * Flash Channel Queue
        * This field encodes the flash channel queue associated with this message request.
        */
         u32 cntxt : 4;
        /**
        * DWORD:0   BITS: 16:12  
        * Flash Channel
        * This field encodes the flash channel associated with this message request.
        */
         u32 chan : 5;
        /**
        * DWORD:0   BITS: 31:17  
        * Reserved
        */
         u32 reservedDW0B31_17 : 15;
        /**
        * DWORD:1   BITS: 1:0  
        * Reserved
        */
         u32 reservedDW1B1_0 : 2;
        /**
        * DWORD:1   BITS: 18:2  
        * Chained Message Node Address
        * This field contains the node address of the next request message in the message chain. A value of zero in this field indicates that this is the last message of a message chain.
        */
         u32 chMsgNodeAddr : 17;
        /**
        * DWORD:1   BITS: 19  
        * Chained Message
        * When this bit is set, the request message is part of a chained message and is not the last message in the message chain. The address of the next request message in the message chain is specified by the chMsgNodeAddr field.
        */
         u32 chain : 1;
        /**
        * DWORD:1   BITS: 23:20  
        * Reserved
        */
         u32 reservedDW1B23_20 : 4;
        /**
        * DWORD:1   BITS: 27:24  
        * Outbound Message Queue
        * This field specifies the index of flash completion outbound message queue to be used by this message.
        */
         u32 outMsgQ : 4;
        /**
        * DWORD:1   BITS: 31:28  
        * Reserved
        */
         u32 reservedDW1B31_28 : 4;
        /**
        * DWORD:3:2  
        * Tag
        * This field contains opaque data that is passed from the request to the corresponding completion.
        */
         u32 tag[2];
        /**
        * DWORD:4   BITS: 7:0  
        * Get Feature Address
        * This field encodes the one byte address for the Get Feature command.
        */
         u32 address : 8;
        /**
        * DWORD:4   BITS: 31:8  
        * Reserved
        */
         u32 reservedDW4B31_8 : 24;
        /**
        * DWORD:15:5  
        * Reserved
        */
         u32 reservedDW15_5B31_0[11];
     };
  u32 dw[16];
} flash_get_feat_t ; 
/** 
* @brief Bit definitions
*/
 #define FLASH_ADDR_FORMAT_PAGENUM_LSB 0
  #define FLASH_ADDR_FORMAT_PAGENUM_MSB 6
  #define FLASH_ADDR_FORMAT_BLOCKNUM_LSB 7
  #define FLASH_ADDR_FORMAT_BLOCKNUM_MSB 19
  #define FLASH_ADDR_FORMAT_LUNNUM_LSB 20
  #define FLASH_ADDR_FORMAT_LUNNUM_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE_MSGTYPE_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE_MSGTYPE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE_CNTXT_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE_CNTXT_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAN_LSB 12
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAN_MSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAIN_LSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAIN_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMCONTEXT_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMCONTEXT_MSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMLUN_LSB 9
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMLUN_MSB 12
  #define FLASH_CHANNEL_CONFIG_UPDATE_LUNBITPOSITION_LSB 13
  #define FLASH_CHANNEL_CONFIG_UPDATE_LUNBITPOSITION_MSB 18
  #define FLASH_CHANNEL_CONFIG_UPDATE_PAGESIZE_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE_PAGESIZE_MSB 15
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTLUN_MSB 27
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_MSGTYPE_LSB 0
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_MSGTYPE_MSB 7
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CNTXT_LSB 8
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CNTXT_MSB 11
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAN_LSB 12
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAN_MSB 16
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAIN_LSB 19
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAIN_MSB 19
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_NUMENTRIES_LSB 4
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_NUMENTRIES_MSB 7
  #define ECC_CONTEXT_DATA_ECCCONTEXTNUM_LSB 0
  #define ECC_CONTEXT_DATA_ECCCONTEXTNUM_MSB 3
  #define ECC_CONTEXT_DATA_ECCCHUNKSIZE_LSB 4
  #define ECC_CONTEXT_DATA_ECCCHUNKSIZE_MSB 17
  #define ECC_CONTEXT_DATA_PROTECTEDDATASIZE_LSB 18
  #define ECC_CONTEXT_DATA_PROTECTEDDATASIZE_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_MSGTYPE_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_MSGTYPE_MSB 7
  #define FLASH_TIMING_PARAM_UPDATE_CNTXT_LSB 8
  #define FLASH_TIMING_PARAM_UPDATE_CNTXT_MSB 11
  #define FLASH_TIMING_PARAM_UPDATE_CHAN_LSB 12
  #define FLASH_TIMING_PARAM_UPDATE_CHAN_MSB 16
  #define FLASH_TIMING_PARAM_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_TIMING_PARAM_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_TIMING_PARAM_UPDATE_CHAIN_LSB 19
  #define FLASH_TIMING_PARAM_UPDATE_CHAIN_MSB 19
  #define FLASH_TIMING_PARAM_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_TIMING_PARAM_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_TIMING_PARAM_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_TIMING_PARAM_UPDATE_TIMESEL_LSB 4
  #define FLASH_TIMING_PARAM_UPDATE_TIMESEL_MSB 4
  #define FLASH_TIMING_PARAM_UPDATE_DUMMYBUSYTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_DUMMYBUSYTIME_MSB 15
  #define FLASH_TIMING_PARAM_UPDATE_CLKHIGH2RBLOWTIME_LSB 16
  #define FLASH_TIMING_PARAM_UPDATE_CLKHIGH2RBLOWTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_RESETTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_RESETTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_POWERONRSTTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_POWERONRSTTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_INTERFACECHANGETIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_INTERFACECHANGETIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_FEATURETIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_FEATURETIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_RDPOLLTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_RDPOLLTIME_MSB 15
  #define FLASH_TIMING_PARAM_UPDATE_WRPOLLTIME_LSB 16
  #define FLASH_TIMING_PARAM_UPDATE_WRPOLLTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_BERPOLLTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_BERPOLLTIME_MSB 15
  #define FLASH_TIMING_PARAM_UPDATE_MISCPOLLTIME_LSB 16
  #define FLASH_TIMING_PARAM_UPDATE_MISCPOLLTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_MAXPOLLCOUNT_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_MAXPOLLCOUNT_MSB 7
  #define FLASH_POWER_CREDIT_UPDATE_MSGTYPE_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_MSGTYPE_MSB 7
  #define FLASH_POWER_CREDIT_UPDATE_CNTXT_LSB 8
  #define FLASH_POWER_CREDIT_UPDATE_CNTXT_MSB 11
  #define FLASH_POWER_CREDIT_UPDATE_CHAN_LSB 12
  #define FLASH_POWER_CREDIT_UPDATE_CHAN_MSB 16
  #define FLASH_POWER_CREDIT_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_POWER_CREDIT_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_POWER_CREDIT_UPDATE_CHAIN_LSB 19
  #define FLASH_POWER_CREDIT_UPDATE_CHAIN_MSB 19
  #define FLASH_POWER_CREDIT_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_POWER_CREDIT_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_POWER_CREDIT_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_POWER_CREDIT_UPDATE_READSLCPOWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_READSLCPOWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMSLCPOWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMSLCPOWERCREDIT_MSB 31
  #define FLASH_POWER_CREDIT_UPDATE_ERASEPOWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_ERASEPOWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_READTLCSINGLEPLANEPOWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_READTLCSINGLEPLANEPOWERCREDIT_MSB 31
  #define FLASH_POWER_CREDIT_UPDATE_READTLCMULTIPLANEPOWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_READTLCMULTIPLANEPOWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS1POWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS1POWERCREDIT_MSB 31
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS2POWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS2POWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS3POWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMTLCPASS3POWERCREDIT_MSB 31
  #define FLASH_POWER_CREDIT_UPDATE_ERASEWORKAROUNDPOWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_ERASEWORKAROUNDPOWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_MISCPOWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_MISCPOWERCREDIT_MSB 31
  #define FLASH_DYNAMIC_UPDATE_MSGTYPE_LSB 0
  #define FLASH_DYNAMIC_UPDATE_MSGTYPE_MSB 7
  #define FLASH_DYNAMIC_UPDATE_CNTXT_LSB 8
  #define FLASH_DYNAMIC_UPDATE_CNTXT_MSB 11
  #define FLASH_DYNAMIC_UPDATE_CHAN_LSB 12
  #define FLASH_DYNAMIC_UPDATE_CHAN_MSB 16
  #define FLASH_DYNAMIC_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_DYNAMIC_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_DYNAMIC_UPDATE_CHAIN_LSB 19
  #define FLASH_DYNAMIC_UPDATE_CHAIN_MSB 19
  #define FLASH_DYNAMIC_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_DYNAMIC_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_DYNAMIC_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_DYNAMIC_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_DYNAMIC_UPDATE_HIGHPRIORPOLLLIMIT_LSB 0
  #define FLASH_DYNAMIC_UPDATE_HIGHPRIORPOLLLIMIT_MSB 15
  #define FLASH_DYNAMIC_UPDATE_DMPDDRBUFFADDR_LSB 0
  #define FLASH_DYNAMIC_UPDATE_DMPDDRBUFFADDR_MSB 31
  #define FLASH_DYNAMIC_UPDATE_DMPBRAMBUFFADDR_LSB 0
  #define FLASH_DYNAMIC_UPDATE_DMPBRAMBUFFADDR_MSB 31
  #define GET_ITERATION_COUNT_MSGTYPE_LSB 0
  #define GET_ITERATION_COUNT_MSGTYPE_MSB 7
  #define GET_ITERATION_COUNT_CNTXT_LSB 8
  #define GET_ITERATION_COUNT_CNTXT_MSB 11
  #define GET_ITERATION_COUNT_CHAN_LSB 12
  #define GET_ITERATION_COUNT_CHAN_MSB 16
  #define GET_ITERATION_COUNT_CHMSGNODEADDR_LSB 2
  #define GET_ITERATION_COUNT_CHMSGNODEADDR_MSB 18
  #define GET_ITERATION_COUNT_CHAIN_LSB 19
  #define GET_ITERATION_COUNT_CHAIN_MSB 19
  #define GET_ITERATION_COUNT_OUTMSGQ_LSB 24
  #define GET_ITERATION_COUNT_OUTMSGQ_MSB 27
  #define GET_ITERATION_COUNT_SUBMSGTYPE_LSB 0
  #define GET_ITERATION_COUNT_SUBMSGTYPE_MSB 3
  #define GET_ITERATION_COUNT_RESET_LSB 4
  #define GET_ITERATION_COUNT_RESET_MSB 4
  #define READ_HEADER_PLANENUM_LSB 0
  #define READ_HEADER_PLANENUM_MSB 2
  #define READ_HEADER_NUMBUFFERS_LSB 3
  #define READ_HEADER_NUMBUFFERS_MSB 6
  #define READ_HEADER_LASTBUFFERSPAN_LSB 7
  #define READ_HEADER_LASTBUFFERSPAN_MSB 7
  #define READ_HEADER_NUMECCCHUNK_LSB 8
  #define READ_HEADER_NUMECCCHUNK_MSB 11
  #define READ_HEADER_STARTECCCHUNK_LSB 12
  #define READ_HEADER_STARTECCCHUNK_MSB 15
  #define READ_HEADER_STARTDUMPCOUNT_LSB 16
  #define READ_HEADER_STARTDUMPCOUNT_MSB 30
  #define READ_HEADER_HDRSIG_LSB 31
  #define READ_HEADER_HDRSIG_MSB 31
  #define WRITE_HEADER_PLANENUM_LSB 0
  #define WRITE_HEADER_PLANENUM_MSB 2
  #define WRITE_HEADER_NUMBUFFERS_LSB 3
  #define WRITE_HEADER_NUMBUFFERS_MSB 6
  #define WRITE_HEADER_LASTBUFFERSPAN_LSB 7
  #define WRITE_HEADER_LASTBUFFERSPAN_MSB 7
  #define WRITE_HEADER_NUMECCCHUNK_LSB 8
  #define WRITE_HEADER_NUMECCCHUNK_MSB 11
  #define WRITE_HEADER_LASTDATAFRAMELENGTH_LSB 12
  #define WRITE_HEADER_LASTDATAFRAMELENGTH_MSB 27
  #define WRITE_HEADER_HDRSIG_LSB 31
  #define WRITE_HEADER_HDRSIG_MSB 31
  #define FLASH_READ_MSGTYPE_LSB 0
  #define FLASH_READ_MSGTYPE_MSB 7
  #define FLASH_READ_CNTXT_LSB 8
  #define FLASH_READ_CNTXT_MSB 11
  #define FLASH_READ_CHAN_LSB 12
  #define FLASH_READ_CHAN_MSB 16
  #define FLASH_READ_CHMSGNODEADDR_LSB 2
  #define FLASH_READ_CHMSGNODEADDR_MSB 18
  #define FLASH_READ_CHAIN_LSB 19
  #define FLASH_READ_CHAIN_MSB 19
  #define FLASH_READ_OUTMSGQ_LSB 24
  #define FLASH_READ_OUTMSGQ_MSB 27
  #define FLASH_READ_ECCCODERATEINDEX_LSB 0
  #define FLASH_READ_ECCCODERATEINDEX_MSB 3
  #define FLASH_READ_MAXITER_LSB 8
  #define FLASH_READ_MAXITER_MSB 15
  #define FLASH_READ_LLR0_LSB 16
  #define FLASH_READ_LLR0_MSB 23
  #define FLASH_READ_LLR1_LSB 24
  #define FLASH_READ_LLR1_MSB 31
  #define FLASH_READ_SCRAMBLERSEED_LSB 0
  #define FLASH_READ_SCRAMBLERSEED_MSB 15
  #define FLASH_READ_READRETRY_LSB 16
  #define FLASH_READ_READRETRY_MSB 23
  #define FLASH_READ_NUMPLANE_LSB 24
  #define FLASH_READ_NUMPLANE_MSB 27
  #define FLASH_READ_DFBUFFOPERATION_LSB 28
  #define FLASH_READ_DFBUFFOPERATION_MSB 28
  #define FLASH_READ_BLOCKTYPE_LSB 31
  #define FLASH_READ_BLOCKTYPE_MSB 31
  #define FLASH_READ_PAGEREADTIME_LSB 0
  #define FLASH_READ_PAGEREADTIME_MSB 23
  #define FLASH_READ_READHDRCOUNT_LSB 24
  #define FLASH_READ_READHDRCOUNT_MSB 31
  #define FLASH_READ_FIRSTDFOFFSET_LSB 0
  #define FLASH_READ_FIRSTDFOFFSET_MSB 15
  #define FLASH_READ_DATAFRAMELENGTH_LSB 16
  #define FLASH_READ_DATAFRAMELENGTH_MSB 31
  #define FLASH_READ_RAWBUFFER_LSB 0
  #define FLASH_READ_RAWBUFFER_MSB 31
  #define FLASH_READ_READHEADER0_LSB 0
  #define FLASH_READ_READHEADER0_MSB 31
  #define FLASH_READ_DATAFRAMEBUFFER0_LSB 0
  #define FLASH_READ_DATAFRAMEBUFFER0_MSB 31
  #define FLASH_READ_READMSGDW15_LSB 0
  #define FLASH_READ_READMSGDW15_MSB 31
  #define FLASH_WRITE_MSGTYPE_LSB 0
  #define FLASH_WRITE_MSGTYPE_MSB 7
  #define FLASH_WRITE_CNTXT_LSB 8
  #define FLASH_WRITE_CNTXT_MSB 11
  #define FLASH_WRITE_CHAN_LSB 12
  #define FLASH_WRITE_CHAN_MSB 16
  #define FLASH_WRITE_XORCALCID_LSB 21
  #define FLASH_WRITE_XORCALCID_MSB 29
  #define FLASH_WRITE_XORCALCSTRIPELAST_LSB 30
  #define FLASH_WRITE_XORCALCSTRIPELAST_MSB 30
  #define FLASH_WRITE_XORCALCOP_LSB 31
  #define FLASH_WRITE_XORCALCOP_MSB 31
  #define FLASH_WRITE_CHMSGNODEADDR_LSB 2
  #define FLASH_WRITE_CHMSGNODEADDR_MSB 18
  #define FLASH_WRITE_CHAIN_LSB 19
  #define FLASH_WRITE_CHAIN_MSB 19
  #define FLASH_WRITE_OUTMSGQ_LSB 24
  #define FLASH_WRITE_OUTMSGQ_MSB 27
  #define FLASH_WRITE_ECCCODERATEINDEX_LSB 0
  #define FLASH_WRITE_ECCCODERATEINDEX_MSB 3
  #define FLASH_WRITE_SCRAMBLERSEED_LSB 0
  #define FLASH_WRITE_SCRAMBLERSEED_MSB 15
  #define FLASH_WRITE_NUMPLANE_LSB 24
  #define FLASH_WRITE_NUMPLANE_MSB 27
  #define FLASH_WRITE_DFBUFFOPERATION_LSB 28
  #define FLASH_WRITE_DFBUFFOPERATION_MSB 28
  #define FLASH_WRITE_BLOCKTYPE_LSB 31
  #define FLASH_WRITE_BLOCKTYPE_MSB 31
  #define FLASH_WRITE_PAGEPROGTIME_LSB 0
  #define FLASH_WRITE_PAGEPROGTIME_MSB 23
  #define FLASH_WRITE_WRITEHDRCOUNT_LSB 24
  #define FLASH_WRITE_WRITEHDRCOUNT_MSB 31
  #define FLASH_WRITE_FIRSTDFOFFSET_LSB 0
  #define FLASH_WRITE_FIRSTDFOFFSET_MSB 15
  #define FLASH_WRITE_DATAFRAMELENGTH_LSB 16
  #define FLASH_WRITE_DATAFRAMELENGTH_MSB 31
  #define FLASH_WRITE_WRITEHEADER0_LSB 0
  #define FLASH_WRITE_WRITEHEADER0_MSB 31
  #define FLASH_WRITE_DATAFRAMEBUFFTYPE_LSB 0
  #define FLASH_WRITE_DATAFRAMEBUFFTYPE_MSB 31
  #define FLASH_WRITE_DATAFRAMEBUFFADDR_LSB 0
  #define FLASH_WRITE_DATAFRAMEBUFFADDR_MSB 31
  #define FLASH_WRITE_WRITEMSGDW15_LSB 0
  #define FLASH_WRITE_WRITEMSGDW15_MSB 31
  #define FLASH_CONT_MSGTYPE_LSB 0
  #define FLASH_CONT_MSGTYPE_MSB 7
  #define FLASH_CONT_CNTXT_LSB 8
  #define FLASH_CONT_CNTXT_MSB 11
  #define FLASH_CONT_CHAN_LSB 12
  #define FLASH_CONT_CHAN_MSB 16
  #define FLASH_CONT_CHMSGNODEADDR_LSB 2
  #define FLASH_CONT_CHMSGNODEADDR_MSB 18
  #define FLASH_CONT_CHAIN_LSB 19
  #define FLASH_CONT_CHAIN_MSB 19
  #define FLASH_CONT_OUTMSGQ_LSB 24
  #define FLASH_CONT_OUTMSGQ_MSB 27
  #define FLASH_ERASE_MSGTYPE_LSB 0
  #define FLASH_ERASE_MSGTYPE_MSB 7
  #define FLASH_ERASE_CNTXT_LSB 8
  #define FLASH_ERASE_CNTXT_MSB 11
  #define FLASH_ERASE_CHAN_LSB 12
  #define FLASH_ERASE_CHAN_MSB 16
  #define FLASH_ERASE_CHMSGNODEADDR_LSB 2
  #define FLASH_ERASE_CHMSGNODEADDR_MSB 18
  #define FLASH_ERASE_CHAIN_LSB 19
  #define FLASH_ERASE_CHAIN_MSB 19
  #define FLASH_ERASE_OUTMSGQ_LSB 24
  #define FLASH_ERASE_OUTMSGQ_MSB 27
  #define FLASH_ERASE_NUMPLANE_LSB 24
  #define FLASH_ERASE_NUMPLANE_MSB 27
  #define FLASH_ERASE_BLOCKTYPE_LSB 31
  #define FLASH_ERASE_BLOCKTYPE_MSB 31
  #define FLASH_ERASE_BLOCKERASETIME_LSB 0
  #define FLASH_ERASE_BLOCKERASETIME_MSB 23
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE0_LSB 0
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE0_MSB 2
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE1_LSB 3
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE1_MSB 5
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE2_LSB 6
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE2_MSB 8
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE3_LSB 9
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE3_MSB 11
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE4_LSB 12
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE4_MSB 14
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE5_LSB 15
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE5_MSB 17
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE6_LSB 18
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE6_MSB 20
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE7_LSB 21
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE7_MSB 23
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE8_LSB 24
  #define DATA_FRAME_BUFF_TYPE_DFBUFFTYPE8_MSB 26
  #define DATA_FRAME_BUFF_TYPE_NUMBUFFTYPES_LSB 27
  #define DATA_FRAME_BUFF_TYPE_NUMBUFFTYPES_MSB 31
  #define FLASH_OP_CPL_MSGTYPE_LSB 0
  #define FLASH_OP_CPL_MSGTYPE_MSB 7
  #define FLASH_OP_CPL_OUTMSGQ_LSB 8
  #define FLASH_OP_CPL_OUTMSGQ_MSB 11
  #define FLASH_OP_CPL_STATUS_LSB 16
  #define FLASH_OP_CPL_STATUS_MSB 19
  #define FLASH_OP_CPL_ERASEDPAGE_LSB 20
  #define FLASH_OP_CPL_ERASEDPAGE_MSB 20
  #define FLASH_OP_CPL_PLANENUM_LSB 21
  #define FLASH_OP_CPL_PLANENUM_MSB 23
  #define FLASH_OP_CPL_RETRIES_LSB 24
  #define FLASH_OP_CPL_RETRIES_MSB 31
  #define FLASH_OP_CPL_PLANECPLINFO_LSB 0
  #define FLASH_OP_CPL_PLANECPLINFO_MSB 31
  #define FLASH_OP_CPL_ECCCHUNKERRVECTOR_LSB 0
  #define FLASH_OP_CPL_ECCCHUNKERRVECTOR_MSB 15
  #define FLASH_OP_CPL_PLANEMAXZERRM_LSB 16
  #define FLASH_OP_CPL_PLANEMAXZERRM_MSB 19
  #define FLASH_OP_CPL_MAXZERRMCHUNKNUM_LSB 20
  #define FLASH_OP_CPL_MAXZERRMCHUNKNUM_MSB 23
  #define FLASH_OP_CPL_PLANETOTALZERRM_LSB 24
  #define FLASH_OP_CPL_PLANETOTALZERRM_MSB 31
  #define FLASH_OP_CPL_DATAFRAMEBUFFTYPE_LSB 0
  #define FLASH_OP_CPL_DATAFRAMEBUFFTYPE_MSB 31
  #define FLASH_RD_PLANE_CPL_INFO_PLANEMAXECCERRORS_LSB 0
  #define FLASH_RD_PLANE_CPL_INFO_PLANEMAXECCERRORS_MSB 11
  #define FLASH_RD_PLANE_CPL_INFO_MAXERRORCHUNKNUM_LSB 12
  #define FLASH_RD_PLANE_CPL_INFO_MAXERRORCHUNKNUM_MSB 15
  #define FLASH_RD_PLANE_CPL_INFO_PLANETOTALECCERRORS_LSB 16
  #define FLASH_RD_PLANE_CPL_INFO_PLANETOTALECCERRORS_MSB 31
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE0STATUS_LSB 0
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE0STATUS_MSB 3
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE1STATUS_LSB 4
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE1STATUS_MSB 7
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE2STATUS_LSB 8
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE2STATUS_MSB 11
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE3STATUS_LSB 12
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE3STATUS_MSB 15
  #define FLASH_OP_CPL_CONT_MSGTYPE_LSB 0
  #define FLASH_OP_CPL_CONT_MSGTYPE_MSB 7
  #define FLASH_OP_CPL_CONT_OUTMSGQ_LSB 8
  #define FLASH_OP_CPL_CONT_OUTMSGQ_MSB 11
  #define FLASH_OP_CPL_CONT_PLANENUM_LSB 21
  #define FLASH_OP_CPL_CONT_PLANENUM_MSB 23
  #define FLASH_MEM_WRITE_MSGTYPE_LSB 0
  #define FLASH_MEM_WRITE_MSGTYPE_MSB 7
  #define FLASH_MEM_WRITE_NUMDWORDS_LSB 8
  #define FLASH_MEM_WRITE_NUMDWORDS_MSB 11
  #define FLASH_MEM_WRITE_MULTICASTVECTOR_LSB 0
  #define FLASH_MEM_WRITE_MULTICASTVECTOR_MSB 31
  #define FLASH_MEM_WRITE_FLASHCHPROCADDR_LSB 2
  #define FLASH_MEM_WRITE_FLASHCHPROCADDR_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD0_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD0_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD1_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD1_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD2_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD2_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD3_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD3_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD4_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD4_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD5_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD5_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD6_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD6_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD7_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD7_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD8_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD8_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD9_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD9_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD10_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD10_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD11_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD11_MSB 31
  #define FLASH_READ_PARAMETER_PAGE_MSGTYPE_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_MSGTYPE_MSB 7
  #define FLASH_READ_PARAMETER_PAGE_CNTXT_LSB 8
  #define FLASH_READ_PARAMETER_PAGE_CNTXT_MSB 11
  #define FLASH_READ_PARAMETER_PAGE_CHAN_LSB 12
  #define FLASH_READ_PARAMETER_PAGE_CHAN_MSB 16
  #define FLASH_READ_PARAMETER_PAGE_CHMSGNODEADDR_LSB 2
  #define FLASH_READ_PARAMETER_PAGE_CHMSGNODEADDR_MSB 18
  #define FLASH_READ_PARAMETER_PAGE_CHAIN_LSB 19
  #define FLASH_READ_PARAMETER_PAGE_CHAIN_MSB 19
  #define FLASH_READ_PARAMETER_PAGE_OUTMSGQ_LSB 24
  #define FLASH_READ_PARAMETER_PAGE_OUTMSGQ_MSB 27
  #define FLASH_READ_PARAMETER_PAGE_ADDRESS_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_ADDRESS_MSB 7
  #define FLASH_READ_PARAMETER_PAGE_PAGEREADTIME_LSB 8
  #define FLASH_READ_PARAMETER_PAGE_PAGEREADTIME_MSB 31
  #define FLASH_READ_PARAMETER_PAGE_DFBUFFOPERATION_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_DFBUFFOPERATION_MSB 0
  #define FLASH_READ_PARAMETER_PAGE_STARTOFFSET_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_STARTOFFSET_MSB 15
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMELENGTH_LSB 16
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMELENGTH_MSB 31
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMEBUFFER_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMEBUFFER_MSB 31
  #define FLASH_READ_ID_MSGTYPE_LSB 0
  #define FLASH_READ_ID_MSGTYPE_MSB 7
  #define FLASH_READ_ID_CNTXT_LSB 8
  #define FLASH_READ_ID_CNTXT_MSB 11
  #define FLASH_READ_ID_CHAN_LSB 12
  #define FLASH_READ_ID_CHAN_MSB 16
  #define FLASH_READ_ID_CHMSGNODEADDR_LSB 2
  #define FLASH_READ_ID_CHMSGNODEADDR_MSB 18
  #define FLASH_READ_ID_CHAIN_LSB 19
  #define FLASH_READ_ID_CHAIN_MSB 19
  #define FLASH_READ_ID_OUTMSGQ_LSB 24
  #define FLASH_READ_ID_OUTMSGQ_MSB 27
  #define FLASH_READ_ID_ADDRESS_LSB 0
  #define FLASH_READ_ID_ADDRESS_MSB 7
  #define FLASH_OP_CPL_DATA_MSGTYPE_LSB 0
  #define FLASH_OP_CPL_DATA_MSGTYPE_MSB 7
  #define FLASH_OP_CPL_DATA_OUTMSGQ_LSB 8
  #define FLASH_OP_CPL_DATA_OUTMSGQ_MSB 11
  #define FLASH_OP_CPL_DATA_SIZE_LSB 16
  #define FLASH_OP_CPL_DATA_SIZE_MSB 23
  #define FLASH_OP_CPL_DATA_STATUS_LSB 24
  #define FLASH_OP_CPL_DATA_STATUS_MSB 31
  #define FLASH_SET_FEAT_MSGTYPE_LSB 0
  #define FLASH_SET_FEAT_MSGTYPE_MSB 7
  #define FLASH_SET_FEAT_CNTXT_LSB 8
  #define FLASH_SET_FEAT_CNTXT_MSB 11
  #define FLASH_SET_FEAT_CHAN_LSB 12
  #define FLASH_SET_FEAT_CHAN_MSB 16
  #define FLASH_SET_FEAT_CHMSGNODEADDR_LSB 2
  #define FLASH_SET_FEAT_CHMSGNODEADDR_MSB 18
  #define FLASH_SET_FEAT_CHAIN_LSB 19
  #define FLASH_SET_FEAT_CHAIN_MSB 19
  #define FLASH_SET_FEAT_OUTMSGQ_LSB 24
  #define FLASH_SET_FEAT_OUTMSGQ_MSB 27
  #define FLASH_SET_FEAT_ADDRESS_LSB 0
  #define FLASH_SET_FEAT_ADDRESS_MSB 7
  #define FLASH_SET_FEAT_PARAMETERS_LSB 0
  #define FLASH_SET_FEAT_PARAMETERS_MSB 31
  #define FLASH_GET_FEAT_MSGTYPE_LSB 0
  #define FLASH_GET_FEAT_MSGTYPE_MSB 7
  #define FLASH_GET_FEAT_CNTXT_LSB 8
  #define FLASH_GET_FEAT_CNTXT_MSB 11
  #define FLASH_GET_FEAT_CHAN_LSB 12
  #define FLASH_GET_FEAT_CHAN_MSB 16
  #define FLASH_GET_FEAT_CHMSGNODEADDR_LSB 2
  #define FLASH_GET_FEAT_CHMSGNODEADDR_MSB 18
  #define FLASH_GET_FEAT_CHAIN_LSB 19
  #define FLASH_GET_FEAT_CHAIN_MSB 19
  #define FLASH_GET_FEAT_OUTMSGQ_LSB 24
  #define FLASH_GET_FEAT_OUTMSGQ_MSB 27
  #define FLASH_GET_FEAT_ADDRESS_LSB 0
  #define FLASH_GET_FEAT_ADDRESS_MSB 7
  #define FLASH_ADDR_FORMAT_PAGENUM_LSB 0
  #define FLASH_ADDR_FORMAT_PAGENUM_MSB 6
  #define FLASH_ADDR_FORMAT_BLOCKNUM_LSB 7
  #define FLASH_ADDR_FORMAT_BLOCKNUM_MSB 19
  #define FLASH_ADDR_FORMAT_LUNNUM_LSB 20
  #define FLASH_ADDR_FORMAT_LUNNUM_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE_MSGTYPE_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE_MSGTYPE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE_CNTXT_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE_CNTXT_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAN_LSB 12
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAN_MSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAIN_LSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE_CHAIN_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMCONTEXT_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMCONTEXT_MSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMLUN_LSB 9
  #define FLASH_CHANNEL_CONFIG_UPDATE_NUMLUN_MSB 12
  #define FLASH_CHANNEL_CONFIG_UPDATE_LUNBITPOSITION_LSB 13
  #define FLASH_CHANNEL_CONFIG_UPDATE_LUNBITPOSITION_MSB 18
  #define FLASH_CHANNEL_CONFIG_UPDATE_PAGESIZE_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE_PAGESIZE_MSB 15
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__1STCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__2NDCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__3RDCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__4THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__5THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__6THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__7THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__8THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__9THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__10THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__11THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__12THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__13THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__14THCONTEXTLUN_MSB 27
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXT_LSB 0
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXT_MSB 3
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTCE_LSB 4
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTCE_MSB 7
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTLUN_LSB 8
  #define FLASH_CHANNEL_CONFIG_UPDATE__15THCONTEXTLUN_MSB 11
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXT_LSB 16
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXT_MSB 19
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTCE_LSB 20
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTCE_MSB 23
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTLUN_LSB 24
  #define FLASH_CHANNEL_CONFIG_UPDATE__16THCONTEXTLUN_MSB 27
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_MSGTYPE_LSB 0
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_MSGTYPE_MSB 7
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CNTXT_LSB 8
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CNTXT_MSB 11
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAN_LSB 12
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAN_MSB 16
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAIN_LSB 19
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_CHAIN_MSB 19
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_NUMENTRIES_LSB 4
  #define FLASH_ECC_CONTEXT_INFO_UPDATE_NUMENTRIES_MSB 7
  #define ECC_CONTEXT_DATA_ECCCONTEXTNUM_LSB 0
  #define ECC_CONTEXT_DATA_ECCCONTEXTNUM_MSB 3
  #define ECC_CONTEXT_DATA_ECCCHUNKSIZE_LSB 4
  #define ECC_CONTEXT_DATA_ECCCHUNKSIZE_MSB 17
  #define ECC_CONTEXT_DATA_PROTECTEDDATASIZE_LSB 18
  #define ECC_CONTEXT_DATA_PROTECTEDDATASIZE_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_MSGTYPE_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_MSGTYPE_MSB 7
  #define FLASH_TIMING_PARAM_UPDATE_CNTXT_LSB 8
  #define FLASH_TIMING_PARAM_UPDATE_CNTXT_MSB 11
  #define FLASH_TIMING_PARAM_UPDATE_CHAN_LSB 12
  #define FLASH_TIMING_PARAM_UPDATE_CHAN_MSB 16
  #define FLASH_TIMING_PARAM_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_TIMING_PARAM_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_TIMING_PARAM_UPDATE_CHAIN_LSB 19
  #define FLASH_TIMING_PARAM_UPDATE_CHAIN_MSB 19
  #define FLASH_TIMING_PARAM_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_TIMING_PARAM_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_TIMING_PARAM_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_TIMING_PARAM_UPDATE_TIMESEL_LSB 4
  #define FLASH_TIMING_PARAM_UPDATE_TIMESEL_MSB 4
  #define FLASH_TIMING_PARAM_UPDATE_DUMMYBUSYTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_DUMMYBUSYTIME_MSB 15
  #define FLASH_TIMING_PARAM_UPDATE_CLKHIGH2RBLOWTIME_LSB 16
  #define FLASH_TIMING_PARAM_UPDATE_CLKHIGH2RBLOWTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_RESETTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_RESETTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_POWERONRSTTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_POWERONRSTTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_INTERFACECHANGETIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_INTERFACECHANGETIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_FEATURETIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_FEATURETIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_RDPOLLTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_RDPOLLTIME_MSB 15
  #define FLASH_TIMING_PARAM_UPDATE_WRPOLLTIME_LSB 16
  #define FLASH_TIMING_PARAM_UPDATE_WRPOLLTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_BERPOLLTIME_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_BERPOLLTIME_MSB 15
  #define FLASH_TIMING_PARAM_UPDATE_MISCPOLLTIME_LSB 16
  #define FLASH_TIMING_PARAM_UPDATE_MISCPOLLTIME_MSB 31
  #define FLASH_TIMING_PARAM_UPDATE_MAXPOLLCOUNT_LSB 0
  #define FLASH_TIMING_PARAM_UPDATE_MAXPOLLCOUNT_MSB 7
  #define FLASH_POWER_CREDIT_UPDATE_MSGTYPE_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_MSGTYPE_MSB 7
  #define FLASH_POWER_CREDIT_UPDATE_CNTXT_LSB 8
  #define FLASH_POWER_CREDIT_UPDATE_CNTXT_MSB 11
  #define FLASH_POWER_CREDIT_UPDATE_CHAN_LSB 12
  #define FLASH_POWER_CREDIT_UPDATE_CHAN_MSB 16
  #define FLASH_POWER_CREDIT_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_POWER_CREDIT_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_POWER_CREDIT_UPDATE_CHAIN_LSB 19
  #define FLASH_POWER_CREDIT_UPDATE_CHAIN_MSB 19
  #define FLASH_POWER_CREDIT_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_POWER_CREDIT_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_POWER_CREDIT_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_POWER_CREDIT_UPDATE_READPOWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_READPOWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMPOWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_PROGRAMPOWERCREDIT_MSB 31
  #define FLASH_POWER_CREDIT_UPDATE_ERASEPOWERCREDIT_LSB 0
  #define FLASH_POWER_CREDIT_UPDATE_ERASEPOWERCREDIT_MSB 15
  #define FLASH_POWER_CREDIT_UPDATE_MISCPOWERCREDIT_LSB 16
  #define FLASH_POWER_CREDIT_UPDATE_MISCPOWERCREDIT_MSB 31
  #define FLASH_DYNAMIC_UPDATE_MSGTYPE_LSB 0
  #define FLASH_DYNAMIC_UPDATE_MSGTYPE_MSB 7
  #define FLASH_DYNAMIC_UPDATE_CNTXT_LSB 8
  #define FLASH_DYNAMIC_UPDATE_CNTXT_MSB 11
  #define FLASH_DYNAMIC_UPDATE_CHAN_LSB 12
  #define FLASH_DYNAMIC_UPDATE_CHAN_MSB 16
  #define FLASH_DYNAMIC_UPDATE_CHMSGNODEADDR_LSB 2
  #define FLASH_DYNAMIC_UPDATE_CHMSGNODEADDR_MSB 18
  #define FLASH_DYNAMIC_UPDATE_CHAIN_LSB 19
  #define FLASH_DYNAMIC_UPDATE_CHAIN_MSB 19
  #define FLASH_DYNAMIC_UPDATE_OUTMSGQ_LSB 24
  #define FLASH_DYNAMIC_UPDATE_OUTMSGQ_MSB 27
  #define FLASH_DYNAMIC_UPDATE_SUBMSGTYPE_LSB 0
  #define FLASH_DYNAMIC_UPDATE_SUBMSGTYPE_MSB 3
  #define FLASH_DYNAMIC_UPDATE_HIGHPRIORPOLLLIMIT_LSB 0
  #define FLASH_DYNAMIC_UPDATE_HIGHPRIORPOLLLIMIT_MSB 15
  #define READ_HEADER_STARTECCCHUNK_LSB 7
  #define READ_HEADER_STARTECCCHUNK_MSB 9
  #define READ_HEADER_NUMECCHEADERS_LSB 11
  #define READ_HEADER_NUMECCHEADERS_MSB 15
  #define READ_HEADER_PAGEOFFSET_LSB 16
  #define READ_HEADER_PAGEOFFSET_MSB 30
  #define E_C_C CODE RATE_PLANENUM_LSB 0
  #define E_C_C CODE RATE_PLANENUM_MSB 0
  #define E_C_C CODE RATE_NUMBUFFERS_LSB 1
  #define E_C_C CODE RATE_NUMBUFFERS_MSB 3
  #define E_C_C CODE RATE_NUMECCCHUNK_LSB 4
  #define E_C_C CODE RATE_NUMECCCHUNK_MSB 6
  #define E_C_C CODE RATE_LASTBUFFERSPANS_LSB 7
  #define E_C_C CODE RATE_LASTBUFFERSPANS_MSB 7
  #define E_C_C CODE RATE_SIZEECCCHUNK_LSB 10
  #define E_C_C CODE RATE_SIZEECCCHUNK_MSB 20
  #define E_C_C CODE RATE_SIZEPROTDATA_LSB 21
  #define E_C_C CODE RATE_SIZEPROTDATA_MSB 31
  #define WRITE_HEADER_PLANENUM_LSB 0
  #define WRITE_HEADER_PLANENUM_MSB 0
  #define WRITE_HEADER_NUMBUFFERS_LSB 1
  #define WRITE_HEADER_NUMBUFFERS_MSB 3
  #define WRITE_HEADER_NUMECCCHUNK_LSB 4
  #define WRITE_HEADER_NUMECCCHUNK_MSB 6
  #define WRITE_HEADER_STARTECCCHUNK_LSB 7
  #define WRITE_HEADER_STARTECCCHUNK_MSB 9
  #define WRITE_HEADER_SIZEECCCHUNK_LSB 10
  #define WRITE_HEADER_SIZEECCCHUNK_MSB 20
  #define WRITE_HEADER_SIZEPROTDATA_LSB 21
  #define WRITE_HEADER_SIZEPROTDATA_MSB 31
  #define FLASH_READ_MSGTYPE_LSB 0
  #define FLASH_READ_MSGTYPE_MSB 7
  #define FLASH_READ_CNTXT_LSB 8
  #define FLASH_READ_CNTXT_MSB 11
  #define FLASH_READ_CHAN_LSB 12
  #define FLASH_READ_CHAN_MSB 16
  #define FLASH_READ_CHMSGNODEADDR_LSB 2
  #define FLASH_READ_CHMSGNODEADDR_MSB 18
  #define FLASH_READ_CHAIN_LSB 19
  #define FLASH_READ_CHAIN_MSB 19
  #define FLASH_READ_OUTMSGQ_LSB 24
  #define FLASH_READ_OUTMSGQ_MSB 27
  #define FLASH_READ_ECCCODERATEINDEX_LSB 0
  #define FLASH_READ_ECCCODERATEINDEX_MSB 3
  #define FLASH_READ_MAXITER_LSB 8
  #define FLASH_READ_MAXITER_MSB 15
  #define FLASH_READ_LLR0_LSB 16
  #define FLASH_READ_LLR0_MSB 23
  #define FLASH_READ_LLR1_LSB 24
  #define FLASH_READ_LLR1_MSB 31
  #define FLASH_READ_SCRAMBLERSEED_LSB 0
  #define FLASH_READ_SCRAMBLERSEED_MSB 15
  #define FLASH_READ_READRETRY_LSB 16
  #define FLASH_READ_READRETRY_MSB 23
  #define FLASH_READ_NUMPLANE_LSB 24
  #define FLASH_READ_NUMPLANE_MSB 27
  #define FLASH_READ_DFBUFFOPERATION_LSB 28
  #define FLASH_READ_DFBUFFOPERATION_MSB 28
  #define FLASH_READ_BLOCKTYPE_LSB 31
  #define FLASH_READ_BLOCKTYPE_MSB 31
  #define FLASH_READ_PAGEREADTIME_LSB 0
  #define FLASH_READ_PAGEREADTIME_MSB 23
  #define FLASH_READ_READHDRCOUNT_LSB 24
  #define FLASH_READ_READHDRCOUNT_MSB 31
  #define FLASH_READ_FIRSTDFOFFSET_LSB 0
  #define FLASH_READ_FIRSTDFOFFSET_MSB 15
  #define FLASH_READ_DATAFRAMELENGTH_LSB 16
  #define FLASH_READ_DATAFRAMELENGTH_MSB 31
  #define FLASH_READ_RAWBUFFER_LSB 0
  #define FLASH_READ_RAWBUFFER_MSB 31
  #define FLASH_READ_READHEADER0_LSB 0
  #define FLASH_READ_READHEADER0_MSB 31
  #define FLASH_READ_ECCHEADER0_LSB 0
  #define FLASH_READ_ECCHEADER0_MSB 31
  #define FLASH_READ_DATAFRAMEBUFFER0_LSB 0
  #define FLASH_READ_DATAFRAMEBUFFER0_MSB 31
  #define FLASH_READ_READMSGDW14_LSB 0
  #define FLASH_READ_READMSGDW14_MSB 31
  #define FLASH_READ_READMSGDW15_LSB 0
  #define FLASH_READ_READMSGDW15_MSB 31
  #define FLASH_WRITE_MSGTYPE_LSB 0
  #define FLASH_WRITE_MSGTYPE_MSB 7
  #define FLASH_WRITE_CNTXT_LSB 8
  #define FLASH_WRITE_CNTXT_MSB 11
  #define FLASH_WRITE_CHAN_LSB 12
  #define FLASH_WRITE_CHAN_MSB 16
  #define FLASH_WRITE_XORCALCID_LSB 21
  #define FLASH_WRITE_XORCALCID_MSB 29
  #define FLASH_WRITE_XORCALCSTRIPELAST_LSB 30
  #define FLASH_WRITE_XORCALCSTRIPELAST_MSB 30
  #define FLASH_WRITE_XORCALCOP_LSB 31
  #define FLASH_WRITE_XORCALCOP_MSB 31
  #define FLASH_WRITE_CHMSGNODEADDR_LSB 2
  #define FLASH_WRITE_CHMSGNODEADDR_MSB 18
  #define FLASH_WRITE_CHAIN_LSB 19
  #define FLASH_WRITE_CHAIN_MSB 19
  #define FLASH_WRITE_OUTMSGQ_LSB 24
  #define FLASH_WRITE_OUTMSGQ_MSB 27
  #define FLASH_WRITE_ECCCODERATEINDEX_LSB 0
  #define FLASH_WRITE_ECCCODERATEINDEX_MSB 3
  #define FLASH_WRITE_SCRAMBLERSEED_LSB 0
  #define FLASH_WRITE_SCRAMBLERSEED_MSB 15
  #define FLASH_WRITE_NUMPLANE_LSB 24
  #define FLASH_WRITE_NUMPLANE_MSB 27
  #define FLASH_WRITE_DFBUFFOPERATION_LSB 28
  #define FLASH_WRITE_DFBUFFOPERATION_MSB 28
  #define FLASH_WRITE_BLOCKTYPE_LSB 31
  #define FLASH_WRITE_BLOCKTYPE_MSB 31
  #define FLASH_WRITE_PAGEPROGTIME_LSB 0
  #define FLASH_WRITE_PAGEPROGTIME_MSB 23
  #define FLASH_WRITE_WRITEHDRCOUNT_LSB 24
  #define FLASH_WRITE_WRITEHDRCOUNT_MSB 31
  #define FLASH_WRITE_FIRSTDFOFFSET_LSB 0
  #define FLASH_WRITE_FIRSTDFOFFSET_MSB 15
  #define FLASH_WRITE_DATAFRAMELENGTH_LSB 16
  #define FLASH_WRITE_DATAFRAMELENGTH_MSB 31
  #define FLASH_WRITE_WRITEHEADER0_LSB 0
  #define FLASH_WRITE_WRITEHEADER0_MSB 31
  #define FLASH_WRITE_DATAFRAMEBUFFER0_LSB 0
  #define FLASH_WRITE_DATAFRAMEBUFFER0_MSB 31
  #define FLASH_WRITE_WRITEMSGDW12_LSB 0
  #define FLASH_WRITE_WRITEMSGDW12_MSB 31
  #define FLASH_WRITE_WRITEMSGDW13_LSB 0
  #define FLASH_WRITE_WRITEMSGDW13_MSB 31
  #define FLASH_WRITE_WRITEMSGDW14_LSB 0
  #define FLASH_WRITE_WRITEMSGDW14_MSB 31
  #define FLASH_WRITE_WRITEMSGDW15_LSB 0
  #define FLASH_WRITE_WRITEMSGDW15_MSB 31
  #define FLASH_CONT_MSGTYPE_LSB 0
  #define FLASH_CONT_MSGTYPE_MSB 7
  #define FLASH_CONT_CNTXT_LSB 8
  #define FLASH_CONT_CNTXT_MSB 11
  #define FLASH_CONT_CHAN_LSB 12
  #define FLASH_CONT_CHAN_MSB 16
  #define FLASH_CONT_CHMSGNODEADDR_LSB 2
  #define FLASH_CONT_CHMSGNODEADDR_MSB 18
  #define FLASH_CONT_CHAIN_LSB 19
  #define FLASH_CONT_CHAIN_MSB 19
  #define FLASH_CONT_OUTMSGQ_LSB 24
  #define FLASH_CONT_OUTMSGQ_MSB 27
  #define FLASH_ERASE_MSGTYPE_LSB 0
  #define FLASH_ERASE_MSGTYPE_MSB 7
  #define FLASH_ERASE_CNTXT_LSB 8
  #define FLASH_ERASE_CNTXT_MSB 11
  #define FLASH_ERASE_CHAN_LSB 12
  #define FLASH_ERASE_CHAN_MSB 16
  #define FLASH_ERASE_CHMSGNODEADDR_LSB 2
  #define FLASH_ERASE_CHMSGNODEADDR_MSB 18
  #define FLASH_ERASE_CHAIN_LSB 19
  #define FLASH_ERASE_CHAIN_MSB 19
  #define FLASH_ERASE_OUTMSGQ_LSB 24
  #define FLASH_ERASE_OUTMSGQ_MSB 27
  #define FLASH_ERASE_NUMPLANE_LSB 24
  #define FLASH_ERASE_NUMPLANE_MSB 27
  #define FLASH_ERASE_BLOCKTYPE_LSB 31
  #define FLASH_ERASE_BLOCKTYPE_MSB 31
  #define FLASH_ERASE_BLOCKERASETIME_LSB 0
  #define FLASH_ERASE_BLOCKERASETIME_MSB 23
  #define FLASH_OP_CPL_MSGTYPE_LSB 0
  #define FLASH_OP_CPL_MSGTYPE_MSB 7
  #define FLASH_OP_CPL_OUTMSGQ_LSB 8
  #define FLASH_OP_CPL_OUTMSGQ_MSB 11
  #define FLASH_OP_CPL_STATUS_LSB 16
  #define FLASH_OP_CPL_STATUS_MSB 19
  #define FLASH_OP_CPL_ERASEDPAGE_LSB 20
  #define FLASH_OP_CPL_ERASEDPAGE_MSB 20
  #define FLASH_OP_CPL_PLANENUM_LSB 21
  #define FLASH_OP_CPL_PLANENUM_MSB 23
  #define FLASH_OP_CPL_RETRIES_LSB 24
  #define FLASH_OP_CPL_RETRIES_MSB 31
  #define FLASH_OP_CPL_PLANECPLINFO_LSB 0
  #define FLASH_OP_CPL_PLANECPLINFO_MSB 31
  #define FLASH_OP_CPL_ECCCHUNKERRVECTOR_LSB 0
  #define FLASH_OP_CPL_ECCCHUNKERRVECTOR_MSB 15
  #define FLASH_OP_CPL_PLANEMAXZERRM_LSB 16
  #define FLASH_OP_CPL_PLANEMAXZERRM_MSB 19
  #define FLASH_OP_CPL_MAXZERRMCHUNKNUM_LSB 20
  #define FLASH_OP_CPL_MAXZERRMCHUNKNUM_MSB 23
  #define FLASH_OP_CPL_PLANETOTALZERRM_LSB 24
  #define FLASH_OP_CPL_PLANETOTALZERRM_MSB 31
  #define FLASH_OP_CPL_DATAFRAMEBUFFTYPE_LSB 0
  #define FLASH_OP_CPL_DATAFRAMEBUFFTYPE_MSB 31
  #define FLASH_RD_PLANE_CPL_INFO_PLANEMAXECCERRORS_LSB 0
  #define FLASH_RD_PLANE_CPL_INFO_PLANEMAXECCERRORS_MSB 11
  #define FLASH_RD_PLANE_CPL_INFO_MAXERRORCHUNKNUM_LSB 12
  #define FLASH_RD_PLANE_CPL_INFO_MAXERRORCHUNKNUM_MSB 15
  #define FLASH_RD_PLANE_CPL_INFO_PLANETOTALECCERRORS_LSB 16
  #define FLASH_RD_PLANE_CPL_INFO_PLANETOTALECCERRORS_MSB 31
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE0STATUS_LSB 0
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE0STATUS_MSB 3
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE1STATUS_LSB 4
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE1STATUS_MSB 7
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE2STATUS_LSB 8
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE2STATUS_MSB 11
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE3STATUS_LSB 12
  #define FLASH_WR_ER_PLANE_CPL_INFO_PLANE3STATUS_MSB 15
  #define FLASH_OP_CPL_CONT_MSGTYPE_LSB 0
  #define FLASH_OP_CPL_CONT_MSGTYPE_MSB 7
  #define FLASH_OP_CPL_CONT_OUTMSGQ_LSB 8
  #define FLASH_OP_CPL_CONT_OUTMSGQ_MSB 11
  #define FLASH_OP_CPL_CONT_PLANENUM_LSB 21
  #define FLASH_OP_CPL_CONT_PLANENUM_MSB 23
  #define FLASH_MEM_WRITE_MSGTYPE_LSB 0
  #define FLASH_MEM_WRITE_MSGTYPE_MSB 7
  #define FLASH_MEM_WRITE_NUMDWORDS_LSB 8
  #define FLASH_MEM_WRITE_NUMDWORDS_MSB 11
  #define FLASH_MEM_WRITE_MULTICASTVECTOR_LSB 0
  #define FLASH_MEM_WRITE_MULTICASTVECTOR_MSB 31
  #define FLASH_MEM_WRITE_FLASHCHPROCADDR_LSB 2
  #define FLASH_MEM_WRITE_FLASHCHPROCADDR_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD0_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD0_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD1_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD1_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD2_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD2_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD3_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD3_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD4_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD4_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD5_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD5_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD6_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD6_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD7_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD7_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD8_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD8_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD9_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD9_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD10_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD10_MSB 31
  #define FLASH_MEM_WRITE_DATADWORD11_LSB 0
  #define FLASH_MEM_WRITE_DATADWORD11_MSB 31
  #define FLASH_READ_PARAMETER_PAGE_MSGTYPE_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_MSGTYPE_MSB 7
  #define FLASH_READ_PARAMETER_PAGE_CNTXT_LSB 8
  #define FLASH_READ_PARAMETER_PAGE_CNTXT_MSB 11
  #define FLASH_READ_PARAMETER_PAGE_CHAN_LSB 12
  #define FLASH_READ_PARAMETER_PAGE_CHAN_MSB 16
  #define FLASH_READ_PARAMETER_PAGE_CHMSGNODEADDR_LSB 2
  #define FLASH_READ_PARAMETER_PAGE_CHMSGNODEADDR_MSB 18
  #define FLASH_READ_PARAMETER_PAGE_CHAIN_LSB 19
  #define FLASH_READ_PARAMETER_PAGE_CHAIN_MSB 19
  #define FLASH_READ_PARAMETER_PAGE_OUTMSGQ_LSB 24
  #define FLASH_READ_PARAMETER_PAGE_OUTMSGQ_MSB 27
  #define FLASH_READ_PARAMETER_PAGE_ADDRESS_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_ADDRESS_MSB 7
  #define FLASH_READ_PARAMETER_PAGE_PAGEREADTIME_LSB 8
  #define FLASH_READ_PARAMETER_PAGE_PAGEREADTIME_MSB 31
  #define FLASH_READ_PARAMETER_PAGE_DFBUFFOPERATION_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_DFBUFFOPERATION_MSB 0
  #define FLASH_READ_PARAMETER_PAGE_STARTOFFSET_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_STARTOFFSET_MSB 15
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMELENGTH_LSB 16
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMELENGTH_MSB 31
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMEBUFFER_LSB 0
  #define FLASH_READ_PARAMETER_PAGE_DATAFRAMEBUFFER_MSB 31
  #define FLASH_READ_ID_MSGTYPE_LSB 0
  #define FLASH_READ_ID_MSGTYPE_MSB 7
  #define FLASH_READ_ID_CNTXT_LSB 8
  #define FLASH_READ_ID_CNTXT_MSB 11
  #define FLASH_READ_ID_CHAN_LSB 12
  #define FLASH_READ_ID_CHAN_MSB 16
  #define FLASH_READ_ID_CHMSGNODEADDR_LSB 2
  #define FLASH_READ_ID_CHMSGNODEADDR_MSB 18
  #define FLASH_READ_ID_CHAIN_LSB 19
  #define FLASH_READ_ID_CHAIN_MSB 19
  #define FLASH_READ_ID_OUTMSGQ_LSB 24
  #define FLASH_READ_ID_OUTMSGQ_MSB 27
  #define FLASH_READ_ID_ADDRESS_LSB 0
  #define FLASH_READ_ID_ADDRESS_MSB 7
  #define FLASH_OP_CPL_DATA_MSGTYPE_LSB 0
  #define FLASH_OP_CPL_DATA_MSGTYPE_MSB 7
  #define FLASH_OP_CPL_DATA_OUTMSGQ_LSB 8
  #define FLASH_OP_CPL_DATA_OUTMSGQ_MSB 11
  #define FLASH_OP_CPL_DATA_SIZE_LSB 16
  #define FLASH_OP_CPL_DATA_SIZE_MSB 23
  #define FLASH_OP_CPL_DATA_STATUS_LSB 24
  #define FLASH_OP_CPL_DATA_STATUS_MSB 31
  #define FLASH_SET_FEAT_MSGTYPE_LSB 0
  #define FLASH_SET_FEAT_MSGTYPE_MSB 7
  #define FLASH_SET_FEAT_CNTXT_LSB 8
  #define FLASH_SET_FEAT_CNTXT_MSB 11
  #define FLASH_SET_FEAT_CHAN_LSB 12
  #define FLASH_SET_FEAT_CHAN_MSB 16
  #define FLASH_SET_FEAT_CHMSGNODEADDR_LSB 2
  #define FLASH_SET_FEAT_CHMSGNODEADDR_MSB 18
  #define FLASH_SET_FEAT_CHAIN_LSB 19
  #define FLASH_SET_FEAT_CHAIN_MSB 19
  #define FLASH_SET_FEAT_OUTMSGQ_LSB 24
  #define FLASH_SET_FEAT_OUTMSGQ_MSB 27
  #define FLASH_SET_FEAT_ADDRESS_LSB 0
  #define FLASH_SET_FEAT_ADDRESS_MSB 7
  #define FLASH_SET_FEAT_PARAMETERS_LSB 0
  #define FLASH_SET_FEAT_PARAMETERS_MSB 31
  #define FLASH_GET_FEAT_MSGTYPE_LSB 0
  #define FLASH_GET_FEAT_MSGTYPE_MSB 7
  #define FLASH_GET_FEAT_CNTXT_LSB 8
  #define FLASH_GET_FEAT_CNTXT_MSB 11
  #define FLASH_GET_FEAT_CHAN_LSB 12
  #define FLASH_GET_FEAT_CHAN_MSB 16
  #define FLASH_GET_FEAT_CHMSGNODEADDR_LSB 2
  #define FLASH_GET_FEAT_CHMSGNODEADDR_MSB 18
  #define FLASH_GET_FEAT_CHAIN_LSB 19
  #define FLASH_GET_FEAT_CHAIN_MSB 19
  #define FLASH_GET_FEAT_OUTMSGQ_LSB 24
  #define FLASH_GET_FEAT_OUTMSGQ_MSB 27
  #define FLASH_GET_FEAT_ADDRESS_LSB 0
  #define FLASH_GET_FEAT_ADDRESS_MSB 7
  #endif /*FLASH_INTERFACE_MESSAGES_MESSAGES_H_*/