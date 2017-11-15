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
//#include<cstdlib>
//#include<cmath>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//
//int main() {
//	ll n, z, w;
//	cin >> n >> z >> w;
//	vector<ll>a(n, 0);
//	for (int i = 0; i < n; i++)cin >> a[i];
//
//	vector<ll> mins(n, INT32_MAX);
//	mins[n - 1] = abs(a[n - 1] - w);
//	for (int i = 0; i < n; i++) {
//		for (int j = i + 1; j < n; j++) {
//			ll b = abs(a[i] - a[j]);
//			mins[i] = min(mins[i], b);
//		}
//	}
//	cout << *max_element(mins.begin(), mins.end())<<endl;
//
//	return 0;
//}
//
//
//
