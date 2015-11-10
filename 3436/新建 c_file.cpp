#include <iostream> 
#include <queue> 
#include <vector> 
#include <algorithm> 
#include <deque> 
using namespace std;
#define INFINITE 999999999 //Poj 1273 Drainage Ditches �� Dinic�㷨
int G[300][300];
bool Visited[300];
int Layer[300]; 
int n,m; //����������
int scr,des;//scr��Դ�㣬 des�ǻ��,�±��1��ʼ����scr>=1

bool CountLayer() 
{
	int layer = 0; 
	deque<int>q;
	memset(Layer,0xff,sizeof(Layer)); //����ʼ����-1
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
				//Layer[j] == -1 ˵��j��û�з��ʹ�
				Layer[j] = Layer[v] + 1;
				if( j == des ) //�ֲ㵽��㼴��
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
	deque<int> q; //DFS�õ�ջ
	while( CountLayer() ) 
	{ //ֻҪ�ֲܷ�
		q.push_back(scr); //Դ����ջ
		memset(Visited,0,sizeof(Visited)); 
		Visited[scr] = 1;
		while( !q.empty()) 
		{
			int nd = q.back();
			if( nd == des ) 
			{ // nd�ǻ��
				//��ջ����������С��
				int nMinC = INFINITE;
				int nMinC_vs; //������С�ߵ����
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
				//���㣬��ͼ
				nMaxFlow += nMinC;
				for( i = 1;i < q.size(); i ++ ) 
				{
					int vs = q[i-1];
					int ve = q[i];
					G[vs][ve] -= nMinC; //�޸ı�����
					G[ve][vs] += nMinC; //��ӷ����
				}
				//��ջ�� nMinC_vs��Ϊջ�����Ա����dfs
				while( !q.empty() && q.back() != nMinC_vs ) 
				{
					Visited[q.back()] = 0; //û�����Ӧ��Ҳ��
					q.pop_back();
				}
			}
			else 
			{ //nd���ǻ��
				for( i = 1;i <= m; i ++ ) 
				{
					if( G[nd][i] > 0 && Layer[i] == Layer[nd] + 1 &&! Visited[i]) 
					{
						//ֻ����һ���û���߹��Ľڵ���
						Visited[i] = 1;
						q.push_back(i);
						break;
					}
				}
				if( i > m) //�Ҳ�����һ����
					q.pop_back(); //����
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
			G[a+2][b+2]+= liu; //����֮������ж�����
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