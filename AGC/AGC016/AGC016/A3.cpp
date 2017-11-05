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
//
//int main() {
//	string s;
//	cin >> s;
//	string str = s;
//	int wholeResult = INT_MAX;
//	rup(loopCount, 0, str.length()) {
//		int result = 0;
//		char same = str[loopCount];
//
//		s = str;
//		while (1) {
//			bool flag = true;
//			//judge
//			int count = 0;
//			rup(i, 0, s.length()) {
//				if (s[i] == same) count++;
//			}
//			if (count == s.length()) break;
//			result++;
//
//			//erase
//			int diffmax = 0;
//			int erase_index = -1;
//			int a = 0, b = 0;
//			rup(i, 0, s.length()) {
//				if (s[i] == same) {
//					b = i - 1;
//				}
//				else if (i == s.length() - 1) {
//					b = i;
//				}
//				if (diffmax < b - a) {
//					diffmax = b - a;
//					erase_index = b;
//				}
//				a = b;
//			}
//			string t = "";
//			rup(i, 0, s.length()) {
//				if (i != erase_index) t += s[i];
//			}
//			s = t;
//
//			//change
//			rup(i, 1, s.length()) {
//				if (s[i] == same) {
//					s[i - 1] = same;
//				}
//
//			}
//		}
//		if (result < wholeResult) wholeResult = result;
//	}
//	cout << wholeResult;
//	return 0;
//}
//
//
//
