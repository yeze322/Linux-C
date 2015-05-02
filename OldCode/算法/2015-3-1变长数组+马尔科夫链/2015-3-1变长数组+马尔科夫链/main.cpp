#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct Nameval {
	char *name;
	int value;
};

struct NVtab {
	int nval;		/* current number of values */
	int max;			/* allocated number if values */
	Nameval *nameval;	/* array of name-value pairs */
}nvtab;

enum { NVINIT = 1, NVGROW = 2 };

int addname(Nameval newname)
{
	Nameval *nvp;
	if(nvtab.nameval == NULL){
		nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
		if (nvtab.nameval ==NULL)
			return -1;
		nvtab.max = NVINIT;
		nvtab.nval = 0;
	}
	else if (nvtab.nval >= nvtab.max){
		nvp = (Nameval *)realloc(nvtab.nameval,(NVGROW*nvtab.max)*sizeof(Nameval));
		if(nvp == NULL)
			return -1;
		nvtab.max *= NVGROW;
		nvtab.nameval = nvp;
	}
	nvtab.nameval[nvtab.nval] = newname;
	return nvtab.nval++;
}

int delname(char *name)
{
	for(int i=0;i<nvtab.nval;i++){
		if(strcmp(nvtab.nameval[i].name,name) == 0){
			memmove(nvtab.nameval+i, nvtab.nameval+i+1,\
				(nvtab.nval-(i+1))*sizeof(Nameval));
			nvtab.nval--;
			return 1;
		}
	}
	return 0;
}