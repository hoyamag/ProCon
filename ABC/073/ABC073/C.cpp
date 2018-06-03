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
//int main() {
//	const ul M = 1e9;
//	ul n;
//	cin >> n;
//	vector<ul> a = vector<ul>(n, 0);
//	rup(i, 0, n)cin >> a[i];
//	sort(a.begin(), a.end());
//	ul res = 0;
//	for (int i = 0; i < n; i++) {
//		ul seq = 1;
//		ul j;
//		for (j = i + 1; j < n; j++) {
//			if (a[j] == a[i]) seq++;
//			else break;
//		}
//		if (seq % 2 == 1)res++;
//		i = j-1;
//	}
//
//	cout << res;
//
//
//	return 0;
//}
//
//
//
