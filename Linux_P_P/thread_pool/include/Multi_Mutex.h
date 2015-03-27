using std::vector;
class Multi_Mutex
{
public:
	Multi_Mutex(size_t);
	~Multi_Mutex();
	void lock_all();
	void lock_one();
	void unlock();
private:
	/* data */
	vector<pthread_mutex_t*> list_ptr_mutex;
};

Multi_Mutex::Multi_Mutex(size_t n  = 1)
{
	assert(n>=1);
	for(int i=0;i<n;i++)
	{
		pthread_mutex_t* newmutex = new pthread_mutex_t;
		pthread_mutex_init(newmutex,NULL);
		list_ptr_mutex.push_back(newmutex);
	}
}

Multi_Mutex::~Multi_Mutex()
{
	for(vector<pthread_mutex_t*>::iterator i = list_ptr_mutex.begin(); i != list_ptr_mutex.end(); ++i)
	{
		pthread_mutex_destroy(*i);
		delete (*i);
	}
}