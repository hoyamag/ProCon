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
#define all(t) t.begin(), t.end()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));


struct edge {
	int to;
	int w;
};
void dfs(vector<list<edge>>&g, vector<bool>&checked, vector<int> &value, int node) {
	if (checked[node] == true)return;
	else {
		checked[node] = true;
		for (auto v : g[node]) {
			value[v.to] = value[node] + v.w;
			dfs(g, checked, value, v.to);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<list<edge>>g(n);
	vector<int> l(m), r(m), d(m);
	rep(i, m) {
		cin >> l[i] >> r[i] >> d[i];
		l[i]--;
		r[i]--;
		g[l[i]].push_back(edge({ r[i], d[i] }));
		g[r[i]].push_back(edge({ l[i],-d[i] }));
	}
	vector<bool>checked(n, false);
	vector<int> value(n, -1);
	value[0] = 0;
	rep(i, n) {
		if (checked[i] == false) dfs(g, checked, value, i);
	}
	bool all = true;
	rep(i, m) {
		if (value[r[i]] - value[l[i]] != d[i]) {
			all = false;
			break;
		}
	}
	cout << (all ? "Yes" : "No");




	return 0;
}



