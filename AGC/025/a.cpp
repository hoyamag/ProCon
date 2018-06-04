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
int ketawa(int n) {
	int cnt = 0;
	while (n > 0) {
		cnt += n % 10;
		n /= 10;

	}
	return cnt;
}
int main() {
	int n;
	cin >> n;
	int mi = INT32_MAX;
	repc(i, 1, n/2+1) {
		int a = n - i;
		int b = i;
		mi = min(mi, ketawa(a) + ketawa(b));

	}
	cout << mi;
	return 0;
}



