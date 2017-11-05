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
//
//int main() {
//	string s;
//	cin >> s;
//	int n{(int) s.size() };
//	for (int i = 0; i < n; i++) {
//	}
//
//	vector<vector<int>> p;
//	p = vector<vector<int>>(n, vector<int>(n, 0));
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (i == j) p[i][j] = 0;
//			else if (i < j) {// go up
//				if (s[i] == 'U') {
//					p[i][j] = 1;
//				}
//				else {
//					p[i][j] = 2;
//				}
//			}
//			else {// go down
//				if (s[i] == 'D') {
//					p[i][j] = 1;
//				}
//				else {
//					p[i][j] = 2;
//				}
//			}
//		}
//	}
//	long sum = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			sum += p[i][j];
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}