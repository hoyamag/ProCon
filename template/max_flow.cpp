#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;


/*
	蟻本P190よりmax_flow。
	中身は理解してない。

*/
struct edge {
	int to, cap, rev;
};
const int MAX_V = 300;
const int INF = INT32_MAX;
vector<bool>used(MAX_V);
vector<edge>G[MAX_V];
void add_edge(int from, int to, int cap) {
	G[from].push_back(edge({ to, cap, (int)G[to].size() }));
	G[to].push_back(edge({ from, 0, (int)G[from].size() - 1 }));

}
int dfs(int v, int t, int f) {
	if (v == t)return f;
	used[v] = true;
	for (int i = 0; i < G[v].size(); i++) {
		edge &e = G[v][i];
		if (!used[e.to] && e.cap > 0) {
			int d = dfs(e.to, t, min(f, e.cap));
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}


	return 0;
}
int max_flow(int s, int t) {
	int flow = 0;
	for (;;) {
		rep(i, MAX_V)used[i] = 0;
		int f = dfs(s, t, INF);
		if (f == 0)return flow;
		flow += f;
	}
}







int main() {

	int n;
	cin >> n;
	vector<int>a(n), b(n), c(n), d(n);
	rep(i, n)cin >> a[i] >> b[i];
	rep(i, n)cin >> c[i] >> d[i];
	int s = 2*n ;
	int t = 2*n + 1;
	rep(i, n) {
		add_edge(s, i, 1);
		add_edge(n + i, t, 1);
	}
		
	rep(i, n) {
		rep(j, n) {
			if (a[i] < c[j] && b[i] < d[j]) {
				add_edge(i, j+n, 1);
			}
		}
	}
	cout << max_flow(s, t);
	

	return 0;
}



