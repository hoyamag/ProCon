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
//	int size = 26;
//	vector<int> v = vector<int>(size, 0);
//	rup(i, 0, s.length()) v[s[i] - 'a']++;
//	int max = 0;
//	int mi;
//	rup(i, 0, v.size()) {
//		if (max < v[i]) {
//			max = v[i];
//			mi = i;
//		}
//	}
//	char c = mi + 'a';
//	int result = 0;
//	while (1) {
//		bool flag = true;
//
//		//judge
//		int count = 0;
//		rup(i, 0, s.length()) {
//			if (s[i] == c) count++;
//		}
//		if (count == s.length()) break;
//		result++;
//		
//		//erase
//		int diffmax = 0;
//		int erase_index = -1;
//		int a = 0, b = 0;
//		rup(i, 0, s.length()) {
//			if (s[i] == c) {
//				b = i-1;
//			}
//			else if (i == s.length() - 1) {
//				b = i;
//			}
//			if (diffmax < b - a) {
//				diffmax = b - a;
//				erase_index = b;
//			}
//			a = b;
//		}
//		string t="";
//		rup(i, 0, s.length()) {
//			if (i != erase_index) t += s[i];
//		}
//		s = t;
//
//		//change
//		rup(i, 1, s.length()) {
//			if (s[i] == c) {
//				s[i - 1] = c;
//			}
//
//		}
//
//	}
//	cout << result;
//	return 0;
//}
//
//
//
