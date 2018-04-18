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
	ll n;
	cin >> n;
	vector<ll>a(n);
	rep(i, 0, n)cin >> a[i];
	sort(all(a));
	ll ai = a[n - 1];
	vector<ll>b(a.begin(), a.end() - 1);
	ll z = ai / 2;
	auto index = lower_bound(b.begin(), b.end(), z);
	int d = distance(b.begin(), index);
	int mi = INT_MAX;
	ll ans = -1;
	for (int i = max(0,d - 1); i <= min(d+2 ,(int)b.size()-1); i++) {
		int con = abs(b[i] - z);
		if (con<= mi) {
			mi = con;
			ans = b[i];
		}

	}
	cout << ai << " " << ans;

	return 0;
}



