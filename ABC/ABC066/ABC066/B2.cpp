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
//using namespace std;
//#define ul unsigned long long
//
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//bool isGoo(string s) {
//	bool res;
//	if (s.length() % 2 != 0) return false;
//	for (int i = 1; i < s.length(); i++) {
//		string part = string(s, 0, i);
//		string other = string(s, i, s.length());
//		int index = 0;
//		while (1) {
//			string otherone = string(other, index, part.length());
//			if (part != otherone) {
//				break;
//			}
//			index += part.length();
//			if (index == other.length()) {
//				return true;
//			}
//
//		}
//	}
//	return false;
//}
//
//int main() {
//	string s;
//	cin >> s;
//	int length = 0;
//	for (int i = 1; i < s.length(); i++) {
//		string str = string(s, 0, s.length() - i);
//		if (isGoo(str)) {
//			length = str.length();
//			break;
//		}
//	}
//	cout << length;
//	return 0;
//}
//
//
//
