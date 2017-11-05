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
//	int n;
//	cin >> n;
//	vector<int>a(n, 0);
//	vector<int>c(101, 0);
//
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//		c[a[i]]++;
//	}
//	int cnt = 0;
//	int pet = 0, vas = 0;
//	for (int i = 0; i < 101; i++) {
//		if (c[i] != 0) cnt++;
//	}
//	if (cnt != 2) {
//		cout << "NO";
//		return 0;
//	}
//	auto maxiter = max_element(c.begin(), c.end());
//	int max = *maxiter;
//	c[distance(c.begin(), maxiter)] = 0;
//	auto miniter = max_element(c.begin(), c.end());
//	int min = *miniter;
//	if (max!=min) {
//		cout << "NO";
//		return 0;
//	}
//	cout << "YES"<<endl;
//	cout << distance(c.begin(), maxiter) << " " << distance(c.begin(), miniter);
//
//	return 0;
//}
//
//
//
