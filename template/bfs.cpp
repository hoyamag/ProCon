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
#include<stack>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
vector<vector<char>>s;
int main() {
  // 入力にH＊Wの迷路が与えられて、それの最短路を求める例。
  // O(HW)
  // なお迷路は#が壁で、.が通路
  // 遷移可能なのは上下左右。
	int h, w;
	cin >> h >> w;
	int h1 = h + 2;
	int  w1 = w + 2;
	s = mat(char, h1, w1, '#');
	for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> s[i][j];
	auto looked = mat(bool, h1, w1, false);
	vector < pair<int, int>>move = { {0,1}, {1,0}, {0,-1},{-1,0} };

	queue<tuple<int, int, int>> st;
	st.push(tuple<int, int, int>{ 1, 1, 1 });
	looked[1][1] = true;
	int minPath = -1;
	while (!st.empty()) {
		auto cell = st.front();
		st.pop();
		int i = get<0>(cell);
		int j = get<1>(cell);
		int dist = get<2>(cell);

		if (i == h && j == w) {
			minPath = dist;
			break;
		}
		else {
			for (auto m : move) {
				int ni = i + m.first;
				int nj = j + m.second;
				if (looked[ni][nj] == false && s[ni][nj] == '.') {
					st.push(tuple<int, int, int> { ni, nj, dist + 1 });
					looked[ni][nj] = true;
				}

			}
		}

	}

	if (minPath != -1) cout << minPath;
	else cout << -1;
	return 0;
}



