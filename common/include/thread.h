 
/**
 * @file thread.h
 * @version $Revision: 1.3 $ 
 * @brief �̴߳������İ�������
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
			 * @brief ��ȡ�߳�id
			 *
			 * @return  pthread_t 
			 * @retval  �����߳�id 
			 **/
			pthread_t get_tid();

			/**
			 * @brief �˳��߳�,��run�����е���
			 *
			 * @param [in] p   : void* 
			 * @return  void 
			 * @retval  ���ظ�join��������Ϣ
			 **/
			void exit(void *p);

			/**
			 * @brief ���̷߳��룬ʹ���Լ����������Դ
			 * ���øú���detach���߳�
			 **/
			int detach();

			/**
			 * @brief ���øú���join���߳�
			 **/
			virtual int join();

			/**
			 * @brief ����ʵ�ָú������Զ����̺߳���
			 **/
			virtual int run() = 0;

			/**
			 * @brief ���øú��������߳�
			 **/
			int start();

			/**
			 * @brief ���캯��
			 **/
			thread_t();

			/**
			 * @brief ������������
			 **/
			virtual ~thread_t();
		private:
			/**
			 * @brief �̺߳���,������pthread_create����ĺ���
			 *
			 * @param [in/out] para   :���ڴ�����̴߳��������
			 * @return  void* 
			 **/
			static void* run_thread(void *para);
		private:
			pthread_t _tid;		  /**< �߳�id */
	};
}
#endif
/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
