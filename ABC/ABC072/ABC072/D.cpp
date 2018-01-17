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
	vector<int>p(n, 0);
	rep(i, n)cin >> p[i];
	int ans = 0;
	int con = 0;
	rep(i, n) {
		if (p[i] == i + 1) {
			con++;
		}
		else {
			ans += (int)ceil((double)con / 2);
			con = 0;
		}
	}
	ans += (int)ceil((double)con / 2);
	cout << ans;
	return 0;
}



