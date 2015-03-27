#include "common.h"
/* this class is meaningless! */
class Barrier
{
public:
	Barrier(unsigned int);
	~Barrier();
	void wait();
private:
	/* data */
	pthread_barrier_t* ptr_barrier;
};

Barrier::Barrier(unsigned int barr_num)
{
	assert(barr_num>=1);
	ptr_barrier = new pthread_barrier_t;
	int ret = pthread_barrier_init(ptr_barrier,NULL,barr_num);
	if(ret) perror("Barrier::Barrier");
}

Barrier::~Barrier()
{
	int ret = pthread_barrier_destroy(ptr_barrier);
	if(ret) perror("Barrier::~Barrier");
	delete ptr_barrier;
}

void Barrier::wait()
{
	int ret = pthread_barrier_wait(ptr_barrier);
	if(ret) perror("Barrier::wait");
	printf("wall : %d\n",ret);
}