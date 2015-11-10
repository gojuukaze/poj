#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct shu
{
	int pay,get;
};
int dp[10000][10000];
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

			for(j=1;j<=ben;j++)
			{
				for(i=1;i<=n;i++)
				{
					if(a[i].pay<=j)
					{
						dp[i][j]=dp[0][j-1] > ( dp[0][j-a[i].pay]+a[i].get )? dp[0][j-1] : ( dp[0][j-a[i].pay]+a[i].get );
					}
					else
						dp[i][j]=dp[0][j-1];
					dp[0][j]=dp[i][j]>dp[0][j]?dp[i][j]:dp[0][j];
				}
			}
			tatol+=dp[0][ben];
			year--;
			while(year--)
			{
				j=ben;
				ben=tatol/1000;
				for(j=j+1;j<=ben;j++)
				{
					for(i=1;i<=n;i++)
					{
			
						if(a[i].pay<=j)
						{
							dp[i][j]=dp[0][j-1] > ( dp[0][j-a[i].pay]+a[i].get )? dp[0][j-1] : ( dp[0][j-a[i].pay]+a[i].get );
						}
						else
							dp[i][j]=dp[0][j-1];
						dp[0][j]=dp[i][j]>dp[0][j]?dp[i][j]:dp[0][j];
					}
				}
				tatol+=dp[0][ben];

			}
		
			printf("%d\n",tatol);
		}

	}
	return 0;
}