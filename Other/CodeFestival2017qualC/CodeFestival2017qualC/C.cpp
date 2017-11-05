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
//bool kaibun(string s) {
//	int n = s.length();
//	for (int i = 0; i < (int)s.length()/2+1; i++) {
//		if (s[i] != s[n - 1 - i])return false;
//	}
//	return true;
//}
//int main() {
//	string s;
//	cin >> s;
//	string rmx = s;
//	int xnum = 0;
//	for (auto it = rmx.begin(); it != rmx.end();) {
//
//		if (*it == 'x') {
//			it = rmx.erase(it);
//			xnum++;
//		}
//		else it++;
//	}
//	bool kai = kaibun(rmx);
//	if (s.length() == 1) {
//		cout << "0";
//		return 0;
//	}
//	int count = 0;
//	if (kai) {
//		int pi = (int)ceil(rmx.length() / 2.0);
//		list<char> st(0);
//		int i = 0;
//		int j = 0;
//		while (true) {
//
//			st.push_back(s[i]);
//			i++;
//			if (s[i] == rmx[j]) j++;
//			if (i == (int)ceil(s.length() / 2.0)) {
//				break;
//			}
//		}
//		i = 0;
//		int pivot = (int)ceil(s.length() / 2.0);
//		while (!st.empty()) {
//			char a = st.back();
//			st.pop_back();
//			if (a != s[pivot + i]) {
//				while (a != s[pivot + i]) {
//					count++;
//					i++;
//				}
//			}else i++;
//		}
//		//count += s.length() - i;
//	}
//	else {
//		cout << "-1";
//		return 0;
//	}
//	cout << count;
//	return 0;
//}
//
//
//
