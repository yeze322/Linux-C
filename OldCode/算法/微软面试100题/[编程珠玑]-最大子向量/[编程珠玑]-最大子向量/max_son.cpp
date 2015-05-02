#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
void forloop(int *a,int size, int &left, int &right)
{
	int maxvalue = 0;
	for(int i=0;i<size;i++){
		int sum = 0;
		for(int j=i;j<size;j++){
			sum += a[j];
			if(sum>maxvalue){
				maxvalue = sum;
				left = i;
				right =j;
			}
		}
	}
}
int divideway(int *a,int index_l,int index_r, int &left, int &right)
{//if both<0 ?
	printf("%d--%d\n",index_l,index_r);
	if(index_l>index_r)
		return INT_MIN;
	if(index_l==index_r)
	{
		left = right = index_l;
		return a[index_l];
	}
	int cut = (index_r - index_l)/2+index_l;
	int i[4];
	memset(i,-1,sizeof(int));
	int ret_left = divideway(a,index_l,cut-1,i[0],i[1]);
	int ret_right = divideway(a,cut+1,index_r,i[2],i[3]);
	if(i[1]==i[2])
	{//逻辑上cut必须同时被包含
		left = i[0];
		right = i[3];
		return ret_left+ret_right-a[cut];
	}else{
		assert(ret_left!=ret_right);
		int cutsum = 0;
		for(int loop=i[1]+1;loop<i[2];loop++)
			cutsum+=a[loop];
		int min = ret_left>ret_right?ret_right:ret_left;
		if(min+cutsum>=0)
		{
			left = i[0];
			right = i[3];
			return ret_left+ret_right+cutsum;
		}
		if(ret_left>ret_right)
		{
			left = i[0];
			right = i[1];
			return ret_left;
		}else{
			left = i[2];
			right = i[3];
			return ret_right;
		}
	}
}
void scanway(int *a,int size,int &left, int &right)
{
	
}
int main()
{
	int a[10] = {1 ,-22, 3 ,4 ,5 ,6 ,7 ,8 ,-121 ,10};
	int left,right;
	//forloop(a,10,left,right);
	divideway(a,0,9,left,right);
	return 0;
}