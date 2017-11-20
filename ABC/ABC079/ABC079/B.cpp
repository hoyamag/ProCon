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
//#include<utility>
//#include<tuple>
//using namespace std;
//unsigned long long luca(int n) {
//	static vector<unsigned long long>m(100, -1);
//	if (n == 0) return 2;
//	else if (n == 1) return 1;
//	else if (m[n] != -1) return m[n];
//	{
//		m[n] = luca(n - 1) + luca(n - 2);
//		return m[n];
//	}
//}
//int main() {
//	int n;
//	cin >> n;
//	cout << luca(n);
//
//	return 0;
//}
//
//
//
