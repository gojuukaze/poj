#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
	int x,y;
	x=0;
		if((a&16)==16)
		{
			x+=1<<4;
		}
		if((a&8)==8)
		{
			x+=1<<3;
		}
		if((a&4)==4)
		{
			x+=1<<2;
		}
		if((a&2)==2)
		{
			x+=1<<1;
		}
		if((a&1)==1)
		{
			x+=1;
		}
		x<<=5;
		y=x;
		x=0;
		if((a&16)==16)
		{
			x+=1<<4;
		}
		if((a&8)==8)
		{
			x+=1<<3;
		}
		if((a&4)==4)
		{
			x+=1<<2;
		}
		if((a&2)==2)
		{
			x+=1<<1;
		}
		if((a&1)==1)
		{
			x+=1;
		}
x=x+y;
	a=x>>5;
	y=x-(a<<5);
		printf("%d,%d\n",a,y);




	
	return 0;
}