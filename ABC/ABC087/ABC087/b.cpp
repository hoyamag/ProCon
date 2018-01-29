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
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	int cnt = 0;
	rep(i, a+1) {
		rep(j, b+1) {
			rep(k, c+1) {
				int v = i * 500 + j * 100 + k * 50;
				if (v == x)cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}



