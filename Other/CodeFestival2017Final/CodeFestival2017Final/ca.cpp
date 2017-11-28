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
#include<initializer_list>
#include<map>
#include<set>
#include<utility>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define llong long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()

int dfs(vector<int>fixed, vector<int>free) {
	vector<int>lf(fixed);
	if (free.size() == 0) {
		int m = 1000;
		if (free.size() != 1) {
			sort(all(fixed));
			int n = fixed.size();
			rep(i, n - 1) {
				for (int j = i + 1; j < n; j++) {
					int d = fixed[j] - fixed[i];
					m = min(m, min(d, 24 - d));
				}
			}
		}
		else m = free.front();

		return min(m, 24 - m);
	}
	else {
		vector<int>c1(fixed);
		vector<int>c2(fixed);
		c1.push_back(free.front());
		c2.push_back(24 - free.front());
		free = vector<int>(free.begin() + 1, free.end());
		return max(dfs(c1, free), dfs(c2, free));

	}

}
int main() {
	// wa torenai -> toreta
	int n;
	cin >> n;
	vector<int>d(n);
	rep(i, n)cin >> d[i];
	vector<int>c(13, 0);
	rep(i, n) c[d[i]]++;
	int m = c.size();
	if (c[0] >= 1 || c[12] >= 2 || *max_element(all(c)) >= 3) {
		cout << 0 << endl;
		return 0;
	}

	vector<int> free;
	vector<int> fixed;
	fixed.push_back(0);//this is takahashi
	if (c[12] != 0)fixed.push_back(12);
	for (int i = 1; i < m - 1; i++) {
		if (c[i] == 1) {
			free.push_back(i);
		}
		else if (c[i] == 2) {
			fixed.push_back(i);
			fixed.push_back(24 - i);
		}
	}
	cout << dfs(fixed, free) << endl;
	return 0;
}



