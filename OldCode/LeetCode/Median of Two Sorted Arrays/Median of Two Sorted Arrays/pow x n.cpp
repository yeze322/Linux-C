#include<iostream>
class Solution {
public:
    double pow(double x, int n) {
        if(n==0)
            return 1;
        int overflow = 0;
        if(n<0) {
            if(n==INT_MIN)  {
                overflow = 1;
                n++;
            }
            n=-n;
            x=1/x;
        }
        
        double result=1;

        while(n){
            int count=1, edge = n/2;
            double value=x;
            while(count<=edge) {
                count<<=1;
                value *= value;
            }
            result*=value;
            n = n-count;
        }
        if(overflow)
            result *= x;
        return result;
    }
};