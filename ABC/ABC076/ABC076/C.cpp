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
//int main() {
//	string s;
//	string t;
//	cin >> s >> t;
//	int j = 0;
//	for (int i = 0; i < s.length(); i++) {
//		if (s[i] == t[0]) {
//			bool f = true;
//			for (int j = 0; j < t.length(); j++) {
//				if (s[i + j] != t[j] && s[i+j]!='?') {
//					f = false;
//					break;
//				}
//				
//			}
//			if (f) {
//				for (int j = 0; j < i; j++) {
//					if (s[j] == '?') s[j] = 'a';
//				}
//				for (int j = 0; j < t.length(); j++) {
//					s[i + j] = t[j];
//				}
//				for (int j = i + t.length(); j < s.length(); j++) {
//					if (s[j] == '?') s.erase(j);
//				}
//				break;
//			}
//			
//		}
//	}
//	cout << s;
//	return 0;
//}
//
//
//
