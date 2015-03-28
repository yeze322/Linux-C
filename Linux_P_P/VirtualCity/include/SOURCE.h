#ifndef _SOURCE_H_
#define _SOURCE_H_

#include "common.h"
#include "Mutex.h"

class SOURCE
{
public:
	void init(const char*,unsigned int, unsigned int,void*);
	inline void increase();
	inline int decrease(unsigned int);
	unsigned int get_sleeptime() {return sleep_time;}
	unsigned int get_amount() {return source_amount;}
	unsigned int get_speed() {return source_speed; }
	char* get_name() { return name; }
	Mutex source_lock;
	void* base_class;
private:
	char name[20];
	unsigned int source_amount;
	unsigned int sleep_time;
	unsigned int source_speed;
};

void SOURCE::init(const char* strname,unsigned int increase_speed, unsigned int sleeptime,void *base)
{
	source_amount = 0;
	source_speed = increase_speed;
	sleep_time = sleeptime;
	strcpy(name,strname);
	base_class = base;
}

void SOURCE::increase()
{
	source_lock.lock();
	source_amount += source_speed;
	source_lock.unlock();
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