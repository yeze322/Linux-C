#ifndef _2048_H_
#define _2048_H_

#define N 4
#define two 2
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#include<math.h>
#include<time.h>
#include<conio.h>


void PrintMatrix();
bool GrowOneNum();
void Reset(int [][N]);
//left
bool MoveLeft();
bool LeftMix();
//right
bool MoveRight();
bool RightMix();
//Up
bool MoveUp();
bool UpMix();
//Down
bool MoveDown();
bool DownMix();


;;



#endif // !_2048_H_