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
	int n, m;
	cin >> n >> m;
	vector<ll>a(n), b(m);
	rep(i, n)cin >> a[i];
	rep(i, m)cin >> b[i];
	sort(all(a));
	sort(all(b));
	cout << a[n - 2] * b[m - 1] << endl;

	return 0;
}



