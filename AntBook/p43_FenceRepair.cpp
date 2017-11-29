#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
//#include<initializer_list>
#include<map>
#include<set>
#include<utility>
//#include<tuple>
//#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()

ll FenceRepair(vector<ll> L) {
	int n = L.size();
	ll ans = 0;
	while (n > 1) {
		int mi1 = 0, mi2 = 1;
		if (L[mi1] > L[mi2])swap(mi1, mi2);
		for (int i = 2; i < n; i++) {
			if (L[i] < L[mi1]) {
				mi2 = mi1;
				mi1 = i;
			}
			else if (L[i] < L[mi2]) mi2 = i;
		}

		ll t = L[mi1] + L[mi2];
		ans += t;
		if (mi1 == n - 1) swap(mi1, mi2);// t should be kept, so if mi1 will be gone, store t on m2.
		L[mi1] = t;
		L[mi2] = L[--n]; // n, number of boards, decreased

	}
	return ans;
}
int main() {

	//vector<int> a = { 8,5,8 };
	//cout << FenceRepair(a) << endl;
	int n;
	cin >> n;
	vector<ll>a(n);
	rep(i, n)cin >> a[i];
	cout << FenceRepair(a) << endl;
	return 0;

}



