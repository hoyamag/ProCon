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
//	int n, k;
//	cin >> n >> k;
//	priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, greater<pair<ull, ull>>>a;
//	rep(i, n) {
//		int t, b;
//		cin >> t >> b;
//		a.push(make_pair(t, b));
//	}
//	ull ans = 0;
//	rep(i, k) {
//		auto t = a.top();
//		ans += t.first;
//		a.pop();
//		a.push(make_pair(t.first + t.second, t.second));
//
//	}
//	cout << ans << endl;
//	return 0;
//}
//
//
//
