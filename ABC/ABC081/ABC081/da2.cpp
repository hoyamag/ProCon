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
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
bool cond(vector<ll> a) {
	int n = a.size();
	rep(i, n - 1)if (a[i] > a[i] + 1) return false;
	return true;
}
void out(int x, int y) {
	cout << x << " " << y << endl;
}
int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)cin >> a[i];
	auto mait = max_element(all(a));
	auto miit = min_element(all(a));
	ll ma = *mait;
	ll mi = *miit;
	int m = 2 * n;
	cout << m << endl;
	if (labs(ma) >= labs(mi)) {
		int imax = distance(a.begin(), mait);
		rep(i, n) {
			if (i != imax)out(imax + 1, i + 1);
		}
		out(imax + 1, imax + 1);
		out(imax + 1, 1);
		rep(i, n - 1)out(i + 1, i + 2);
	}
	else {
		int imin = distance(a.begin(), miit);
		rep(i, n)if (i != imin)out(imin + 1, i + 1);
		out(imin + 1, imin + 1);
		out(imin + 1, n);
		for (int i = n - 1; i >= 1; i--)out(i + 1, i);
	}


	return 0;
}



