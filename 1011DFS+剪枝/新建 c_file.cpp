#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include <vector>
#include<cmath>
#include <functional>
using namespace std;
vector<int> a;
bool ok;
bool f[90];
int da;
int mmax=(1<<31)-1;

int Scan()
{
	int res = 0, ch, flag = 0;

	if((ch = getchar()) == '-')				//判断正负
		flag = 1;

	else if(ch >= '0' && ch <= '9')			//得到完整的数
		res = ch - '0';
	while((ch = getchar()) >= '0' && ch <= '9' )
		res = res * 10 + ch - '0';

	return flag ? -res : res;
}

int dfs(int len,int n,int shen,int total)
{
	int i,biao=mmax;

	if(len==total)
	{
		if(shen==0)
		{
			da=len;
			ok=1;
			return 0;
		}
		total=0;
	}
	for(i=0;i<n;i++)
	{
		if( f[i]==0 )
		{
			if( total+a[i]<=len  && a[i]<biao)
			{
				f[i]=1;
				dfs(len,n,shen-1,total+a[i]);
				f[i]=0;
				if(total+a[i]==a[i] || total+a[i]==len)
				{
					return 0;
				}
				biao=a[i];
			}
			
		}

	}


	return 0;

}
int main()
{
	int n;
	int i;
	int sum;
	
	while((n=Scan()))
	{
		if(n==0)
			break;
		sum=0;
		a.clear();
		ok=0;
		for(i=0;i<n;i++)
		{
			int t=Scan();
			sum+=t;
			a.push_back(t);
		}
		da=sum;
		sort(a.begin(),a.end(),greater<int>());
		for(i=a[0];i<=sum/2;i++)
		{
			if(sum%i)
				continue;
			memset(f,0,sizeof(f));
			dfs(i,n,n,0);
			if(ok==1)
				break;
		}
		printf("%d\n",da);
	}
	return 0;
}