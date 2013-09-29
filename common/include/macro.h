/***************************************************************************
 * 
 * Copyright (c) 2013 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file macro.h
 * @author wuchao(wuchao@)
 * @date 2013/09/29 21:33:40
 * @version $Revision$ 
 * @brief macro  define
 *  
 **/
#ifndef  __MACRO_H_
#define  __MACRO_H_
/**<  ev_flag状态        */
#define LIST_TIMEOUT  0x01;		  /**< 在 timeout 容器中 */
#define LIST_INSERT   0x02;		  /**< 在注册容器中     */
#define LIST_ACTIVE   0x04;		  /**< 在激活容器中     */
#define LIST_INTERNAL 0x08		  /**<        */
#define LIST_INIT     0x10		  /**<        */
#define LIST_ALL      (0x01|0x02|0x04|0x08|0x10)

/**< ev_res状态*/
#define EV_TIMEOUT    0x01		  /**< timeout 事件发生*/
#define EV_READ       0x02		  /**< read    事件发生*/
#define EV_WRITE      0x04		  /**< write事件发生  */
#define EV_SIGNAL     0x08		  /**< 信号事件       */
/** Persistent event: won't get removed automatically when activated. */
#define EV_PERSIST    0x10
/** Select edge-triggered behavior, if supported by the backend. */
#define EV_ET         0x20

/**< err mask */
#define RET_OK       0x00
#define ERR_NET      0x01		  /**< 网络错误*/
#define ERR_FILE     0x02
#define ERR_MEM      0x04

#endif  //__MACRO_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 : */
