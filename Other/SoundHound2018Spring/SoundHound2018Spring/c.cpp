//#include<math.h>
//#include<limits.h>
//#include<iostream>
//#include<string>
//#include<vector>
//#include<stdio.h>
//#include<sstream>
//#include<list>
//#include<queue>
//#include<algorithm>
//#include<functional>
//#include<map>
//#include<set>
//#include<utility>
//#include<initializer_list>
//#include<tuple>
//#include<regex>
//using namespace std;
//#define ull unsigned long long
//#define ll long long
//#define rep(i, n) for(int i=0;i<(int)(n);i++)
//#define all(t) t.begin(), t.end()
//#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
//int dfs(vector<vector<char>>&t, int x, int y) {
//	if (x < 0 || x >= t.size() || y < 0 || y >= t[0].size()) return 0;
//	vector<vector<char>> ori(t);
//	char p = t[x][y];
//	if (p == '.') {
//		int d1 = dfs(t, x + 1, y);
//		int d2 = dfs(t, x, y + 1);
//		int ans1 = d1 + d2;
//		auto r1 = t;
//		t = ori;
//		t[x][y] = '#';
//		if (x + 1 < t.size())t[x + 1][y] = '*';
//		if (x - 1 >= 0) t[x - 1][y] = '*';
//		if (y + 1 < t[0].size())t[x][y + 1] = '*';
//		if (y - 1 >= 0)t[x][y - 1] = '*';
//		int ans2 = max(ans1, dfs(t, x + 1, y) + dfs(t, x, y + 1) + 1);
//		if (ans1 > ans2) {
//			t = r1;
//			return ans1;
//		}
//		else {
//			return ans2;
//		}
//	}
//	else {
//		int d1 = dfs(t, x + 1, y);
//		int d2 = dfs(t, x, y + 1);
//		int ans1 = max(d1, d2);
//		return ans1;
//
//	}
//}
//
//int main() {
//	int r, c;
//	cin >> r >> c;
//	auto t = mat(char, r, c, '*');
//	rep(i, r)rep(j, c)cin >> t[i][j];
//	int cnt = 0;
//	dfs(t, 0, 0);
//	rep(i, r)rep(j, c)if (t[i][j] == '#')cnt++;
//	cout << cnt;
//
//	return 0;
//}
//
//
//
