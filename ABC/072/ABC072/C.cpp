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
//	long n;
//	cin >> n;
//	vector<long>a = vector<long>(n);
//	rup(i, 0, n)cin >> a[i];
//	const long range = 1e5 + 1;
//	vector<long>bucket = vector<long>(range, 0);
//	for (int i = 0; i < n; i++) {
//		bucket[a[i]]++;
//	}
//	vector<long>fixed = vector<long>(range, 0);
//	fixed[0] = bucket[0] + bucket[1];
//	fixed[range - 1] = bucket[range - 2] + bucket[range - 1];
//	for (long i = 1; i < range-1; i++) {
//		fixed[i] = bucket[i - 1] + bucket[i] + bucket[i + 1];
//	}
//	long max = *max_element(fixed.begin(), fixed.end());
//	cout << max<<endl;
//	return 0;
//}
//
//
//
