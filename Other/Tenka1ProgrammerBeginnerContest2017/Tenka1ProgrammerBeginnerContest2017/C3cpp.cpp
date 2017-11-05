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
//	long long N;
//	cin >> N;
//	long long lim = 3501;
//	long long h, n, w;
//	h = n = w = 3*N/4 +1;
//	while (1) {
//		long long le = 4 * h*n*w;
//		long long ri = N*(n*w + h*w + h*n);
//		if (le == ri)break;
//		else if (le > ri) {
//			long long m = max({ h, n, w });
//			if (m == h) h--;
//			else if(m == n) n--;
//			else if (m == w)w--;
//
//		}
//		else {
//			long long m = min({ h, n, w });
//			if (m == h) h++;
//			else if (m == n) n++;
//			else if (m == w)w++;
//
//		}
//	}
//
//	cout << h << " " << n << " " << w;
//	return 0;
//}
//
//
//
