#include<iostream>
#include<cstring>
#include<cstdio>
#include<stack>
#include<vector>
#include<ctime>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
const int N = 8;

class temparr{
public:
	int index;
	int count;
	int a[N][N];
	void copy(temparr& temp){memcpy(((int*)a),((int*)temp.a),sizeof(int)*N*N);index = temp.index;count = temp.count;};
	temparr() {memset(((int*)a),0,sizeof(int)*N*N);index=0;count=0;}
};//now change it into a class

class Queen {
private: 
	temparr arr;
	stack<temparr> save;
	void cutscope(int);
	int total;

public:
	/* memeber functions */
	inline void printqueen(){
		cout<<"======\n";
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(arr.a[i][j]==1)
					cout<<"Q";
				else
					cout<<"+";
			}
			cout<<endl;
		}
	}
	void create();
	Queen(): total(0) {};
};

void Queen::cutscope(int loop)
{
	int ia = loop/N;
	int ib = loop%N;
	int(*arry)[N]= arr.a;
	for(int i=0;i<N;i++){
		arry[ia][i]=-1;
		arry[i][ib]=-1;
	}
	while(ia<N&&ib<N){
		arry[ia++][ib++]=-1;
	}
	ia = loop/N,ib=loop%N;
	while(ia<N&&ib>=0){
		arry[ia++][ib--]=-1;
	}
	ia = loop/N,ib=loop%N;
	while(ia>=0&&ib>=0){
		arry[ia--][ib--]=-1;
	}
	ia = loop/N,ib=loop%N;
	while(ia>=0&&ib<N){
		arry[ia--][ib++]=-1;
	}

	((int*)arry)[loop] = 1;
}

void Queen::create()
{

	int maxval = N*N;
	int* arry = (int *)arr.a;
traceback:
	int &loop=arr.index;
	for(loop;(loop)<maxval;(loop)++){
		if(arry[loop]==0){
			arry[loop] = -1;
			save.push(arr);
			cutscope(loop);
			arry[loop] = 1;
			arr.count++;
		}
	}
	if(arr.count==N){
		++total;
		printqueen();
	}
	if(!save.empty())	{
		arr.copy(save.top());
		save.pop();
		goto traceback;
	}
	cout<<"["<<total<<"]"<<endl;
}

int main()
{
	clock_t starttime = clock();
	freopen("queen.txt","w",stdout);
	Queen q8;
	q8.create();
	cout<<"time"<<clock()-starttime<<endl;
	//system("pause");
}

//总结: 规范的二维数组解法，虽然没有使用递归，但是效率并不高，因为二维的方式使得它耗费较多时间