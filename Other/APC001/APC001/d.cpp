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
void combine(list < pair<ll, int>>&left, list<pair<ll, int>>&right) {
	auto r = right.begin();

	for (auto l = left.begin(); l != left.end(); l++) {
		ll le = l->first;
		ll re = r->first;
		while (le > re) {
			left.insert(l, { r->first, r->second });
			++r;
		}
		if (r == right.end())break;
	}
	while (r != right.end()) {
		left.push_back({ r->first, r->second });
		++r;
	}
	right.push_front({ -1,-1 });

}
int main() {
	ll lim = 1e9 + 1;
	int n, m;
	cin >> n >> m;
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
	while (treenum > 1) {
		ll mi = LLONG_MAX;
		int left = -1;
		int lefttree;
		rep(i, treenum) {
			auto p = t[i].front();
			if (p.second != -1) {
				if (p.first < mi) {
					mi = p.first;
					left = i;
				}
			}
		}
		if (left == -1) {
			cout << "Impossible";
			return 0;
		}

		ll summin = LLONG_MAX;
		int right = -1;
		rep(i, treenum) {
			if (i != left) {
				pair<ll, int> p = t[i].front();
				if (p.second != -1) {
					auto p2 = (++t[i].begin())->first;
					ll c = p.first + p2;
					if (c < summin) {
						summin = c;
						right = i;

					}
				}
			}
		}
		if (right == -1) {
			cout << "Impossible";
			return 0;
		}
		ans += t[left].begin()->first + t[right].begin()->first;
		t[left].erase(t[left].begin());
		t[right].erase(t[right].begin());
		combine(t[left], t[right]);
		treenum--;
	}

	cout << ans;
	return 0;
}



