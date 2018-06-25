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
int ketawa(ll n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;

	}
	return sum;
}
int main() {
	ll k;
	cin >> k;
	rep(i, 0, min(9LL, k)) {
		cout << i + 1 << endl;
	}
	if (k > 9) {
		ll n = 19;
		ll diff = 10;
		vector<ll>co(11, LLONG_MAX);
		rep(cnt, 0, k - 9) {
			ll mi=LLONG_MAX;
			if (cnt % 10 == 0) {
				ll nn = n;
				ll dd = diff;
				rep(i, 0, 9) {
					co[i] = nn;
					nn += dd;
				}
				mi = *min_element(all(co));

			}
			rep(i, 0, 9) {
				if (mi == co[i]) {
					cout << n;
					cout << " " << (double)n / ketawa(n);
					n += diff;
					cout << endl;
					mi = co[i + 1];
					cnt++;
					if (cnt == k) {
						return 0;
					}
				}
				else {
					diff *= 10;

				}
			}
			cnt--;
		}

	}


	return 0;
}



