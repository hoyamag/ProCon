
#include<bitset>
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
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define repe(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repi(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
int main() {
	int a, b;
	cin >> a >> b;
	char wh = '.', bl = '#';
	int h, w;
	h = w = 100;
	vector<string>t(h, string(w, wh));
	repe(i, h / 2, h) {
		t[i] = string(w, bl);
	}
	auto f = [&](int st, int en, char ch, int lim) {
		int cnt = 1;
		repe(i, st, en) {
			rep(j, w) {
				if (cnt >= lim)return;
				t[i][j] = ch;
				j++;
				cnt++;
			}
			i++;
		}
	};
	f(1, 50, bl, b);
	f(51, h, wh, a);
	cout << h << " " << w << endl;
	rep(i, h) {

		rep(j, w)cout << t[i][j];
		cout << endl;
	}

	return 0;
}


