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
//int main() {
//	long long n;
//	cin >> n;
//	vector<long long>d(n, 0);
//	for (long long i = 0; i < n; i++)cin >> d[i];
//	long long m;
//	cin >> m;
//	vector<long long>t(m, 0);
//	for (long long i = 0; i < m; i++)cin >> t[i];
//	sort(d.begin(), d.end());
//	sort(t.begin(), t.end());
//	long long begin = 0;
//	for (long long i = 0; i < m; i++) {
//		for (long long j = begin; j < n; j++) {
//			if (d[j] == t[i]) {
//				begin = j + 1;
//				break;
//			}
//			else if (d[j] > t[i]) {
//				cout << "NO";
//				return 0;
//			}
//
//		}
//	}
//	cout << "YES";
//	return 0;
//}
//
//
//
