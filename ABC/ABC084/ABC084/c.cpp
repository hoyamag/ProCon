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
//
//#include<stdlib.h>
//int main() {
//	int a = 1, b = 2;
//	swap(a, b);
//	int n;
//	cin >> n;
//	vector<int>c(n - 1), s(n - 1), f(n - 1);
//	rep(i, n - 1)cin >> c[i] >> s[i] >> f[i];
//	vector<int> duration(n, 0);
//	rep(i, n) {
//		int t = 0;
//		for (int j = i; j < n-1; j++) {
//			if (t <= s[j]) {
//				t = s[j];
//			}
//			else if (t%f[j]==0) {
//				t = t;
//			}
//			else {
//				t = t + f[j] - (t%f[j]);
//			}
//			t += c[j];
//		}
//		duration[i] = t;
//
//	}
//	rep(i, n)cout << duration[i] << endl;
//	return 0;
//}
//
//
//
