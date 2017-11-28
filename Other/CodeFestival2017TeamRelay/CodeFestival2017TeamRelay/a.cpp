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
using namespace std;
#define ull unsigned long long
#define llong long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
 
 
int main() {
	llong k, a, b;
	cin >> k >> a >> b;
	if (k <= a) {
		cout << 1 << endl;
		return 0;
	}
	if (a - b <= 0) {
		cout << -1 << endl;
		return 0;
	}
	else {
		llong add = (k - a) % (a - b) != 0;
		llong t = (k - a) / (a - b) + add;
 
		cout << 1 + 2 * t << endl;
	}
 
	return 0;
}
