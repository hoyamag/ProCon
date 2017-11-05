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
//int upperbound(list<long long> a, long long ub, int begin, int end) {
//	if (end - begin == 1) {
//		if (a.front()< ub)	return begin;
//		else return -1;
//	}
//	if (a.front() >= ub) return -1;
//	else {
//
//		int mid = (int)(end + begin) / 2;
//		long long low = upperbound(a, ub, mid, end);
//		if (low != -1) return low;
//		long long up = upperbound(a, ub, begin, mid);
//		return up;
//	}
//
//
//}
//int main() {
//
//	long long n, c;
//	cin >> n >> c;
//	list<long long>b(0);
//	for (int i = 0; i < n; i++) {
//		long long v;
//		cin >> v;
//		b.push_back(v);
//	}
//	b.sort();
//	long long boxnum = 0;
//	int i = 0;
//	while (b.size() > 1) {
//		
//		int index = upperbound(b, c - b.front(), 0, b.size());
//		if (index != -1 && index!=0) {
//			auto itr = b.begin();
//			for (int i = 0; i < index; i++)itr++;
//			b.erase(itr);
//			b.pop_front();
//			boxnum += 1;
//		}
//		else {
//			boxnum++;
//			b.pop_front();
//		}
//	}
//	boxnum+=b.size();
//	
//	cout << boxnum;
//	return 0;
//}
//
//
//
//
