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
//	long n;
//	cin >> n;
//	vector<ul> a = vector<ul>(n, 0);
//	rup(i, 0, n) cin >> a[i];
//	sort(a.begin(), a.end());
//	
//	ul tyohen = 0, tanpen = 0;
//	ul tyohenIndex = 0;
//	for (ul i = a.size() - 2;; i--) {
//		if (a[i] == a[i + 1]) {
//			tyohen = a[i];
//			tyohenIndex = i;
//			break;
//		}
//
//		if (i == 0) break;
//	}
//	if (tyohenIndex >= 2) {
//		for (ul i = tyohenIndex - 2;; i--) {
//			if (a[i] == a[i + 1]) {
//				tanpen = a[i];
//				break;
//			}
//			if (i == 0) break;
//		}
//	}
//	
//	cout << tyohen*tanpen<<endl;
//
//	return 0;
//}
//
//
//
