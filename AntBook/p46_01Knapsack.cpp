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

#define MAX_N 100
#define MAX_W 10000
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];
int rec(int i, int j) {
	// i”Ô–ÚˆÈ~‚Ì•i•¨‚©‚çd‚³‚Ì‘˜a‚ªjˆÈ‰º‚É‚È‚é‚æ‚¤‚É‘I‚Ô
	if (dp[i][j] >= 0) return dp[i][j];
	int res;
	if (i == n) {
		res = 0;
	}
	else if (j < w[i]) {
		res = rec(i + 1, j);
	}
	else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}
int main() {
	n = 4;
	W = 5;
	w[0] = 2;
	w[1] = 1;
	w[2] = 3;
	w[3] = 2;
	v[0] = 3;
	v[1] = 2;
	v[2] = 4;
	v[3] = 2;
	memset(dp, -1, sizeof(dp));
	cout << rec(0, W) << endl;
	return 0;
}



