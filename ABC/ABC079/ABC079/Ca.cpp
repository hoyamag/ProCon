//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
//#include<sstream>
//#include<list>
//#include<queue>
//#include <algorithm>
//#include<initializer_list>
//#include<map>
//#include<set>
//#include<utility>
//#include<tuple>
//using namespace std;
//#define ull unsigned long long
//#define llong long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define all(t) t.begin(), t.end()
//
//int main() {
//	string s;
//	cin >> s;
//	int n = 4;
//	vector<int>a(n, 0);
//	rep(i, n)a[i] = s[i] - '0';
//	rep(i, 1 << 3) {
//		int ans = a[0];
//		rep(j, 3)ans = (i & 1<<j) ? ans - a[j+1] : ans + a[j+1];
//		if (ans == 7) {
//			string f = "0-0-0-0=7";
//			rep(k, 4)f[k * 2] = a[k] + '0';
//			rep(k, 3)f[k * 2 + 1] = (i >> k & 1) ? '-' : '+';
//			cout << f << endl;
//			return 0;
//		}
//	}
//	return 0;
//}
//
//
//
