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
//
//int main() {
//	string s;
//	cin >> s;
//	int n = s.length();
//	int cnt = 0;
//	char next;
//	int repd = 0;
//	while (repd < n) {
//		int prerepd = repd;
//		next = '2';
//		rep(i, n) {
//			if (s[i] == next) {
//				s[i] = '0';
//				repd++;
//				next = next == '2' ? '5' : '2';
//			}
//		}
//		cnt++;
//		if (repd == prerepd)break;
//
//	}
//	if (repd == n && next == '2')	cout << cnt << endl;
//	else cout << -1 << endl;
//	return 0;
//}
//
//
//
