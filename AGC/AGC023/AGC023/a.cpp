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
	cin >> n;
	vector<ll>a(n);
	rep(i, 0, n)cin >> a[i];
	vector<ll>cs(n, 0);
	cs[0] = a[0];
	rep(i, 1, n)cs[i] += cs[i - 1] + a[i];
	ll cnt = 0;
	vector<ll>b(n, 0);

	rep(i, 1, n)b[i] = cs[i - 1];
	rep(i, 0, n) {
		rep(j, i, n) {
			if (cs[j] == b[i])cnt++;

		}
	}

	cout << cnt;

	return 0;
}



