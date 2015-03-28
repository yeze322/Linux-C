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
	CITY();
	SOURCE sand;
	SOURCE wood;
	SOURCE water;
	static thread_FUNC f_reporter;
	static thread_FUNC f_productor;

private:
	pthread_mutex_t city_lock;
};

CITY::CITY()
{
	sand.init("sand",1,3);
	wood.init("wood",1,5);
	water.init("water",1,1);
}

void* CITY::f_reporter(void* arg)
{
	int report_freq = 5;
	CITY *city = (CITY*) arg;
	unsigned int sandnum = 0;
	unsigned int woodnum = 0;
	unsigned int waternum = 0;
	while(1){
		sandnum = (city->sand).get_amount();
		woodnum = (city->wood).get_amount();
		waternum = (city->water).get_amount();
		printf("REPORT: [sand = %u|wood = %u|water = %u]\n",sandnum,woodnum,waternum);
		sleep(report_freq);
	}
}

void* CITY::f_productor(void *arg)
{
	SOURCE *src = (SOURCE *)arg;
	unsigned int sleeptime = src->get_sleeptime();

	while(1){
		sleep(sleeptime);
		src->increase();
	}
	return NULL;
}

#endif
/* ========== */