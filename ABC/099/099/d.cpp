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




int main() {

	int n,C;
	cin >> n>>C;
	auto d = mat(int, C, C, 0);
	rep(i, 0, C) {
		rep(j, 0, C) {
			cin >> d[i][j];
		}
	}
	auto c = mat(int, n, n, 0);
	rep(i, 0, n) {
		rep(j, 0, n)cin >> c[i][j];
	}

	auto cost = mat(int, 3, C, 0);
	rep(i, 0, 3) {
		rep(j, 0, C) {
			rep(k, 0, n)rep(l, 0, n) {
				if((k+l)%3==i) cost[i][j] += d[c[k][l]-1][j];
			}

		}
	}
	int mi = INT32_MAX;
	rep(g1, 0, C) {
		rep(g2, 0, C) {
			rep(g3, 0, C) {
				if (g1 == g2 || g2 == g3 || g3 == g1)continue;
				mi = min(mi, cost[0][g1] + cost[1][g2] + cost[2][g3]);
			}
		}
	}
	cout << mi;


	return 0;
}



