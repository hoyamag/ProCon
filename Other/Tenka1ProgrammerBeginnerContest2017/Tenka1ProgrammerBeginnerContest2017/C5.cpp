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
//	h = n = w = 1;// 3 * N / 4 + 1;
//	while (1) {
//		long long le = 4 * h*n*w;
//		long long ri = N*(n*w + h*w + h*n);
//		if (le == ri)break;
//		else if (le > ri) {
//			if (4 * n*w > N*(w + n) && h > 1) h--;
//			else h++;
//		}
//		else {
//			if (4 * n*w > N*(w + n)) h++;
//			else if (h > 1)h--;
//		}
//		le = 4 * h*n*w;
//		ri = N*(n*w + h*w + h*n);
//		if (le == ri)break;
//		else if (le > ri) {
//			if (4 * h*w > N*(h + w) && n > 1) n--;
//			else n++;
//		}
//		else {
//			if (4 * h*w > N*(h + w)) n++;
//			else if (n > 1)n--;
//		}
//		le = 4 * h*n*w;
//		ri = N*(n*w + h*w + h*n);
//		if (le == ri)break;
//		else if (le > ri) {
//			if (4 * h*n > N*(h + n) && w > 1) w--;
//			else w++;
//		}
//		else {
//			if (4 * h*n > N*(h + n)) w++;
//			else if (w > 1)w--;
//		}
//
//
//
//		cout << h << " " << n << " " << w << endl;
//	}
//
//	cout << h << " " << n << " " << w;
//	return 0;
//}
//
//
//
