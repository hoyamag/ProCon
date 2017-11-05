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
//using namespace std;
//
//bool match(string s, string t) {
//	if (s.length() != t.length()) return false;
//	for (int i = 0; i < s.length(); i++) {
//		if (!(s[i] == t[i] || s[i] == '?')) return false;
//	}
//	return true;
//}
//int main() {
//	string s;
//	string t;
//	cin >> s >> t;
//	vector<string> ansAll;
//	bool rep = false;
//	for (int i = s.length()-1; i >= 0; i--) {
//		string sub = s.substr(i, t.length());
//		if (match(sub, t)) {
//			string ans = s;
//			for (int j = 0; j < s.length(); j++) {
//				if (j < i) {
//					if (s[j] == '?') ans[j] = 'a';
//					else ans[j] = s[j];
//				}
//				else if (j < i + t.length()) {
//					ans[j] = t[j-i];
//				}
//				else {
//					if (s[j] == '?') ans[j] = 'a';
//				}
//			}
//			ansAll.push_back(ans);
//			rep = true;
//		}
//	
//	
//	}
//	if (rep) {
//		string r = *min_element(ansAll.begin(), ansAll.end());
//		cout << r;
//	}
//	else cout << "UNRESTORABLE";
//	return 0;
//}
//
//
//
