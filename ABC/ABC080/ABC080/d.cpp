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
	int n, C;
	cin >> n >> C;
	vector<int>s(n), t(n), c(n);
	rep(i, n)cin >> s[i] >> t[i] >> c[i];
	int lim = 2 * 1e5 + 2;
	vector<int>sum(lim, 0);
	for (int i = 1; i <= C; i++) {
		vector<int> d(lim, 0);
		rep(j, n) {
			if (c[j] == i) {
				d[2 * s[j] - 1]++;
				d[2 * t[j]]--;
			}
		}
		vector<int> cumulativeSum(d);
		for (int j = 1; j < lim; j++) {
			cumulativeSum[j] += cumulativeSum[j - 1];
		}
		rep(j, lim)if (cumulativeSum[j] > 0) sum[j]++;
	}
	int mx = *max_element(all(sum));
	std::cout << mx << endl;
	return 0;
}



