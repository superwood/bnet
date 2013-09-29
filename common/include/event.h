/***************************************************************************
 * 
 * Copyright (c) 2013 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file event.h
 * @author wuchao(wuchao@)
 * @date 2013/09/29 22:12:34
 * @version $Revision$ 
 * @brief 
 *  
 **/


#ifndef  __EVENT_H_
#define  __EVENT_H_
#include "macro.h"
#include "reactor.h"
#include "stl/heap.h"
namespace bnet
{
	struct event_t
	{
		reactor_t* reactor;
		uint32_t   ev_fd;
		void *ev_arg;
		int ev_res;
		int ev_flag;
		struct timeval ev_timeout;
		void (*ev_callback)(int ,short, void *arg);
	};
}
#endif  //__EVENT_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 : */
