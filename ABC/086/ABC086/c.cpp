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
//#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
//
//int main() {
//	int n;
//	cin >> n;
//	vector<int>t(n+1), x(n+1), y(n+1);
//	t[0] = x[0] = y[0] = 0;
//	rep(i, n)cin >> t[i+1] >> x[i+1] >> y[i+1];
//	bool all = true;
//	rep(i, n) {
//		long l = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);
//		int td = t[i + 1] - t[i];
//		if (td < l) {
//			all = false;
//			break;
//		}
//		if ((td - l) % 2 != 0) {
//			all = false;
//			break;
//		}
//
//	}
//	if (all) cout << "Yes";
//	else cout << "No";
//
//	return 0;
//}
//
//
//
