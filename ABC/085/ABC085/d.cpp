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
	int n;
	ll h;
	cin >> n >> h;
	vector<ll>a(n), b(n);
	rep(i, n)cin >> a[i] >> b[i];
	int cnt = 0;

	sort(all(b), greater<ll>());

	ll ma = *max_element(all(a));
	rep(i, n) {
		if (b[i] > ma) {
			h -= b[i];
			cnt++;
			if (h <= 0) {
				break;
			}
		}
	}
	if (h > 0) {
		int a = (h + ma - 1) / ma;
		cnt += a;
	}
	cout << cnt << endl;
	return 0;
}



