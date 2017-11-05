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
//#include<map>
//#include<set>
//using namespace std;
//double ctx(int v1, int v0, int t0) {
//	return v1 - v0 - +t0;
//}
//double dist(int v1, int v0, int t1, int t0, int tx) {
//	return 1 / 2.0*(v1 - v0)*(tx-t0) + v0*(tx - t0) + max(0, v1*(t1 - tx));
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<int>v(n, 0);
//	vector<int>t(n, 0);
//	for (int i = 0; i < n; i++) cin >> t[i];
//	for (int i = 0; i < n; i++) cin >> v[i];
//	int cv = 0;
//	int ct = 0;
//	double dsum = 0;
//	for (int i = 0; i < n; i++) {
//		int p;
//		if (v[i] > cv)p = 1;
//		else if (v[i] < cv) p = -1;
//		else p = 0;
//		int tx = ctx(v[i], cv, ct);
//		double d = dist(v[i], cv, t[i], ct, tx);
//		dsum += d;
//		cv = tx < t[i] ? v[i]: cv + p*(tx-ct);
//		ct = t[i];
//	}
//	cout << dsum;
//	return 0;
//}
//
//
//
