/*背景：n个同学编号1,2,3...n，走廊里n盏灯。编号为1的同学拉所有1的倍数的灯一下
编号为2的同学拉所有2的倍数的灯一下……试问最后n个同学拉完后，有几盏灯亮着？*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<time.h>
const int N=9007150;
using namespace std;
/*设置控制台输出行数和列数
 system("mode con:cols=100 lines=1000");  
 请包含头文件 #include<windows.h>*/

void main()
{	//这里是设计一个循环，然后从1号一直到N号依次遍历开关灯操作。
	//其实有一个更简单的方法，一个数可化为两个数相乘，除完全平方数外，其他数字都是偶数次操作，必然灭。
	//所以找出完全平方数即可，这样很简单的。sqrt(N)
	int lamp[N+1]={0},temp,i;
	clock_t start_time1=clock();{

		for(i=1;i<=N;i++){
			temp=i;
			while(temp<N){
				lamp[temp]=1-lamp[temp];
				temp=temp+i;
			}
		}

		for(i=1;i<=N;i++){
			if(lamp[i])
				printf("%d ",i);
				//cout<<i<<" ";
		}

	}clock_t end_time1=clock();
	printf("\n*****************************************************************\n");
	clock_t start_time2=clock();{
		/*上面提到的简便算法*****************************************************/
		int t=int(sqrt(float(N)));
		for(i=1;i<=t;i++)
			printf("%d ",i*i);
			//cout<<i*i<<" ";
		/*单从运行时间感受，相差甚远。由此可见在大数据情况下算法优化的重要性！！*/

	}clock_t end_time2=clock();

	cout<< "\nRunning time(1) is: "<<static_cast<double>(end_time1-start_time1)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	cout<< "\nRunning time(2) is: "<<static_cast<double>(end_time2-start_time2)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	//加上这个统计时间的功能后发现，输出操作占据了差不多接近于计算的时间.而printf的效率明显高于cout！这是一个重要知识。待我查证一下
	getchar();
}
/*还遇到了一个有意思的问题，当N的值很大时，会出现错误。
原因是：“局部变量的申请空间是存放于栈中，windows里默认栈内存是1M，所以当申请空间大于1M时就会出现溢出错误”
如果想把他扩大M的话，项目->属性->链接器->系统->堆栈保留大小 即可。
例如扩大到2M：填写字节数——1024*1024*2 = 2097152*/

/*输出效率有这样的说法：
【1】long long 时用cout方便一点
【2】cin cout不关闭指针同步的话慢，关闭和fin fout速度差不多，而fin fout速度大概是scanf printf的一半
【3】不同的OS/Kernel，不同的编译器，不同的glibc，表现都不一样！
*/