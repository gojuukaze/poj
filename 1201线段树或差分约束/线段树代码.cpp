/******************************************************
* @author:xiefubao
*******************************************************/
#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>
//freopen ("in.txt" , "r" , stdin);
using namespace std;

#define eps 1e-8
#define zero(_) (abs(_)<=eps)
const double pi=acos(-1.0);
typedef long long LL;
const int Max=50010;
const LL INF=0x3FFFFFFF;
struct node
{
  int l,r;
  node* pl,*pr;
  bool same;
  int sum;
} nodes[Max*3];
int tot=0;
int n=0;
void build(node* p,int left,int right)
{
  p->l=left;
  p->r=right;
  p->sum=0;
  p->same=0;
  if(left==right)
    return ;

  int middle=(left+right)/2;

  tot++;
  p->pl=nodes+tot;
  build(p->pl,left,middle);

  tot++;
  p->pr=nodes+tot;
  build(p->pr,middle+1,right);
}
void push_down(node* p)
{
  int middle=(p->r+p->l)/2;
  p->pl->same=1;
  p->pl->sum=middle-p->l+1;

  p->pr->same=1;
  p->pr->sum=p->r-middle;

  p->same=0;
}
void pushup(node* p)
{
  p->sum=p->pr->sum+p->pl->sum;
}
void update(node* p,int left,int right)
{
  if(p->l==p->r)
  {
    p->same=1;
    p->sum=1;
    return ;
  }
  if(p->l==left&&p->r==right)
  {
    p->same=1;
    p->sum=right-left+1;
    return ;
  }
  if(p->same)
    push_down(p);

  int middle=(p->r+p->l)/2;

  if(left>middle)
    update(p->pr,left,right);
  else if(right<=middle)
    update(p->pl,left,right);
  else
  {
    update(p->pl,left,middle);
    update(p->pr,middle+1,right);
  }
  pushup(p);
}

int query(node* p,int left,int right)
{
  if(right<left)
  return 0;
  if(p->l==left&&p->r==right)
    return p->sum;
  if(p->same)
    push_down(p);

  int middle=(p->r+p->l)/2;
  if(left>middle)
    return query(p->pr,left,right);
  else if(right<=middle)
    return query(p->pl,left,right);
  else
    return query(p->pl,left,middle)+query(p->pr,middle+1,right);
}
struct line
{
  int x,y;
  int c;
} lines[Max];
bool operator<(const line& a,const line& b)
{
  if(a.y!=b.y)
    return a.y<b.y;
  return a.x<b.x;
}
void solve(int a,int b,int c)
{
  if(query(nodes,a,b)>=c)
  return ;
  int left=a,right=b;
  while(left<=right)
  {
    int middle=(left+right)/2;
    if(query(nodes,a,middle)+b-middle>=c)
    left=middle+1;
    else
    right=middle-1;
  }
  ///cout<<left<<endl;
  update(nodes,left,b);
}
int main()
{
  while(cin>>n)
  {
    tot=0;
    build(nodes,0,Max-1);
    for(int i=0; i<n; i++)
      scanf("%d%d%d",&lines[i].x,&lines[i].y,&lines[i].c);
    sort(lines,lines+n);
    for(int i=0; i<n; i++)
    {
      solve(lines[i].x,lines[i].y,lines[i].c);
      //cout<<lines[i].x<<"		   "<<lines[i].y<<endl;
       // cout<<"   "<<query(nodes,1,Max-1)<<endl;
    }
    cout<<query(nodes,0,Max-1)<<endl;
  }
  return 0;
}