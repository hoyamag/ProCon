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
int nthbit(int n, int a) {
	int b = 1 >> n;
	return a&b;

}
int main() {
	int n;
	cin >> n;
	int len = 20;
	vector<int>a(n, 0);
	rep(i, 0, n)cin >> a[i];
	auto bits = mat(bool, len, n, 0);
	rep(i, 0, len)rep(j, 0, n) {
		bits[i][j] = nthbit(i, a[j]);
	}
	auto cs = mat(int, len, n + 2, 0);
	rep(i, 0, len) {
		cs[i][0] = 1;
		int cnt = 0;

		if (bits[i][0] == 1)cnt++;
		rep(j, 1, n) {
			if (bits[i][j] == 1)cnt++;
			if(cnt%2)cs[i][j] = 1;
			else cs[i][j] = -1;
		}

	}
	return 0;
}



