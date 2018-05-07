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
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
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
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));

int main() {
  // AC
	int n;
	cin >> n;
	vector<int>a(n);
	vector<ll>cs(n, 0);
	rep(i, n) {
		cin >> a[i];
	}
	cs[0] = a[0];
	rep(i, n - 1) {
		cs[i + 1] = cs[i] + a[i + 1];
	}
	ll ans = LLONG_MAX;
	rep(i, n-1) {
		ans = min(ans, abs(cs[i] - (cs[n - 1] - cs[i])));
	}
	
	cout << ans;

	return 0;
}


