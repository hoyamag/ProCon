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
int bit(int n, int th) {
	return (n >> th) & 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	auto cake = mat(ll, 3, n, 0);
	auto tmpcake = mat(ll, 3, n, 0);
	rep(i, 0, n) {
		rep(j, 0, 3)cin >> cake[j][i];
	}
	ll ma = 0;
	rep(com, 0, 8) {
		rep(i, 0, 3) {
			int sign = (bit(com, i) ? -1 : 1);
			rep(j, 0, n) {
				tmpcake[i][j] = sign*cake[i][j];
			}
		}
		vector<ll>sum(n,0);
		rep(j, 0, n) {
			rep(i, 0, 3) {
				sum[j] += tmpcake[i][j];
			}
		}
		sort(all(sum));
		ll whole = 0;
		rep(k, 0, m)whole += sum[k];
		ma = max(ma, abs(whole));

	}
	cout << ma << endl;;
	return 0;
}



