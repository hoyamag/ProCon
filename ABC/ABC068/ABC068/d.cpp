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

	ull k;
	cin >> k;
	int n = 2;
	vector<ull>a(n);
	ull i = k / 2;
	if (k % 2 == 0) {
		a[0] = i + 1;
		a[1] = i;
	}
	else {
		a[0] = i;
		a[1] = i + 2;
	}
	cout << n << endl;
	rep(i, n)cout << a[i] << " ";
	return 0;

}

