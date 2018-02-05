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
	ull x, y;
	cin >> x >> y;

	ull xx = 2 * x;
	if (x%y == 0) {
		cout << -1;
		return 0;
	}
	while (xx<=1e18) {
		if (xx%y != 0) {
			cout << xx;
			return 0;
		}
		xx += x;
	}
	cout << -1;
	return 0;
}



