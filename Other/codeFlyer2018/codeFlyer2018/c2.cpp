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
//#define DBG(str) cerr<<(str)<<endl;
//int main() {
//	int n;
//	ll d;
//	cin >> n >> d;
//	vector<ll>x(n);
//	rep(i, 0, n)cin >> x[i];
//	ll cnt = 0;
//	rep(i, 0, n) {
//		ll lim = x[i] + d;
//		auto it = upper_bound(all(x), lim);
//		int kb = distance(x.begin(), it);
//		int je = kb - 1;
//
//		if (je <= i || kb >= n)continue;
//
//		rep(j, i + 1, je+1) {
//			int ke = distance(x.begin(), upper_bound(all(x), x[j] + d));
//			cnt += ke - kb;
//		}
//
//
//
//	}
//	cout<<cnt;
//	return 0;
//}
//
//
//
