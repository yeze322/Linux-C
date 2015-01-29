/*************************************************************************
	> File Name: p82.cpp
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Tue 27 Jan 2015 12:16:48 UTC
 ************************************************************************/

//#include<iostream>
//using namespace std;
#include<assert.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	if(write(1,"here is some datsda\n",19)!=18)
		write(2,"A write error has occurred on file description 1\n",46);
	exit(0);
}
