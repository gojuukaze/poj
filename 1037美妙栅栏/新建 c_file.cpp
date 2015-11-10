#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;


int map[22][22][2];
int sum[22][22];
int init()
{
	int i,j,z;
	memset(map,0,sizeof(map));
	memset(sum,0,sizeof(sum));
	sum[1][0]=1;
	sum[1][1]=1;
	map[1][1][0]=map[1][1][1]=1;
	for(i=2;i<=20;i++)
	{
		for(j=1;j<=i;j++)
		{
			for(z=j;z<=i-1;z++)
			{
				map[i][j][1]+=map[i-1][z][0];
				
			}
			for(z=1;z<=j-1;z++)
			{
				map[i][j][0]+=map[i-1][z][1];
			}
			sum[i][j]=map[i][j][1]+map[i][j][0];

			sum[i][0]+=sum[i][j];
		}
	}
	return 0;

}

void dfs(int len, int num, int dir)
{
        // 设置退出点
        int i;
        if (len == 1)
        {
                for (i=1; i<=N; i++)
                        if (!used[i])
                                break;
                ans[1] = i;
                output();
                return;
        }
        if (dir == 0)
        {
                // 注意，很关键的一点，i在这里并不代表具体的数值了，而是序号
                // 相当于之前用过的全部擦掉，由剩下的重新构建序列。只是此时index与value
                // 不对应了
                for (i=1; i
                {
                        if (C - dp[len][i][1] > 0)
                                C -= dp[len][i][1];
                        else
                                break;
                }
                ans[len] = find(i), used[ans[len]] = true;
                dfs(len-1, i, 1);
        }
        else
        {
                for (i=num; i<=len; i++)
                {
                        if (C - dp[len][i][0] > 0)
                                C -= dp[len][i][0];
                        else
                                break;
                }

                ans[len] = find(i), used[ans[len]] = true;
                dfs(len-1, i, 0);
        }
}

int main()
{
	init();
	int i,j,z,q,c,n;
	while(~scanf("%d",&n))
	{
		while(n--)
		{
			scanf("%d%d",&q,&c);
			bool f[22];
			memset(f,0,sizeof(f));
			int kong=q;
			int qq=q;

			for(i=1;i<=qq;i++)
			{
				if(sum[qq][i]<c)
					c-=sum[qq][i];
				else
					break;
			}
			printf("%d",i);
			if(kong!=1)
				printf(" ");
			kong--;
			
			printf("\n");

		}
	}
	return 0;
}
