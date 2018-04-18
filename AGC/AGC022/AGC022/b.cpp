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
vector<vector<list<ll>>>ta;
vector<vector<ll>>g;

void init() {
	int n = ta.size();
	rep(i, 0, n) {
		rep(j, 0, n) {
			ta[i][i%j].push_back(j);
		}
	}
}
ll min(list<ll> a) {
	int mi = LLONG_MAX;
	for (auto v : a)mi = (mi, v);
}
int main() {
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, n)cin >> b[i];
	ta = vector<vector<list<ll>>>(51, vector<list<ll>>(51, list<ll>()));
	init();
	g = mat(ll, 51, 51, LLONG_MAX);
	int m = 51;
	rep(k, 0, m)rep(i, 0, m)rep(j, 0, m) {
		ta[i][j] = min(min(t[i][j]), t[i][k] + t[k][j]);
	}


	return 0;
}



