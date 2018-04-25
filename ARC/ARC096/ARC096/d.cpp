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
ll n;
ll c;
vector<pair<ll, ll>>xv;

vector<ll> lef, rig;
ll leftgain(int num) {
	if (num == 0)return 0;
	return lef[num] - xv[num - 1].first;
}
ll riggain(int num) {
	if (num == 0)return 0;
	ll dis = c - xv[n - num].first;
	return rig[num] - dis;
}
int main() {
	cin >> n >> c;
	xv = vector<pair<ll, ll>>(n);
	rep(i, 0, n)cin >> xv[i].first >> xv[i].second;
	sort(all(xv));

	lef = vector<ll>(n + 1, 0);
	rig = vector<ll>(n + 1, 0);
	rep(i, 1, n + 1) {
		lef[i] += lef[i - 1] + xv[i - 1].second;
		rig[i] += rig[i - 1] + xv[n - i].second;
	}

	ll ans = 0;
	vector<ll> maxleft(n + 1, 0);
	vector<ll> maxright(n + 1, 0);
	repc(i, 1, n)maxleft[i] = max(maxleft[i - 1], leftgain(i));
	repc(i, 1, n)maxright[i] = max(maxright[i - 1], riggain(i) - (c - xv[n - i].first));
	repc(i, 0, n)ans = max(ans, maxleft[i] + maxright[n - i]);

	ll ans2 = 0;
	vector<ll> maxleft2(n + 1, 0);
	vector<ll> maxright2(n + 1, 0);
	repc(i, 1, n)maxleft2[i] = max(maxleft2[i - 1], leftgain(i) - xv[i - 1].first);
	repc(i, 1, n)maxright2[i] = max(maxright2[i - 1], riggain(i));
	repc(i, 0, n)ans2 = max(ans2, maxleft2[i] + maxright2[n - i]);
	cout << max(ans, ans2);


	return 0;
}



