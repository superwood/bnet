/***************************************************************************
 * 
 * Copyright (c) 2013 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 
 
/**
 * @file thread_data.h
 * @author wuchao(wuchao@)
 * @date 2013/09/30 00:29:09
 * @version $Revision$ 
 * @brief data for worker thread 
 *  
 **/


#ifndef  __THREAD_DATA_H_
#define  __THREAD_DATA_H_
#include "reactor.h"

namespace bnet
{
	struct fd_pair
	{
	};
	struct thread_data
	{
		reactor_t*  preactor;

		
	};
}

















#endif  //__THREAD_DATA_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 : */
