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

void showmat(vector<vector<int>>&a) {
	rep(i, 0, a.size()) {
		rep(j, 0, a[i].size()) {
			cerr << a[i][j] << " ";
		}
		cerr << endl;
	}
	cerr << endl;
}

int main() {
	ll n;
	cin >> n;
	vector<ll>p(n, 0);
	rep(i, 0, n)cin >> p[i];
	vector<ll>q(n, 0);
	rep(i,0,n) q[p[i]-1] = i;
	ll ma = 0;
	ll seq = 1;
	rep(i, 0, n-1) {
		if (q[i + 1] > q[i])seq++;
		else {
			ma = max(ma, seq);
			seq = 1;
		}

	}
	ma = max(ma, seq);
	cout << n - ma;
	//auto d = mat(int, 2, n + 1, INT32_MAX);
	//int length = 0;
	//vector<set<int>>a(2);
	//rep(i, 0, n) {
	//	d[1][i + 1] = min(d[1][i], p[i]);
	//}
	//rep(j, 1, n+1) {

	//	a[j % 2].clear();

	//	rep(i, 1, n+1) {
	//		cerr << "j:" << j << ", i:" << i << endl;
	//		showmat(d);
	//		auto pam = [&]()->int {
	//			if (a[(j - 1) % 2].count(p[i] - 1)) {
	//				d[j % 2][i] = p[i-1];
	//			}
	//			return min(d[j % 2][i], d[j % 2][i - 1]);
	//		};
	//		d[j % 2][i] = pam();
	//		int now = d[j % 2][i];
	//		if (d[j % 2][i] != INT32_MAX) {
	//			length = j;
	//			a[j % 2].insert(d[j % 2][i]);
	//		}

	//	}


	//}
	//cout << n - length;

	return 0;
}



