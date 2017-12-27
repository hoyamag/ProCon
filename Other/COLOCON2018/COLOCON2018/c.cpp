//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
//#include<sstream>
//#include<list>
//#include<queue>
//#include<algorithm>
//#include<functional>
//#include<map>
//#include<set>
//#include<utility>
//#include<initializer_list>
//#include<tuple>
//#include<regex>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define all(t) t.begin(), t.end()
//vector<ll> dp;
//ll gcd(ll a, ll b) {
//	while (b != 0) {
//		ll r = a%b;
//		a = b;
//		b = r;
//	}
//	return a;
//}
//ll solve(ll a, ll b) {
//	if (dp[b - a] != -1) return dp[b - a];
//	else {
//		ll merge = 0;
//		for (ll i = a; i < b; i++) {
//			if (a > 1) {
//				ll g = gcd(i, b);
//				merge += g == 1;
//			}
//			dp[b - a] = solve(a, b - 1) + merge;
//			return dp[b - a];
//		}
//	}
//}
//
//int main() {
//	dp = vector<ll>(35 + 1, -1);
//	dp[0] = 1;
//	cout << solve(2, 4)<<endl;
//	ll a, b;
//	cin >> a >> b;
//	dp = vector<ll>(b - a + 1, -1);
//	cout << solve(a, b) << endl;
//
//
//	return 0;
//}
//
//
//
