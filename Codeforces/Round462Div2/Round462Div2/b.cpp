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
	int k;
	cin >> k;
	if (k > 36) {
		cout << -1 << endl;
		return 0;
	}
	while (k > 0) {
		if (k >= 2) {
			cout << 8;
			k = k - 2;
		}
		else {
			cout << 4;
			--k;
		}
	}

	cout << endl;
	return 0;
}



