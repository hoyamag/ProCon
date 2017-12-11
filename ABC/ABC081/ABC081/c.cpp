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
//	ll n, k;
//	cin >> n >> k;
//	vector<ll> a(n);
//	rep(i, n)cin >> a[i];
//	vector<ll> buc(n+1, 0);
//	rep(i, n) buc[a[i]]++;
//	int nonzero = 0;
//	sort(all(buc));
//	rep(i, n) {
//		if (buc[i] != 0) {
//			nonzero = i; break;
//		}
//	}
//	vector<ll> buc2(buc.begin() + nonzero, buc.end());
//	int cnt = 0;
//	if (buc2.size() > k) {
//		int deleting = buc2.size() - k;
//		rep(i, deleting) {
//			cnt += buc2[i];
//		}
//	}
//	cout << cnt << endl;
//
//
//
//	return 0;
//}
//
//
//
