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
//	long n, a, b;
//	cin >> n >> a >> b;
//
//	if (a > b) {
//		cout << 0 << endl;
//		return 0;
//	}
//	if (n == 1) {
//		if (a == b) {
//			cout << 1 << endl;
//		}
//		else {
//			cout << 0 << endl;
//		}
//		return 0;
//
//	}
//
//	long minSum = (n - 1)*a + b;
//	long maxSum = a + (n - 1)*b;
//	
//	cout << maxSum - (minSum - 1) << endl;
//	return 0;
//}