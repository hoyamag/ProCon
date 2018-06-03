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
//#define ul long long
//
//#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
//#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)
//
//int main() {
//	ul n;
//	cin >> n;
//	vector<ul>a = vector<ul>(n, (ul)0);
//	for (ul i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	vector<ul>b = vector<ul>(n, (ul)0);
//
//	if (n % 2 == 0) {
//		for (ul i = 0; i < n; i++) {
//			if (n - 2 * i - 1 >= 1) {
//				b[i] = a[n - 2 * i - 1];
//			}
//			else {
//				b[i] = a[ 2 * i -n];
//			}
//		}
//	}
//	else {
//		for (ul i = 0; i < n; i++) {
//			if (n - 2 * i - 1 >= 0) {
//				b[i] = a[n - 2 * i - 1];
//			}
//			else {
//				b[i] = a[2 * i - n];
//			}
//		}
//	}
//
//	cout << b[0];
//	for (ul i = 1; i < n; i++) cout << " "<<b[i];
//
//	return 0;
//}
//
//
//
