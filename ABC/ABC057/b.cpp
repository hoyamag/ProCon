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
int md(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n), b(n);
	rep(i, n)cin >> a[i] >> b[i];
	vector<int>c(m), d(m);
	vector<int>dist(n,INT32_MAX);
	vector<int>ans(n, -1);
	rep(i, m)cin >> c[i] >> d[i];
	rep(i, n) {
		rep(j, m) {
			int cand = min(dist[i], md(a[i], b[i], c[j], d[j]));
			if (cand < dist[i]) {
				dist[i] = cand;
				ans[i] = j + 1;
			}
		}
	}
	rep(i, n)cout << ans[i] << endl;


	return 0;
}


