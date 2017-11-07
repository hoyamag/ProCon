#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include <algorithm>
//#include<initializer_list> // POJ can not use initializer_list
#include<map>
#include<set>
using namespace std;

void dfs(vector<string>&s, int x, int y) {
	s[x][y] = '.';

	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			int nx = x + dx;
			int ny = y + dy;
			if (0 <= nx && nx < s.size() && 0 <= ny&&ny < s[nx].size() && s[nx][ny] == 'W')dfs(s, x + dx, y + dy);
		}
	}

}
int main() {
  /*10 12
  //W........WW.
  //.WWW.....WWW
  //....WW...WW.
  //.........WW.
  //.........W..
  //..W......W..
  //.W.W.....WW.
  //W.W.W.....W.
  //.W.W......W.
  //..W.......W.
   */
	int n, m;
	cin >> n >> m;
	vector<string>s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'W') {
				dfs(s, i, j);// 1 dfs delete 1 lake
				count++;
			}
		}
	}
	cout << count;
	return 0;
}



