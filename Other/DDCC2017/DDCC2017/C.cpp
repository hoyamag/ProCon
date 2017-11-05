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
//int upperbound(vector<long long> a, long long ub, int begin, int end) {
//	long long pre = -1;
//	for (long long i = begin; i < end; i++) {
//		if (a[i] >= ub) break;
//		pre = i;
//	}
//	return pre;
//}
//int main() {
//
//	long long n, c;
//	cin >> n >> c;
//	vector<long long>b(n, 0);
//	for (int i = 0; i < n; i++) cin >> b[i];
//	sort(b.begin(), b.end());
//	long long boxnum = 0;
//	int i = 0;
//	while (b.size() > 1) {
//		int index = upperbound(b, c - b[0], 0, b.size());
//		if (index != -1 && index != 0) {
//			b.erase(b.begin() + index);
//			b.erase(b.begin());
//			boxnum += 1;
//		}
//		else {
//			b.erase(b.begin());
//			boxnum++;
//		}
//	}
//	boxnum += b.size();
//
//	cout << boxnum;
//	return 0;
//}
//
//
//
//
