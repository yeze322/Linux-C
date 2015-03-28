/* ========== */
#include "CITY.h"

using std::queue;
using std::cout;
using std::endl;

int main()
{
	Mutex lock_main;
	lock_main.lock();

	CITY lord;
	Thread th_reporter(lord.f_reporter,(void*)&lord);
	th_reporter.create();
	//queue<Thread*> ptrque_productor;
	Thread th_productor_sand(lord.f_productor,(void*)&(lord.sand));
	Thread th_productor_wood(lord.f_productor,(void*)&(lord.wood));
	Thread th_productor_water(lord.f_productor,(void*)&(lord.water));
	th_productor_sand.create();
	th_productor_wood.create();
	th_productor_water.create();

	lock_main.lock();
	return 0;
}
