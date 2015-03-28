#ifndef _SOURCE_H_
#define _SOURCE_H_

#include "common.h"
#include "Mutex.h"
class SOURCE
{
public:
	void init(const char*,unsigned int, unsigned int);
	inline void increase();
	inline int decrease(unsigned int);
	unsigned int get_sleeptime() {return sleep_time;}
	unsigned int get_amount() {return source_amount;}
	Mutex source_lock;
private:
	unsigned int source_amount;
	unsigned int sleep_time;
	unsigned int source_speed;
	char name[20];
};

void SOURCE::init(const char* strname,unsigned int increase_speed, unsigned int sleeptime)
{
	source_amount = 0;
	source_speed = increase_speed;
	sleep_time = sleeptime;
	strcpy(name,strname);
}

void SOURCE::increase()
{
	source_lock.lock();
	source_amount += source_speed;
	source_lock.unlock();

	printf("[%s] increase %u\n",name,source_speed);
}

int SOURCE::decrease(unsigned int num)
{
	if (num>source_amount){
		printf("No Enough [%s]!\n",name);
		return false;
	}
	source_lock.lock();
	source_amount -= num;
	source_lock.unlock();

	printf("[%s] decrease by [$=%u]\n",name,num);
	return true;
}

#endif
//_SOURCE_H_