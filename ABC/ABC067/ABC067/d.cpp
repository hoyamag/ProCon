
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
	// ABC067d
	int n;
	cin >> n;
	vector<list<int>>g(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int nl, nr;// 塗った点の数(点0からと点n-1から)
	nl = nr = 1;
	vector<bool>splat(n, false);// 色塗り済みかどうかを格納
	splat[0] = splat[n - 1] = true;

	// 点0と点n-1の2点から交互にBFSを進めて、
	// 両方の探索が続けられなくなったら、
	// 塗れた点の数を数えて勝敗を出力する
	queue<int>sl, sr;
	sl.push(0);
	sr.push(n - 1);
	while (!sl.empty() || !sr.empty()) {
		// この1回分のPOPは、距離(pop回数)の点をすべて探索することとは一致しないため、
		// この実装ではACしない。
		if (!sl.empty()) {
			int l = sl.front();
			sl.pop();
			for (auto v : g[l]) {
				if (splat[v] == false) {
					splat[v] = true;
					sl.push(v);
					nl++;
				}
			}
		}
		if (!sr.empty()) {
			int r = sr.front();
			sr.pop();
			for (auto v : g[r]) {
				if (splat[v] == false) {
					splat[v] = true;
					sr.push(v);
					nr++;
				}
			}
		}
	}
	

	if (nl > nr) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;


	return 0;
}


