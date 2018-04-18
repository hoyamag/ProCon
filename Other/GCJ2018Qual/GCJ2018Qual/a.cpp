//#include<bitset>
//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cstdio>
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
//#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
//#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
//#define all(t) t.begin(), t.end()
//#define rall(t) t.rbegin(), t.rend()
//#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
//#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
//#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
//char S = 'S', C = 'C';
//vector<ll> damage(string p, ll &sum) {
//	ll da = 1;
//	vector<ll>d(p.length(), 0);
//	rep(i, 0, p.length()) {
//		if (p[i] == S) {
//			sum += da;
//		}
//		else {
//			da *= 2;
//		}
//		d[i] = da;
//	}
//	return d;
//}
//void ope(vector<ll>&da, string &p, ll &sum) {
//	int n = p.length();
//	for (int i = n - 1; i >= 1; i--) {
//		if (p[i] == S && p[i - 1] == C) {
//			swap(p[i], p[i - 1]);
//			da[i - 1] /= 2;
//			sum -= da[i - 1];
//			break;
//		}
//	}
//}
//ll solve(ll d, string p) {
//	int cnt = 0;
//	int n = p.length();
//	rep(i, 0, n)if (p[i] == S)cnt++;
//	if (cnt > d)return -1;
//	ll sum = 0;
//	vector<ll>da = damage(p, sum);
//	cnt = 0;
//	while (sum > d) {
//		ope(da, p, sum);
//		cnt++;
//	}
//	return cnt;
//
//}
//int main() {
//	int t;
//	cin >> t;
//	vector<ll>d(t);
//	vector<string>p(t);
//	rep(i, 0, t)cin >> d[i] >> p[i];
//	rep(i, 0, t) {
//		ll ans = solve(d[i], p[i]);
//		cout << "Case #" << i + 1 << ": ";
//		if (ans == -1)cout << "IMPOSSIBLE" << endl;
//		else cout << ans << endl;
//	}
//
//
//
//
//	return 0;
//}
//
//
//
