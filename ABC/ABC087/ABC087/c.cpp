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
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));

int main() {
	int n;
	cin >> n;
	auto a = mat(int, 2, n, 0);
	int m = 2;
	rep(i, m)rep(j, n) cin >> a[i][j];

	vector<int>cs1(n + 1, 0), cs2(n, 0);
	cs1[n] = 0;
	cs1[n - 1] = a[0][n - 1] + a[1][n - 1];
	cs2[n - 1] = a[1][n - 1];
	for (int i = n - 1; i >= 1; i--) {
		cs1[i - 1] += cs1[i] + a[0][i - 1];
		cs2[i - 1] += cs2[i] + a[1][i - 1];
	}
	ll ma = 0;
	ll sum = 0;
	rep(i, n) {
		sum += a[0][i];
		ma = max({ ma, sum + cs2[i], sum + cs1[i + 1] });
	}
	cout << ma << endl;
	return 0;
}



