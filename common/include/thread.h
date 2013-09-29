 
/**
 * @file thread.h
 * @version $Revision: 1.3 $ 
 * @brief 线程处理函数的包裹基类
 *  
 **/
#ifndef __THREAD_WRAP_CLASS_H_
#define __THREAD_WRAP_CLASS_H_
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
namespace bnet
{
	class thread_t{
		public:
			/**
			 * @brief 获取线程id
			 *
			 * @return  pthread_t 
			 * @retval  返回线程id 
			 **/
			pthread_t get_tid();

			/**
			 * @brief 退出线程,在run函数中调用
			 *
			 * @param [in] p   : void* 
			 * @return  void 
			 * @retval  返回给join参数的信息
			 **/
			void exit(void *p);

			/**
			 * @brief 将线程分离，使其自己处理回收资源
			 * 调用该函数detach本线程
			 **/
			int detach();

			/**
			 * @brief 调用该函数join本线程
			 **/
			virtual int join();

			/**
			 * @brief 子类实现该函数以自定义线程函数
			 **/
			virtual int run() = 0;

			/**
			 * @brief 调用该函数启动线程
			 **/
			int start();

			/**
			 * @brief 构造函数
			 **/
			thread_t();

			/**
			 * @brief 虚拟析构函数
			 **/
			virtual ~thread_t();
		private:
			/**
			 * @brief 线程函数,就是在pthread_create传入的函数
			 *
			 * @param [in/out] para   :用于传入给线程处理的数据
			 * @return  void* 
			 **/
			static void* run_thread(void *para);
		private:
			pthread_t _tid;		  /**< 线程id */
	};
}
#endif
/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
