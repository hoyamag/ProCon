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
//ul frac(int n) {
//	ul res = 1;
//	for (int i = 1; i <= n; i++) {
//		res *= i;
//		if (res > (ul)1e9) res /= (1e9 + 7);
//	}
//	return res;
//}
//
//int main() {
//	int n, m;
//	cin >> n >> m;
//	if (abs(n - m) > 1) {
//		cout << 0;
//	}
//	else {
//		ul h = frac(100000);
//		ul monkey, dog;
//		dog = frac(n);
//		monkey = frac(m);
//		if (n == m) {
//			cout << (2 * dog * monkey) % ((ul)1e9 + 7);
//		}
//		else {
//			cout << (dog * monkey) % ((ul)1e9 + 7);
//		}
//	}
//	return 0;
//}
//
