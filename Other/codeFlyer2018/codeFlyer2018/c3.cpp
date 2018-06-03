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
	int n;
	ll d;
	cin >> n >> d;
	vector<ll>x(n);
	rep(i, 0, n)cin >> x[i];
	
	vector<ll>ks(n + 2, 0);
	vector<ll>cs(n + 2, 0);
	rep(i, 1, n) {
		auto it = upper_bound(all(x), x[i-1] + d);
		ll dis = distance(x.begin(), it);
		ks[i] = n-dis;
		cs[i] += cs[i - 1] + ks[i];
	}
	ll cnt = 0;
	rep(j, 1, n) {
		ll imin = x[j] - d;
		ll kmax = x[j] + d;
		int iximin = distance(x.begin(), lower_bound(all(x), imin));
		if (ks[j] == 0)break;
		if (iximin == 0)cnt += cs[j ];
		else cnt += cs[j] - cs[iximin];
		cerr << j << ":" << cnt << endl;



	}
	cout << cnt;
	return 0;
}



