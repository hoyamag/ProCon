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
//int main() {
//	int n;
//	cin >> n;
//	vector<int>a(n);
//	rep(i, n)cin >> a[i];
//	sort(all(a));
//	int cnt = 1;
//	ull sum = 0;
//	rep(i, n) {
//		if (i == n - 1 || a[i] != a[i + 1]) {
//			if (a[i] <= cnt) {
//				sum += cnt - a[i];
//			}
//			else {
//				sum += cnt;
//			}
//			cnt = 1;
//		}
//		else {
//			cnt++;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//}
//
//
//
