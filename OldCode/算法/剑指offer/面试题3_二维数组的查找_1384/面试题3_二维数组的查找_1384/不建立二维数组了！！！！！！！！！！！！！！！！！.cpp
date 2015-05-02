#include <string>
#include <stdio.h>
using namespace std;
char str[22222];
 int main(int argc, char *argv[])
{
    int m,n,num;
    while(scanf("%d%d%d",&m,&n,&num)==3)
    {
        int compare = 0;
        bool flag = false;
        //string str;
        for(int i = 0 ; i < m ; i++)
        {
            if(flag)
                gets(str);
            else
                for(int j = 0 ; j < n ; j++)
                {
                    scanf("%d", &compare);
                    if(compare == num)
                    {
                        flag = true;
                        gets(str);
                        break;
                    }
                }
        }
	flag==1?puts("Yes"):puts("No");
    }
    return 0;
}