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
	vector<ll>a(n), b(n), d(n, 0);
	int pos = 0;
	bool all = true;
	rep(i, 0, n) {
		cin >> a[i] >> b[i];
		d[i] = a[i] - b[i];
		if (d[i] > 0)pos++;
		if (d[i] != 0)all = false;
	}
	if (all) {
		cout << 0;
		return 0;
	}
	if (pos < 2) {
		ll Aa = 0;
		ll Ab = 0;
		rep(i, 0, n) {
			if (d[i] > 0)Ab += d[i];
			else if (d[i] <= 0 && a[i] > 0)Aa += a[i];
		}

		cout << Aa + Ab;
	}
	else {
		ll sum = 0;
		ll mi = LLONG_MAX;
		rep(i, 0, n) {
			sum += a[i];
			if (d[i] > 0 && b[i] < mi) {
				mi = b[i];
			}
		}
		sum = sum - mi;
		cout << sum;
	}
	return 0;
}



