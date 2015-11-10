#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
int a[7][7];
int b[7][7];
int input(int c)
{
	int i,j;
	int n,m;
	a[0][2]=c;
	scanf("%d",&i);
	a[0][4]=i;
	for(i=1;i<7;i++)
	{
		if(i==2 || i==4)
		{
			for(j=0;j<7;j++)
				scanf("%d",&a[i][j]);
		}
		else
		{
			scanf("%d %d",&n,&m);
			a[i][2]=n;
			a[i][4]=m;
		}
	}
	return 0;
}

int move(char c,int dep)
{
	int i,j;
	switch(c) {
	case 'A': int zu=b[i][j];break;
	default:
		break;
	}
return 0;
}

int main()
{
	
	int b[7][7];
//	move(a,'c',3);
	int n;
	int i,j;
while(~scanf("%d",&n))
{
	if(n==0)
		break;
	else
	{memset(a,0,sizeof(a));
		input(n);
		
	}

	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(a[i][j]!=0)
				printf("%d",a[i][j]);
			else cout<<" ";
		}
		cout<<endl;
	}
}
	
	return 0;
}
