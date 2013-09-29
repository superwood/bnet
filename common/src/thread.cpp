#include"thread.h"
bnet::thread_t::thread_t() : _tid(0)
{

}

bnet::thread_t::~thread_t()
{

}

int bnet::thread_t::start()
{
	int ret;
	if((ret = pthread_create(&_tid, NULL, run_thread, (void *)this)) != 0){
		errno = ret;
	}
	return ret;
}

void* bnet::thread_t::run_thread(void *para)
{
	thread_t *t = static_cast<thread_t*>(para);
	t->run();
	return 0;
}

int bnet::thread_t::join()
{
	int ret;
	if( (ret = pthread_join(get_tid(), NULL)) != 0){
		errno = ret;
	}
	return ret;
}

int bnet::thread_t::detach()
{
	int ret;
	if((ret = pthread_detach(get_tid())) != 0){
		errno = ret;
	}
	return ret;
}

void bnet::thread_t::exit(void *p)
{
	pthread_exit(p);
}

pthread_t bnet::thread_t::get_tid()
{
	while(0 == _tid){
		usleep(1000000);
	}
	return _tid;
}
