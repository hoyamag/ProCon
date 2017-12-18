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
#define vec vector

ll knapsack0N(vector<int>w, vector<int>v, int W) {
	//ant book p52 0-inf knapsack problem
	// w : weight vector
	// v : value vector
	// W : knapsack's weight limit(including)
	// return : max value knapsack can contain.
	int n = v.size();
	vec<vec<int>>dp(n+1, vec<int>(W + 1, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= W; j++) {
			dp[i + 1][j] = max(dp[i][j], j >= w[i] ? dp[i+1][j - w[i]] + v[i] : 0);
		}
	}
	return dp[n][W];
}
int main() {
	cout << knapsack0N({ 3, 4,2 }, { 4,5,3 }, 7) << endl;

	return 0;
}



