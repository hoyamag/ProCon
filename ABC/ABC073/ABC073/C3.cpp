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
//	const ul M = 1e9;
//	ul n;
//	cin >> n;
//	vector<ul> a = vector<ul>(n, 0);
//	rup(i, 0, n)cin >> a[i];
//
//	ul e = 0;
//	rup(i, 0, n) {
//
//		ul count = 1;
//		if (a[i] != 0) {
//			rup(j, i + 1, n) {
//				if (a[i] == a[j]) {
//					a[j] = 0;
//					count++;
//				}
//			}
//			if (count % 2 != 0) e++;
//		}
//	}
//	cout << e;
//
//
//	return 0;
//}
//
//
//
