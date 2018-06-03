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
	int h, w;
	cin >> h >> w;
	int h1 = h + 2;
	int  w1 = w + 2;
	s = mat(char, h1, w1, '#');
	int whitenum = 0;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> s[i][j];
			if (s[i][j] == '.')whitenum++;
		}
	}
	auto looked = mat(bool, h1, w1, false);
	vector < pair<int, int>>move = { {0,1}, {1,0}, {0,-1},{-1,0} };

	queue<tuple<int, int, int>> st;
	st.push(tuple<int, int, int>{ 1, 1, 1 });
	looked[1][1] = true;
	int lpn = -1;
	int loopnum = 0;
	while (!st.empty()) {
		loopnum++;
		auto cell = st.front();
		st.pop();
		int i = get<0>(cell);
		int j = get<1>(cell);
		int dist = get<2>(cell);

		if (i == h && j == w) {
			lpn = dist;
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

	if (lpn != -1) cout << whitenum - lpn;
	else cout << -1;
	return 0;
}



