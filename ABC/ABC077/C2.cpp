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
//
//long long mysum(vector<int> a, int i) {
//	//a[i, i+1, ..., N]ÇÃçáåvÇï‘Ç∑
//	static vector<long long>s(100003, -1);
//	if (s[i] != -1)return s[i];
//	else if (i >= a.size()) return 0;
//	else {
//		s[i] = a[i] + mysum(a, i + 1);
//		return s[i];
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n, 0);
//	vector<int>b(n, 0);
//	vector<int>c(n, 0);
//
//	for (int i = 0; i < n; i++) cin >> a[i];
//	for (int i = 0; i < n; i++)cin >> b[i];
//	for (int i = 0; i < n; i++)cin >> c[i];
//
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	sort(c.begin(), c.end());
//	vector<int> bch(n);
//	for (int i = 0; i < n; i++) {
//		bch[i] = distance(lower_bound(c.begin(), c.end(), b[i] + 1), c.end());
//	}
//
//	long long sum = 0;
//	for (int i = 0; i < n; i++) {
//		auto ilb = lower_bound(b.begin(), b.end(), a[i] + 1);
//		int lb = distance(b.begin(), ilb);
//
//		sum += mysum(bch, lb);
//	}
//	cout << sum;
//	return 0;
//}
//
//
//
