#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sum = m+n;
		if(sum%2==0)
			return (double)minkproblem(A,m,B,n,sum/2)*0.5+(double)minkproblem(A,m,B,n,sum/2+1)*0.5;
		else
			return minkproblem(A,m,B,n,(sum+1)/2);
    }
	double minkproblem(int A[],int m,int B[],int n,int k){
		if(m<=0)
			return B[k-1];
		if(n<=0)
			return A[k-1];
		if(k==1)
			return min(A[0],B[0]);
		int middle_a = min(m,k/2);
		int middle_b = min(n,k/2);
		if(A[middle_a-1]<=B[middle_b-1])
			return minkproblem(A+middle_a,m-middle_a,B,n,k-middle_a);
		else
			return minkproblem(A,m,B+middle_b,n-middle_b,k-middle_b);
	}
};

int main()
{
	int a[1]={1};
	Solution p;
	double find = p.findMedianSortedArrays(a,1,a,1);
	return 0;
}
