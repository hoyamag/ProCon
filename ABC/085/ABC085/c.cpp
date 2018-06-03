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
//	int n, y;
//	cin >> n >> y;
//	vector<int>k1(3, 0), k2(2, 0);
//	int k3;
//	k1[0] = y/10000;
//	k1[1] = 2 * k1[0];
//	k1[2] = 10 * k1[0];
//	y %= 10000;
//	
//	k2[0] = y/5000;
//	k2[1] = 5 * k2[0];
//	y %= 5000;
//	k3 = y/1000;
//	rep(i, k1.size()) {
//		rep(j, k2.size()) {
//			int num = k1[i] + k2[j] + k3;
//			if (num == n) {
//				int man, go, sen;
//				man = go = sen = 0;
//				if (i == 0)man = k1[i];
//				else if (i == 1) go = k1[i];
//				else sen = k1[i];
//				if (j == 0) go += k2[j];
//				else sen += k2[j];
//				sen += k3;
//				cout << man << " " << go << " " << sen << endl;
//				return 0;
//			}
//		}
//	}
//	cout << -1 << " " << -1 << " " << -1 << endl;
//	return 0;
//}
//
//
//
