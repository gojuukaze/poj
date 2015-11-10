#include<cstdio>
#include<cstring>
using namespace std;
const int INF = 1 << 30;
const int MAXM = 20 + 2;
int minv[MAXM], mins[MAXM];
int ans, N, M;
void init(){
	minv[0] = 0;
	mins[0] = 0;
	int i;
	for (i = 1; i <= M; ++i){
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	}
}
int min(int a, int b){ return a < b ? a : b; }

void dfs(int v, int s, int k, int r, int h){
	//已拼出体积v,面积s,还剩下k层，底层最大半径和最大高度分别为r,h
	if (k == 0){
		if (s < ans && v == N) ans = s;
		return;
	}
	if (v + minv[k] > N || s + mins[k] > ans || s + 2 * (N - v) / r > ans) return;
	int i, j;
	for (i = r - 1; i >= k; --i){
		j = min(h - 1, (N - v - minv[k - 1]) / (i*i));
		for (; j >= k; --j){
			if (k == M) s = i*i;
			dfs(v + i*i*j, s + 2 * i*j, k - 1, i, j);
		}
	}
}
int main(){
	while (scanf("%d%d", &N, &M)!=EOF){
		ans = INF;
		init();
		dfs(0, 0, M, N + 1, N + 1);
		if (ans != INF){ printf("%d\n", ans); }
		else{ printf("0\n"); }
	}
	return 0;
}