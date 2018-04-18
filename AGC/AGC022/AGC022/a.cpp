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
//int main() {
//	string s;
//	cin >> s;
//	int n = s.length();
//	set<char>m;
//	rep(i, 0, n)m.insert(s[i]);
//	string ans;
//	if (m.size() == 26) {
//		if (s == "zyxwvutsrqponmlkjihgfedcba") {
//			cout << -1 << endl;
//			return 0;
//		}
//		for (int i = 25; i >= 0; i--) {
//			m.erase(s[i]);
//			for (char j = 'a'; j <= 'z'; j++) {
//				if (m.find(j) == m.end()) {
//					ans = s.substr(0, i);
//					ans[ans.length() - 1] = j;
//					if (ans > s) {
//						cout << ans;
//						return 0;
//					}
//				}
//			}
//		}
//	}
//	else {
//		cout << s;
//		for (char j = 'a'; j <= 'z'; j++) {
//
//			if (m.find(j) == m.end()) {
//				cout << j << endl;
//				return 0;
//			}
//		}
//
//	}
//
//}
//
//
//
