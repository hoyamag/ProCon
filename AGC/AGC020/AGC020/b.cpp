//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
//#include<sstream>
//#include<list>
//#include<queue>
//#include<algorithm>
//#include<functional>
//#include<map>
//#include<set>
//#include<utility>
//#include<initializer_list>
//#include<tuple>
//#include<regex>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define all(t) t.begin(), t.end()
//
//
//int main() {
//	int k;
//	cin >> k;
//	vector<ll>a(k + 1);
//	rep(i, k) cin >> a[i + 1];
//	vector<ll>nl(k + 1, 0), nr(k + 1, 0);
//	nl[k] = nr[k] = 2;
//	for (int i = k - 1; i >= 0; i--) {
//		nl[i] = max(nl[i + 1], a[i + 1]);
//		nr[i] = nl[i] + a[i + 1] - 1;
//	}
//	cout << nl[0] << " " << nr[0];
//
//
//
//	return 0;
//}
//
//
//
