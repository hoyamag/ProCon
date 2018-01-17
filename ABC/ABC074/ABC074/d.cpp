
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
	// ABC074D
	int n;
	cin >> n;
	vector<vector<ll>>a(n, vector<ll>(n, 0));
	rep(i, n)rep(j, n)cin >> a[i][j];
	vector<vector<ll>>b(a);
	rep(k, n)rep(i, n)rep(j, n) b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
	rep(i, n) {
		rep(j, n) {
			if (b[i][j] < a[i][j]) {
				cout << -1 << endl; return 0;
			}
		}
	}
	vector<vector<bool>> del(n, vector<bool>(n, false));
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				if (b[i][k] > 0 && b[k][j] > 0 && b[i][j] == b[i][k] + b[k][j]) {
					del[i][j] = del[j][i] = true;
				}
			}
		}
	}
	ll sum = 0;
	rep(i, n)rep(j, n)if (!del[i][j])sum += b[i][j];

	cout << sum / 2 << endl;

	return 0;
}



