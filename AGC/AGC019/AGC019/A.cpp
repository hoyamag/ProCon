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
//	ul q, h, s, d;
//	ul n;
//	cin >> q >> h >> s >> d;
//	cin >> n;
//
//	ul best1l = min({ 4*q, 2*h, s });
//	ul best2l = 0;
//	if (n >= 2) {
//		best2l = min({ d, 2 * best1l });
//	}
//	else {
//		best2l = 2 * best1l;
//	}
//
//	ul money = 0;
//	if (best2l == 2 * best1l) {
//		money = best1l*n;
//	}
//	else {
//		money = (ul)(n / 2)*best2l + best1l*(n % 2);
//	}
//	cout << money << endl;
//	return 0;
//}
//
//
//
