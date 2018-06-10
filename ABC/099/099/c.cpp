#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
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
#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
#define DBG(str) cerr<<(str)<<endl;
int main() {
	int n;
	cin >> n;
	vector<int>a(n + 1, n + 1);
	vector<int>six(n + 1, 6);
	rep(i, 1, n) {
		six[i] = six[i - 1] * 6;
	}
	vector<int>nine(n + 1, 9);
	rep(i, 1, n) {
		nine[i] = nine[i - 1] * 9;
	}
	a[0] = 0;
	a[1] = 1;
	rep(i, 2, n+1) {
		a[i] = a[i - 1] + 1;
		rep(j, 0, n) {
			if (i - six[j] < 0)break;
			a[i] = min(a[i], a[i - six[j]] + 1);
		}
		rep(j, 0, n) {
			if (i - nine[j] < 0)break;
			a[i] = min(a[i], a[i - nine[j]] + 1);
		}
	}
	cout << a[n];

	return 0;
}






