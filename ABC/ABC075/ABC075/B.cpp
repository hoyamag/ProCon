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
//	int h, w;
//	cin >> h >> w;
//	vector<string> s(h);
//	for (int i = 0; i < h; i++) {
//		cin >> s[i];
//		for (int j = 0; j < w; j++) {
//			if (s[i][j] == '.') {
//				s[i][j] = '0';
//			}
//		}
//	}
//	for (int i = 0; i < h; i++) {
//		for (int j = 0; j < w; j++) {
//			if (s[i][j] == '#') {
//				for (int r = max(0, i - 1); r < min(h, i + 2); r++) {
//					for (int c = max(0, j - 1); c < min(w, j + 2); c++) {
//						if (r != i || c != j) {
//							if (s[r][c] != '#') s[r][c] = (char)((int)s[r][c] + 1);
//						}
//					}
//				}
//			}
//		}
//	}
//	for (int i = 0; i < h; i++)cout << s[i] << endl;
//	return 0;
//}
//
//
//
