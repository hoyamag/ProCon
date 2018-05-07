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
//#include<bitset>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define all(t) t.begin(), t.end()
//ll ci(bitset<32> sis, bitset<32>fi) {
//	auto t = fi&sis;
//	return t.count();
//}
//ll prof(bitset<32>sis, vector<bitset<32>>f, vector<vector<ll>>p) {
//	ll n = f.size();
//	vector<ll> c(n);
//	rep(i, n) {
//		c[i] = ci(sis, f[i]);
//	}
//	ll sum = 0;
//	rep(i, n) {
//		sum += p[i][c[i]];
//	}
//	return sum;
//}
//int main() {
//	int n;
//	cin >> n;
//	string kk = "";
//	vector<bitset<32>>f(n,0);
//	rep(i, n) {
//		rep(j, 10) {
//			char k;
//			cin >> k;
//			kk.push_back(k);
//		}
//		f[i] = bitset<32>(kk);
//	}
//	vector<vector<ll>>p(n, vector<ll>(11));
//	rep(i, n)rep(j, 11)cin >> p[i][j];
//	ll ma = INT_MIN;
//	for (int i = 1; i < (1 << 10); i++) {
//		ma = max(ma, prof(i, f, p));
//	}
//	cout << ma << endl;
//	return 0;
//}
//
//
//
