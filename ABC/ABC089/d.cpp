//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
//#include<sstream>
//#include<list>
//#include<queue>
//#include<algorithm>
//#include<functional>
//#include<map>
//#include<set>
//#include<utility>
//#include<initializer_list>
//#include<tuple>
//#include<regex>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
//#define all(t) t.begin(), t.end()
//#define rall(t) t.rbegin(), t.rend()
//#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
//#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
//#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
//#define LIM 301
//int h, w, d;
//vector<vector<int>>a;
//int q;
//vector<int>l, r;
//vector<pair<int, int>>p;
//vector<ll>c(h*w + 1, -1);
//pair<int, int> cord(int v) {
//	if (p[v].first != -1)return p[v];
//	else {
//		rep(i, h)rep(j, w) {
//			p[a[i][j]] = { i,j };
//		}
//		return p[v];
//	}
//}
//ll dist(int x, int y, int i, int j) {
//	return abs(x - i) + abs(y - j);
//}
//ll cost(int v) {
//	if (c[v] != -1)return c[v];
//	else if (v <= d) return 0;
//	else {
//		auto cur = cord(v - d);
//		auto next = cord(v);
//		c[v] = cost(v - d) + dist(next.first, next.second, cur.first, cur.second);
//		return c[v];
//
//	}
//
//}
//int main() {
//	cin >> h >> w >> d;
//	a = vector<vector<int>>(h, vector<int>(w));
//	rep(i, h)rep(j, w)cin >> a[i][j];
//	cin >> q;
//	l = vector<int>(q);
//	r = vector<int>(q);
//	rep(i, q)cin >> l[i] >> r[i];
//	p = vector < pair<int, int>>(h*w + 1, { -1,-1 });
//	c = vector<ll>(h*w + 1, -1);
//	rep(i, q) {
//		cout << cost(r[i]) - cost(l[i]) << endl;
//	}
//	return 0;
//}
//
//
//
