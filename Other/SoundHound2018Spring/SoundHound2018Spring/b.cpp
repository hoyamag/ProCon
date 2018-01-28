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
	int n, L, R;
	cin >> n >> L >> R;
	vector<int>a(n);
	rep(i, n) {
		int x;
		cin >> x;
		if (x < L)a[i] = L;
		else if (x > R)a[i] = R;
		else a[i] = x;
	}
	rep(i, n)cout << a[i] << " ";
	return 0;
}



