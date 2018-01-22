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
	int n, m;
	cin >> n >> m;
	int lim = 200001;
	vector<bool>one(lim, 0), enu(lim, 0);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		if (a > b)swap(a, b);
		if (a == 1) one[b] = 1;
		else if (b == n)enu[a] = 1;
	}
	rep(i, lim) {
		if (one[i] && enu[i]) {
			cout << "POSSIBLE";
			return 0;
		}
	}
	cout << "IMPOSSIBLE";



	return 0;
}



