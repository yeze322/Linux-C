#ifndef _CLASS_H_
#define _CLASS_H_

#include "common.h"
#include "Thread.h"
#include "Mutex.h"
#include "SOURCE.h"
/* ========== */
class CITY
{
public:
	CITY(int);
	SOURCE sand;
	SOURCE wood;
	SOURCE water;
	static thread_FUNC f_reporter;
	static thread_FUNC f_productor;
	void run();
	 int commuicate_fd;
	 Mutex fd_lock;
	 Mutex city_lock;
};

CITY::CITY(int fd = 1)
{
	commuicate_fd = fd;
	sand.init("sand",1,3,(void*)this);
	wood.init("wood",1,5,(void*)this);
	water.init("water",1,1,(void*)this);
}

void CITY::run()
{
	city_lock.lock();

	Thread th_reporter(f_reporter,(void*)this);
	th_reporter.create();
	//queue<Thread*> ptrque_productor;
	Thread th_productor_sand(f_productor,(void*)&sand);
	Thread th_productor_wood(f_productor,(void*)&wood);
	Thread th_productor_water(f_productor,(void*)&water);
	th_productor_sand.create();
	th_productor_wood.create();
	th_productor_water.create();

	city_lock.lock();
}

void* CITY::f_reporter(void* arg)
{
	int report_freq = 5;
	CITY *city = (CITY*) arg;
	unsigned int sandnum = 0;
	unsigned int woodnum = 0;
	unsigned int waternum = 0;
	char info[100];
	int com_fd = city->commuicate_fd;

	while(1){
		sandnum = (city->sand).get_amount();
		woodnum = (city->wood).get_amount();
		waternum = (city->water).get_amount();
		memset(info,100,sizeof(char));
		sprintf(info,"REPORT: [sand = %u|wood = %u|water = %u]\n",sandnum,woodnum,waternum);
		city->fd_lock.lock();
		write(com_fd,info,strlen(info)+1);
		city->fd_lock.unlock();
		sleep(report_freq);
	}
}

void* CITY::f_productor(void *arg)
{
	SOURCE *src = (SOURCE *)arg;
	CITY *base = (CITY *)(src->base_class);
	int com_fd = base->commuicate_fd; 
	unsigned int sleeptime = src->get_sleeptime();
	char info[40];
	while(1){
		sleep(sleeptime);
		src->increase();
		memset(info,40,sizeof(char));
		sprintf(info,"[%s] increase %u\n",src->get_name(),src->get_speed());
		base->fd_lock.lock();
		write(com_fd, info, strlen(info)+1);
		base->fd_lock.unlock();
	}
	return NULL;
}

#endif
/* ========== */