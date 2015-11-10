#include <iostream>
#include <memory.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include<functional>
using namespace std;
int N;
int L;
vector<int> anLength;
int anUsed[65]; //是否用过的标记
int i,j,k;
int Dfs(int R, int M);

int main()
{
while(1) {
cin >> N;
if( N == 0 )
break;
int nTotalLen = 0;
anLength.clear();
for( int i = 0; i < N; i ++ ) {
int n;
cin >> n;
anLength.push_back(n);
nTotalLen += anLength[i];
}
sort(anLength.begin(),anLength.end(),greater<int>()); //要从长到短进行尝试
for( L = anLength[0]; L <= nTotalLen / 2; L ++ ) {
if( nTotalLen % L)
continue;
memset( anUsed, 0,sizeof(anUsed));
if( Dfs( N,L)) 
{
cout << L << endl;
break;
}
}
if( L > nTotalLen / 2 )
cout << nTotalLen << endl;
} // while
return 0;
}

int Dfs( int R, int M)
// M表示当前正在拼的棍子和 L 比还缺的长度
{
if( R == 0 && M == 0 )
return true;
if( M == 0 ) //一根刚刚拼完
M = L; //开始拼新的一根
int nStartNo = 0,nLastStickNo;
if( M != L ) //剪枝4
nStartNo = nLastStickNo + 1;
for( int i = nStartNo; i < N; i ++) {
if( !anUsed[i] && anLength[i] <= M) {
if( i > 0 ) {
if( anUsed[i-1] == false
&& anLength[i] == anLength[i-1])
continue; //剪枝1
}
anUsed[i] = 1; nLastStickNo = i;
if ( Dfs( R- 1,
M - anLength[i]))
return true;
else {
anUsed[i] = 0; //说明本次不能用第i根
//第i根以后还有用
if( anLength[i] == M || M == L)
return false; //剪枝3, 2
}
}
}
return false;
}