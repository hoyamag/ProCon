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
	int n = 3;
	auto c = mat(int, n, n, 0);
	rep(i, n)rep(j, n)cin >> c[i][j];
	vector<int>si(n, 0);
	vector<int>sj(n, 0);
	rep(i, n) {
		rep(j, n) {
			si[i] += c[i][j];
		}
	}
	rep(j, n)rep(i, n)sj[j] += c[i][j];
	bool condi = false;
	int lim = 100;
	int sl2 = si[0] - si[1];
	int sl3 = si[1] - si[2];
	[&] {
		rep(a1, lim + 1)rep(a2, lim + 1) {

			if (sl3 % 3 == 0) {

				int a3 = a2 - (int)(sl3 / 3);
				if (sl2 == 3 * (a1 - a2) && a3 >= 0) {
					condi = true;
					return;
				}
			}


		}
	}();
	bool condj = false;
	int sc2 = sj[0] - sj[1];
	int sc3 = sj[1] - sj[2];
	[&] {
		rep(b1, lim + 1)rep(b2, lim + 1) {

			if (sc3 % 3 == 0) {

				int b3 = b2 - (int)(sc3 / 3);
				if (sc2 == 3 * (b1 - b2) && b3 >= 0) {
					condj = true;
					return;
				}
			}


		}
	}();
	if (condi&&condj) cout << "Yes";
	else cout << "No";











	return 0;
}



