/*************************************************************************
	> File Name: main.cpp
	> Author: Yeze
	> Mail: a@b.com
	> Created Time: 2015年03月11日 星期三 23时15分17秒
 ************************************************************************/

#include "_common.h"
#include "BasicCard.h"
#include "MinionCard.h"
int main()
{
    BasicCard SiverGuard("Argent Square","Devine Shield",1);
    SiverGuard.print();
    MinionCard Giant("Molten Gient","Cost 1 less for each damege your hero has taken",20);
}
