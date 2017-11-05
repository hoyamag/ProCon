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
//long mymax(vector<long> &a, int end) {
//	//a is soreted
//	if (a[end -1] > a[end]) {
//		swap(a[end-1], a[end]);
//	}
//	return a[end];
//}
//
//void bomb(vector<long> &h, long a, long b, int index, long &deadline) {
//	deadline += b;
//	h[index] -= a - b;
//
//}
//
//
//int main() {
//	int n, a, b;
//	cin >> n >> a >> b;
//	vector<long> h = vector<long>(n, 0);
//	for (int i = 0; i < n; i++) cin >> h[i];
//	long count = 0;
//	sort(h.begin(), h.end());
//	long deadline = 0;
//	int max_i = h.size()-1;
//	while (1) {
//		long minNum = mymax(h, max_i) % a;
//		if (h[max_i] <= 0) break;
//
//		count += minNum;
//		deadline = b*minNum;
//		h[max_i] = 0;
//		max_i--;
//	}
//
//	cout << count << endl;
//	return 0;
//}
//
//
//
