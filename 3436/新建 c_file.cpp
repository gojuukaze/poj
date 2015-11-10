#include <iostream> 
#include <queue> 
#include <vector> 
#include <algorithm> 
#include <deque> 
using namespace std;
#define INFINITE 999999999 //Poj 1273 Drainage Ditches 的 Dinic算法
int G[300][300];
bool Visited[300];
int Layer[300]; 
int n,m; //点数，边数
int scr,des;//scr是源点， des是汇点,下标从1开始，即scr>=1

bool CountLayer() 
{
	int layer = 0; 
	deque<int>q;
	memset(Layer,0xff,sizeof(Layer)); //都初始化成-1
	Layer[scr] = 0; 
	q.push_back(scr);
	while( ! q.empty()) 
	{
		int v = q.front();
		q.pop_front();
		for( int j = 1; j <= m; j ++ ) 
		{
			if( G[v][j] > 0 && Layer[j] == -1 ) 
			{
				//Layer[j] == -1 说明j还没有访问过
				Layer[j] = Layer[v] + 1;
				if( j == des ) //分层到汇点即可
					return true;
				else
					q.push_back(j);
			}
		}
	}
	return false;
}

int Dinic()
{
	int i; int s;
	int nMaxFlow = 0;
	deque<int> q; //DFS用的栈
	while( CountLayer() ) 
	{ //只要能分层
		q.push_back(scr); //源点入栈
		memset(Visited,0,sizeof(Visited)); 
		Visited[scr] = 1;
		while( !q.empty()) 
		{
			int nd = q.back();
			if( nd == des ) 
			{ // nd是汇点
				//在栈中找容量最小边
				int nMinC = INFINITE;
				int nMinC_vs; //容量最小边的起点
				for( i = 1;i < q.size(); i ++ ) 
				{
					int vs = q[i-1];
					int ve = q[i];
					if( G[vs][ve] > 0 ) 
					{
						if( nMinC > G[vs][ve] ) 
						{
							nMinC = G[vs][ve];
							nMinC_vs = vs;
						}
					}
				}
				//增广，改图
				nMaxFlow += nMinC;
				for( i = 1;i < q.size(); i ++ ) 
				{
					int vs = q[i-1];
					int ve = q[i];
					G[vs][ve] -= nMinC; //修改边容量
					G[ve][vs] += nMinC; //添加反向边
				}
				//退栈到 nMinC_vs成为栈顶，以便继续dfs
				while( !q.empty() && q.back() != nMinC_vs ) 
				{
					Visited[q.back()] = 0; //没有这个应该也对
					q.pop_back();
				}
			}
			else 
			{ //nd不是汇点
				for( i = 1;i <= m; i ++ ) 
				{
					if( G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 &&! Visited[i]) 
					{
						//只往下一层的没有走过的节点走
						Visited[i] = 1;
						q.push_back(i);
						break;
					}
				}
				if( i > m) //找不到下一个点
					q.pop_back(); //回溯
			}
		}
	}
	return nMaxFlow;
}

int main()
{
	int lu,fa,con;
	char c;
	int a,b,liu,i;
	while (cin >> n) 
	{
		m=n+2;
		cin>>fa>>con>>lu;
		memset( G,0,sizeof(G));
		for( i = 0;i < lu;i ++ ) 
		{
			cin>>c>>a>>c>>b>>c>>liu;
			if(a!=b)
			G[a+2][b+2]+= liu; //两点之间可能有多条边
		}
		for(i=0;i<fa;i++)
		{
				cin>>c>>a>>c>>liu;
				G[1][a+2]+=liu;
		}
		for(i=0;i<con;i++)
		{
				cin>>c>>a>>c>>liu;
				G[a+2][m]+=liu;
		}
		
		cout << Dinic() << endl;
	}
	return 0;
}