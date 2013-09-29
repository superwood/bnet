/***************************************************************************
 * 
 * Copyright (c) 2013 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file reactor.h
 * @author wuchao(wuchao@)
 * @date 2013/09/29 23:41:04
 * @version $Revision$ 
 * @brief the reactor model  interface 
 *  
 **/


#ifndef  __REACTOR_H_
#define  __REACTOR_H_
#include "event.h"
namespace bnet
{
	class reactor_t
	{
		public:
		reactor_t()
		{}
		~reactor_t()
		{}
		virtual int init(void) = 0;
		virtual int add(struct event*);
		virtual int del(struct event*);
		
		/**
		 * @brief 具体的 poll机制实现的细节 
		 * 监听事件，等事件发生后，将事件挂载到active队列中 
		 * 以及其他的一些边界处理。
		 * @param [in/out] tv   : struct timeval*
		 * @return  int 
		 * @retval   
		 * @see 
		 * @note 
		 * @author wuchao
		 * @date 2013/09/30 00:05:59
		**/
		virtual int dispatch(struct timeval *tv) = 0;
		/**
		 * @brief 调用 dispatch，遍历 active队列 调用 event回调处理 
		 *
		 * @return  int 
		 * @retval   
		 * @see 
		 * @note 
		 * @author wuchao
		 * @date 2013/09/30 00:07:38
		**/
		virtual int loop(void);
	};
}

















#endif  //__REACTOR_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 : */
