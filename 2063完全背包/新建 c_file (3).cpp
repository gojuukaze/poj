#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct shu
{
	int pay,get;
};
int dp[100000];
shu a[13];
int mmax(int a,int b);

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out2.txt","w",stdout);
	int i,j;
	int pay,get;
	int ben,year;
	int t,n;
	int tatol;
	int temp,x;
	while(~scanf("%d",&t))
	{	
		while(t--)
		{
			scanf("%d%d",&ben,&year);
			tatol=ben;
			ben/=1000;
			scanf("%d",&n);
			for(j=1;j<=n;j++)
			{
				scanf("%d%d",&a[j].pay,&a[j].get);
				a[j].pay/=1000;

			}
			a[0].pay=0;
			a[0].get=0;

			memset(dp,0,sizeof(dp));

			for(i=1;i<=n;i++)
			{
				for(j=1;j<=ben;j++)
				{
					temp=0;
					if(a[i].pay<=j)
					{
						temp=dp[j-1] > ( dp[j-a[i].pay]+a[i].get )? dp[j-1] : ( dp[j-a[i].pay]+a[i].get );
					}
				//	else
						dp[j]=temp>dp[j]?temp:dp[j];
				//	dp[j]=dp[j]>dp[j]?dp[j]:dp[j];
				}
			}
			tatol+=dp[ben];
			
			year--;
			while(year--)
			{
				x=ben;
				ben=tatol/1000;
				for(i=1;i<=n;i++)
				{
					for(j=x+1;j<=ben;j++)
					{
						temp=0;
						if(a[i].pay<=j)
						{
							temp=dp[j-1] > ( dp[j-a[i].pay]+a[i].get )? dp[j-1] : ( dp[j-a[i].pay]+a[i].get );
						}
					//	else
						dp[j]=temp>dp[j]?temp:dp[j];
					//	dp[j]=dp[j]>dp[j]?dp[j]:dp[j];
					}
				}
				tatol+=dp[ben];

			}
		
			printf("%d\n",tatol);
		}

	}
	return 0;
}