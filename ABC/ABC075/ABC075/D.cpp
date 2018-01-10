
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
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
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()


int main() {
	// ABC075D
	int n, k;
	cin >> n >> k;
	vector<ll>ox(n), oy(n);
	rep(i, n)cin >> ox[i] >> oy[i];
	vector<ll>x(ox), y(oy);
	
	sort(all(x));
	sort(all(y));
	ll ans = 1LL*(x[n - 1] - x[0])*(y[n - 1] - y[0]);
	rep(xi, n) {
		for (int xj = xi + 1; xj < n; xj++) {
			rep(yi, n) {
				for (int yj = yi + 1; yj < n; yj++) {
					int cnt = 0;
					rep(i, n) {
						if (x[xi] <= ox[i] && ox[i] <= x[xj] && y[yi] <= oy[i] && oy[i] <= y[yj])cnt++;
					}

					if (cnt >= k) {
						ll area = (x[xj] - x[xi])*(y[yj] - y[yi]);
						ans = min(ans, area);
					}
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}



