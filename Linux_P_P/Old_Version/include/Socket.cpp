#include "common.h"
#include "Thread.h"
#include "MutexLock.h"
#include "ThreadPool.h"
#define PERROR(judge,word) if(judge == -1) { perror(word);exit(1);}

using std::queue;
using std::vector;
class Socket_Connect
{
public:
	Socket_Connect(int ,const char *);
	~Socket_Connect() { close(sock_fd); };
	void PowerOn();
	int getSocketID();
	int  Accept();
private:
	/* data */
	int sock_fd;
	int BACK_LOG;
	struct sockaddr_in servaddr;
	void init_sockaddr_in(sockaddr_in*,int,const char*);
	pthread_mutex_t lock_accept;
};

Socket_Connect::Socket_Connect (int SER_PORT = 1234, const char *SER_IP = "192.168.1.97" )
{
	/* UNP p85 */
	BACK_LOG = 10;
	/* 1 - socket  */
	sock_fd = socket(AF_INET,SOCK_STREAM,0);
	PERROR(sock_fd,"socket function failed!");
	init_sockaddr_in(&servaddr,SER_PORT,SER_IP);
}

void Socket_Connect::PowerOn()
{
	/* 2.1 - bind */	/* 2.2 - getsockname */
	int ret = bind(sock_fd,(const sockaddr*)&servaddr,sizeof(servaddr));
	PERROR(ret,"bind failed!");
	/* 3 - listen */
	ret = listen(sock_fd,BACK_LOG);
	PERROR(ret,"listen failed!");
}

int  Socket_Connect::Accept( )
{
	struct sockaddr_in cliaddr;
	socklen_t size_clientaddr = sizeof(cliaddr);
	MutexLock lock(lock_accept);
	int fd_client = accept(sock_fd,(struct sockaddr*)&cliaddr,&size_clientaddr);
	printf("[%d] %s:%d connet!\n",fd_client,inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));
	return fd_client;
}

int Socket_Connect::getSocketID( )
{
	return sock_fd;
}

void Socket_Connect::init_sockaddr_in(sockaddr_in *seraddr,int SER_PORT,const char* SER_IP)
{    
    memset(seraddr,0,sizeof(seraddr));
    seraddr->sin_family = AF_INET;
    seraddr->sin_port = htons(SER_PORT);
    seraddr->sin_addr.s_addr = inet_addr(SER_IP);
}


Socket_Connect server;

int main()
{
	ThreadPool pool;
	server.PowerOn();
	server.Accept();
	return 0;
}