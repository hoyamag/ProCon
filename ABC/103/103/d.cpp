#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
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
#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
#define DBG(str) cerr<<(str)<<endl;
bool pcom(pair<int, int>a, pair<int, int>b) {
	return a.second < b.second;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>a(m);
	vector<pair<int, int>>b(m);
	map<int, list<pair<int, int>*>>c;
	rep(i, 0, m) {
		int ta, tb;
		cin >> ta >> tb;
		a[i].first = min(ta, tb);
		a[i].second = max(ta, tb);
		b[i] = a[i];

	}

	sort(all(a));
	sort(all(b), pcom);
	rep(i, 0, m) {
		c[b[i].first].push_back(&b[i]);

	}
	int cnt = 0;
	int j = 0;
	rep(i, 0, m) {
		int t = b[i].second;
		if (t > 0) {
			cnt++;
			while (j < m && a[j].first < t) {
				while (!c[a[j].first].empty()) {
					auto p = c[a[j].first].front();
					c[a[j].first].pop_front();
					p->second = -1;
				}
				j++;
			}
		}
	}

	cout << cnt;



	return 0;
}



