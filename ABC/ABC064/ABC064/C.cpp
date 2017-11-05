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
//#define rep(a, b) for(int i = a; i < b; i++)
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int> a = vector<int>(n, 0);
//	rep(0, n) cin >> a[i];
//
//	int c = 0;
//	vector<int> arr = vector<int>(9, 0);
//	for (int i = 0; i < n; i++) {
//		int r = a[i];
//		if (r >= 3200) {
//			c = 1;
//		}
//		else if (r >= 2800) {
//			c = 2;
//		}
//		else if (r >= 2400) {
//			c = 3;
//		}
//		else if (r >= 2000) {
//			c = 4;
//		}
//		else if (r >= 1600) {
//			c = 5;
//		}
//		else if (r >= 1200) {
//			c = 6;
//		}
//		else if (r >= 800) {
//			c = 7;
//		}
//		else if (r >= 400) {
//			c = 8;
//		}
//		else if (r >= 1) {
//			c = 9;
//		}
//		arr[c - 1]++;
//	}
//
//	int colors = 0;
//	for (int i = 1; i < arr.size(); i++) {
//		if (arr[i] != 0) colors++;
//	}
//	int minColors = colors;
//	if (minColors == 0) {
//		if (arr[0] != 0) minColors = 1;
//	}
//	int maxColors = colors + arr[0];
//	/*if (maxColors >= arr.size() - 1) {
//		maxColors = arr.size() - 1;
//	}*/
//	cout << minColors << " " << maxColors << endl;
//	return 0;
//}
//
//
//
