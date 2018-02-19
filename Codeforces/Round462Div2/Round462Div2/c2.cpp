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
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	vector<int>one(n, 0), two(n, 0);
	one[0] = a[0] == 1;
	two[0] = a[0] == 2;
	rep(i, n - 1) {
		one[i + 1] = one[i] + (a[i + 1] == 1);
		two[i + 1] = two[i] + (a[i + 1] == 2);
	}
	int sum = 0;
	rep(i, n) {
		int lh = one[i];
		int rh = two[n - 1] - two[i];
		int rad = min(i + 1, n - i - 1);
		for (int j = 1; j <= rad; j++) {
			int lh2 = two[i] - two[i - j + 1];
			int rh1 = one[i + rad] - one[i];
			int lh1 = one[i] - one[i - j + 1];
			int rh2 = two[i + rad] - two[i];
			int tsum = lh + rh + lh2 + rh1 - lh1 - rh2;
			sum = max(sum, tsum);
		}






	}
	cout << sum << endl;

	return 0;
}



