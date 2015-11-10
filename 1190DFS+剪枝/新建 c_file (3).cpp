#include <stdio.h>
#include <string.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int minv[25];
int mins[25];
int mmin=(1<<31)-1;
int s;
int N;
bool f;
int Min(int a,int b)
{
	 if(a>b)
		return b;
	else
		return a;
}


int maxv(int n,int r,int h)
{
	int i,j;
	int v=0;
	for(i=0;i<n;i++,r--,h--)
	{
		v+=r*r*h;
	}
	return v;
}
int dfs(int v,int n,int r,int h)
{

	if(v==0)
	{
		if(n==0)
		{
			mmin=Min(mmin,s);
			f=1;
		}
	//	else
			return 0;
	}

	if(v<0)
		return 0;
	if(n>r || n>h)
		return 0;
	if(minv[n]>v)
		return 0;
	if(s+mins[n]>mmin)
		return 0;
	if(maxv(n,r,h)<v)
		return 0;

	int i,j;
	for(i=r;i>=n;i--)
	{
		if(n==N)
			s=i*i;
		for(j=h;j>=n;j--)
		{
			s+=2*i*j;
			dfs(v-i*i*j,n-1,i-1,j-1);
			s-=2*i*j;
		}
	}
}

int main()
{
	int n,v,i,j;
	minv[0]=mins[0]=0;
	for(i=1;i<=20;i++)
	{
		minv[i]=minv[i-1]+i*i*i;
		mins[i]=mins[i-1]+2*i*i;
	}
	while(~scanf("%d",&v))
	{
		scanf("%d",&n);
		N=n;
		if(minv[n]>v)
			printf("0\n");
		else
		{
			int maxh=(v-minv[n-1])/n*n+1;
			int maxr=sqrt(double(v-minv[n-1])/n)+1;
			mmin=(1<<31)-1;
			s=0;
			f=0;
			dfs(v,n,maxr,maxh);
			if(f==1)
				printf("%d\n",mmin);
			else
				printf("0\n");

		}
		
	}
}