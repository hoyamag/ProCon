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
	ll a, b, c, k;
	cin >> a >> b >> c >> k;
	bool odd = k % 2;
	ll ans = -1;
	if (k <=1000) {
		rep(i, 0, k) {
			ll na, nb, nc;
			na = b + c;
			nb = a + c;
			nc = a + b;
			a = na;
			b = nb;
			c = nc;
		}
		ans = a - b;
	}
	else {
		if (odd) {
			ans = -a + b;

		}
		else { ans = a - b; }

	}

	abs(ans) >= 1000000000000000000L ? cout << "Unfair": cout << ans;

	return 0;
}



