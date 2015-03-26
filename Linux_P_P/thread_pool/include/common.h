#ifndef _COMMON_H_
#define _COMMON_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
typedef void* (*p_thread_FUNC)(void *);
typedef void* thread_FUNC(void*);

void p(const char *);

#endif //_COMMON_H_