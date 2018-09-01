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
int value(int n, int k) {
	int ans = 0;
	repc(a, 1, n) {
		if ((n + a) % k != 0) continue;
		repc(b, a, n) {
			if ((b + n) % k != 0) continue;
			if ((a + b) % k == 0) {
				if (a == b&&b == n&&n == a) {
					ans++;
					//cerr << a << " " << b << " " << n << endl;
				}
				else {
					ans += 3;
					//cerr <<"3: "<< a << " " << b << " " << n << endl;
				}
			}
			b += k - 1;
		}
		a += k - 1;

	}


	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	vector<int> ans(n + 1, 0);
	repc(i, 1, n) {
		ans[i] = ans[i - 1] + value(i, k);
	}
	cout << ans[n] << endl;

	return 0;
}



