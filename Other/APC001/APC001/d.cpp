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
void dfs(int &n, vector<list<int>>&g, vector<ll>&a, vector<bool>&chd, int &treenum, int node, vector < list<pair<ll, int>>> &t) {
	if (chd[node] == false) {
		chd[node] = true;
		t[treenum].push_back(make_pair(a[node], node));
		for (auto v : g[node]) {
			dfs(n, g, a, chd, treenum, v, t);
		}

	}
}
int main() {
	ll lim = 1e9 + 1;
	int n, m;
	cin >> n >> m;
	if (m == n - 1) {
		cout << 0;
		return 0;
	}
	vector<ll>a(n);
	rep(i, n)cin >> a[i];
	vector<list<int>>g(n);
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	vector < list<pair<ll, int>>> t;
	t.reserve(1e5);
	vector<bool>chd(n, false);
	int treenum = 0;
	rep(i, n) {
		if (chd[i] == false) {
			t.push_back({});
			dfs(n, g, a, chd, treenum, i, t);
			t[treenum].sort();
			treenum++;
		}
	}
	ll ans = 0;
	int usedNum = 0;
	rep(i, treenum) {
		ans += t[i].front().first;
		t[i].pop_front();
		usedNum++;
	}
	priority_queue<ll, vector<ll>, greater<ll> >costbox;
	rep(i, treenum) {
		auto it = t[i].begin();
		while (it != t[i].end()) {
			costbox.push(it->first);
			it++;
		}
	}
	while (usedNum < 2 * (n - m - 1) && !costbox.empty()) {
		auto combiningNode = costbox.top();
		costbox.pop();
		ans += combiningNode;
		usedNum++;

	}
	if (usedNum != 2 * (n - m - 1) )cout << "Impossible";
	else cout << ans;
	return 0;
}



