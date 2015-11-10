#include<iostream> 
#include<cstdio> 
#include<string.h>
#include<algorithm> 
#include<queue>
#include<math.h>
using namespace std;   
#define ll __int64
#define maxint (1<<31)-1;
double paixu[500];
double dis[33][33];
int the=0;
int map[33][33];
bool use[999][999];
double k;
bool fj,fb;
int xx[]={0,0,-1,1};
int yy[]={1,-1,0,0};
int n;
struct xy
{
	int x1,y1;
	int x2,y2;
	double diss;//Á½ÈË¾àÀë
	xy()
	{
		diss=maxint;
	}
	xy(int a,int b,int c,int d)
	{x1=a;y1=b;x2=c;y2=d;}
}fa[999][999],tempxy;

int jhx,jhy,jsx,jsy;
int bhx,bhy,bsx,bsy;

queue<xy> que;
queue<xy> temp;

int MAX(int a,int b)
{
	if(a>b)
		return a;
	return b;
}

int xy_to_er(int i,int j)
{
	int x,a,y;
	a=i;
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
	return x;
}

int er_to_x(int a)
{
	return (a>>5);
}
int er_to_y(int x,int a)
{
	return (a-(x<<5));
}
int bfs()
{
	int a=xy_to_er(tempxy.x1,tempxy.y1);
	int b=xy_to_er(tempxy.x2,tempxy.y2);
	if(use[a][b]==1)
		return 0;
	use[a][b]=1;
	int i,j;
	/*a=tempxy.x1-tempxy.x2;
	b=tempxy.y1-tempxy.y2;
	if(a<0)
		a=-a;
	if(b<0)
		b=-b;
	double ddis=dis[a][b];*/
	int tx1,ty1,tx2,ty2;
	for(i=0;i<4;i++)
	{
		if(fj==0)
		{
		
		tx1=tempxy.x1+xx[i];
		ty1=tempxy.y1+yy[i];
		}
		else
		{
			tx1=tempxy.x1;
			ty1=tempxy.y1;
		}
		if(map[tx1][ty1]==1)
			continue;
	//	if(tx1==jsx && ty1==jsy)
	//		fj=1;
	//	if(fj==1)
	//	{
	//		if()
	//	}
		if(tx1>=1 && tx1<=n && ty1>=1 && ty1<=n)
		{
			a=xy_to_er(tx1,ty1);
		
		for(j=0;j<4;j++)
		{
			if(fj==0)
			{
			tx2=tempxy.x2+xx[j];
			ty2=tempxy.y2+yy[j];
			}
			else
			{
			tx2=tempxy.x2;
			ty2=tempxy.y2;
			}
			if(map[tx2][ty2]==1)
			continue;
			if(tx2>=1 && tx2<=n && ty2>=1 && ty2<=n)
			{
		/*		b=xy_to_er(tx2,ty2);
				if(fa[a][b].diss<ddis)
				{
					fa[a][b].diss=ddis;
					fa[a][b].x1=tempxy.x1;
					fa[a][b].y1=tempxy.y1;
					fa[a][b].x2=tempxy.x2;
					fa[a][b].y2=tempxy.y2;
				}*/
				a=tx1-tx2;
				b=ty1-ty2;
				if(a<0)
					a=-a;
				if(b<0)
					b=-b;
				int ddis=dis[a][b];
				if(ddis>=k)
					temp.push(xy(tx1,ty1,tx2,ty2)); 
			}
		}
		}
	}
return 0;
}

int find()
{

	while(temp.empty()==false)
	{

		
		while(temp.empty()==false)
		{
			tempxy=temp.front();
			temp.pop();
			if(tempxy.x1==jsx && tempxy.y1==jsy)
				fj=1;
			if(tempxy.x2==bsx && tempxy.y2==bsy)
				fb=1;
			if(fj!=fb)
			{
				if(fj==1 && tempxy.x1!=jsx && tempxy.y1!=jsy)
					continue;
				if(fb==1 && tempxy.x2!=bsx && tempxy.y2!=bsy)
					continue;
			}
			if(fj==1 && fb==1)
				return 0;
			que.push(tempxy);
		}
		memset(use,0,sizeof(use));
		while(que.empty()==false)
		{
			tempxy=que.front();
			que.pop();
			bfs();	
		}
	}
return -1;
}


int main() 
{
	int t;

	//int n;
	char c;
	int i,j;
	dis[0][0]=0;
	for(i=2;i<=30;i++)
	{
		for(j=1;j<=i;j++)
		{
			int a=(i-1);
			int b=(j-1);
			paixu[the]=sqrt(a*a+b*b);
			dis[b][a]=dis[a][b]=paixu[the];
			the++;
		}
	}
	sort(paixu,paixu+the);
	while(~scanf("%d",&n))
	{
		if(n==0)
			break;
	//	memset(f,0,sizeof(f));
	//	memset(use,0,sizeof(use));
	//	count=0;
		scanf("%c",&c);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				scanf("%c",&c);
				if(c=='#')
					map[i][j]=1;
				else 
				{
					map[i][j]=0;
					if(c=='H')
					{
						jhx=i;
						jhy=j;
					}
					else if(c=='s')
					{
						jsx=i;
						jsy=j;
					}
					else if(c=='h')
					{
						bhx=i;
						bhy=j;
					}
					else if(c=='s')
					{
						bsx=i;
						bsy=j;
					}
				}
			}
			scanf("%c",&c);
		}
		tempxy.x1=jhx;
		tempxy.y1=jhy;
		tempxy.x2=bhx;
		tempxy.y2=bhy;

		temp.push(tempxy);
		int s=0;
		int e=the-1;
		double tt;
		int a=jhx-bhx;
		int b=jhy-bhy;
		if(a<0)
			a=-a;
		if(b<0)
			b=-b;
		double ttt=dis[a][b];
		while(s<=e)
		{
			int mid=(s+e)>>1;
			k=paixu[mid];
			if(k>ttt)
			{
				s=mid-1;
				continue;
			}
			fb=fj=0;	
			find();
			if(fb==1 && fj==1)
			{
				tt=k;
				e=mid-1;
			}
			else
				s=mid+1;
		}
		printf("%f",tt);
	}
    return 0; 
}