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
	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];

	auto ans = mat(int, h, w, 0);
	int ai = 0;
	rep(i, h) {
		rep(j, w) {
			ans[i][j] = ai + 1;
			a[ai]--;
			if (a[ai] <= 0)ai++;
		}
		i++;
		if (i < h) {
			for (int j = w - 1; j >= 0; j--) {
				ans[i][j] = ai + 1;
				a[ai]--;
				if (a[ai] <= 0)ai++;
			}
		}

	}
	rep(i, h) {
		rep(j, w)cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}



