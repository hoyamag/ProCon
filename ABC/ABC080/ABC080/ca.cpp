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


int main() {
	int n;
	cin >> n;
	vector<vector<int>>f(n, vector<int>(10));
	vector<vector<int>>p(n, vector<int>(11));
	rep(i, n)rep(j, 10)cin>>f[i][j];
	rep(i, n)rep(j, 11)cin >> p[i][j];
	int res = -(1 << 30);
	for (int b = 1; b < (1 << 10); b++) {
		int cc = 0;
		rep(i, n) {
			int c = 0;
			rep(j, 10) {
				if ((b >> j & 1) && f[i][j])c++;
			}
			cc += p[i][c];
		}
		if (res < cc)res = cc;
	}
	cout << res << endl;

	return 0;
}



