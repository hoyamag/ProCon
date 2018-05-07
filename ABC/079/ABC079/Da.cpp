#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include <algorithm>
#include<initializer_list>
#include<map>
#include<set>
#include<utility>
#include<tuple>
using namespace std;
#define ull unsigned long long
#define llong long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()

vector<vector<int>> WarshallFloyd(int n, vector<vector<int>>initializedMatrix) {
	auto w = initializedMatrix;
	rep(k, n) {
		rep(i, n) {
			rep(j, n) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	return w;
}
int main() {
	int h, w;
	cin >> h >> w;
	int n = 10;
	vector<vector<int>>c(n, vector<int>(n, 0));
	vector<vector<int>>a(h, vector<int>(w, 0));
	rep(i, n) rep(j, n) cin >> c[i][j];
	rep(i, h)rep(j, w) cin >> a[i][j];
	auto dist = WarshallFloyd(n, c);
	llong sum = 0;
	rep(i, h)rep(j, w) {
		if(a[i][j]!=-1) sum += dist[a[i][j]][1];
	}
	cout << sum << endl;
	return 0;
}



