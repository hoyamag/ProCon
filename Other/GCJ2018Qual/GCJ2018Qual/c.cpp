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
int CNT = 0;
int PREPARED = 0;
void dispMat(vector<vector<bool>> ta) {
	rep(i, 0, ta.size()) {
		rep(j, 0, ta[i].size()) {
			cerr << ta[i][j];
		}
		cerr << endl;
	}
}
void update(vector<vector<bool>>&ta, int dh, int dw, int &nh, int &nw) {
	cerr << "Q:";
	cout << dh << " " << dw << endl;

	CNT++;
	int a, b;
	cin >> a >> b;
	nh = a;
	nw = b;
	if (nh < 1 || nw < 1)return;
	else {
		cerr << "CNT" << CNT << ":" << nh << " " << nw << endl;
		if (ta[nh - 1][nw - 1] == false) {
			PREPARED++;
			cerr << "PREPARED" << PREPARED << endl;
		}

		ta[nh - 1][nw - 1] = true;
		//dispMat(ta);
	}
}

void solve() {
	int h, w;
	h = w = 10;
	auto ta = mat(bool, h, w, false);

	int nh, nw;
	int limit = 1000;
	int x, y;
	x = y = 2;
	rep(operationCount, 0, limit) {
		nh = nw = -10;
		update(ta, x, y, nh, nw);
		if (PREPARED % 9 == 0) {
			if (y < w - 3)y += 3;
			else {
				x += 3;
				y = 2;
			}
		}
		if (nh == 0 && nw == 0)break;

	}

}
int main() {
	int t;
	cin >> t;
	rep(i, 0, t)solve();


	return 0;
}



