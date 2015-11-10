#include <stdio.h>
#include <string.h>
#include <queue>
#define M 100010
#define N 1005
const int inf = 0x3f3f3f3f;
using namespace std;
struct E         //�ڽӱ��ߣ�to���¸���㣬w ��Ȩֵ nxt �������ߵ�λ��
{
    int to,w,nxt;
}edge[2*M];

struct data    //g ��ʾ��㵽��ǰ��ľ��룬h���յ㵽��ǰ��ľ���
{
    int g,h;
    int to;
    bool operator < (data a) const   //���ȶ��е�������ʵҲ������ô���� ʹg+hС���ڶ���
    {
        return a.h + a.g < h + g;
    }
};
int e,n,src,des,head[N],tail[N],dis[N];//head ������ߣ�tail������� dis��des���յ㣩������ľ���
void addedge (int cu,int cv,int cw)
{
    edge[e].to = cv;
    edge[e].w = cw;
    edge[e].nxt = head[cu];
    head[cu] = e ++;
    edge[e].to = cu;
    edge[e].w = cw;
    edge[e].nxt = tail[cv];
    tail[cv] = e ++;
}

void dij ()          //dijstra�㷨��des������ľ��� ���ڹ��ۺ���h
{
    int i,j,k;
    int vis[N];
    memset (vis,0,sizeof(vis));
    memset (dis,0x3f,sizeof(dis));
    dis[des] = 0;
    for (i = 1;i <= n;i ++)
    {
        k = -1;
        int min = inf;
        for (j = 1;j <= n;j ++)
            if (!vis[j]&&min > dis[j])
            {
                k = j;
                min = dis[j];
            }
       // if (k == -1)      //��Ϊ����ͼ�϶�����ͨ�� �ɼӿɲ���
       //     break;
        vis[k] = 1;
        for (int u = tail[k];u != -1;u = edge[u].nxt)
        {
            int v;
            v = edge[u].to;
            if (!vis[v]&&dis[v] > dis[k] + edge[u].w)
                dis[v] = dis[k] + edge[u].w;
        }
    }
}

int Astar (int k)    //A*�㷨���k��·
{
    int cnt[N];
    data cur,nxt;     //��ǰ��� �¸����
    priority_queue <data> node;
    memset (cnt,0,sizeof(cnt));
    cur.to = src;             //��ǰ����ʼ�� ��Ͳ��ö�˵��
    cur.g = 0;
    cur.h = dis[src];
    node.push (cur);
    while (!node.empty())
    {
        cur = node.top ();
        node.pop();
        cnt[cur.to] ++;
        if (cnt[cur.to] > k)//�����ǰ����չ�ĵ�cnt>k��û��Ҫ��չ��
            continue;        //��Ϊ������Ѿ�����k+1��·�� ���������������ѿ϶��õ����Ǵ��ڵ���k+1��·��·��
        if (cnt[des] == k)  //�ҵ���K��· ����
            return cur.g;
        for (int u = head[cur.to];u != -1;u = edge[u].nxt)  //�����ĵ������
        {
            int v = edge[u].to;
            nxt.to = v;
            nxt.g = cur.g + edge[u].w;
            nxt.h = dis[v];
            node.push (nxt);
        }
    }
    return -1;
}
int main ()
{
    int m,u,v,w,k;
    while (~scanf ("%d%d",&n,&m))
    {
        e = 0;
        memset (head,-1,sizeof (head));
        memset (tail,-1,sizeof (tail));
        while (m --)
        {
            scanf ("%d%d%d",&u,&v,&w);
            addedge (u,v,w);
        }
        scanf ("%d%d%d",&src,&des,&k);
        if (src == des)     //�����յ���ͬʱ��kҪ++
            k ++;
        dij ();
        int ans = Astar (k);
        printf ("%d\n",ans);
    }
    return 0;
}