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
//	int a, b, c, x, y;
//	cin >> a >> b >> c >> x >> y;
//	vector<int>dp(max(x, y) + 1, 0);
//	repc(i, 0, x) {
//	}
//	
//	repc(i, 1, min(x, y)) {
//		dp[i] = min(dp[i-1] + a + b, dp[i-1] + 2 * c);
//	}
//	ll sum = dp[min(x, y)];
//	int d = max(x, y) - min(x, y);
//	bool greaterA = x > y;
//	if (greaterA) {
//		sum += d*min(a, 2 * c);
//	}
//	else {
//		sum += d*min(b, 2 * c);
//	}
//	cout << sum << endl;
//	
//	return 0;
//}
//
//
//
