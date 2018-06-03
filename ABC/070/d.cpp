

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

int main() {
	int n;
	cin >> n;
	vector<list<pair<int, ll>>>t(n);
	rep(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		t[a].push_back(make_pair(b, c));
		t[b].push_back(make_pair(a, c));
	}
	int q, k;
	cin >> q >> k;
	k--;
	list<int> s;
	s.push_back(k);
	vector<ll>dist(n, -1);
	dist[k] = 0;
	while (!s.empty()) {
		int node = s.front();
		s.pop_front();

		for (auto it = t[node].begin(); it != t[node].end(); it++) {
			int i = it->first;
			int c = it->second;
			if (c != 0 && dist[i] == -1) {
				dist[i] = dist[node] + c;
				s.push_back(i);
			}
		}
	}
	//vector<ll>ans(n);
	rep(i, q) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << dist[x] + dist[y]<<endl;
		//ans[i] = dist[x] + dist[y];

	}
	//rep(i, q)cout << ans[i] << endl;




	return 0;
}



