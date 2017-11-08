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
#include<initializer_list>
#include<map>
#include<set>
#include<utility>
#include<tuple>
using namespace std;
int meiro(vector<string>so, int n, int m) {
	queue<tuple<int, int, int>> q;
	vector<string> s(n + 2, string(m + 2, '#'));
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		s[i+1][j+1] = so[i][j];
		if (s[i+1][j+1] == 'S')q.push(make_tuple(i+1, j+1, 0));
	}
	int count = -1;
	while (!q.empty()) {
		auto c = q.front();
		q.pop();
			
		int x = get<0>(c);
		int y = get<1>(c);
		count = get<2>(c);
		if (s[x][y] == 'G') break; // BFS, so first hit is the best answer
		
		s[x][y] = 'D';
		vector<int> d = { 1,0,-1,0,1 };
		for (int i = 0; i < d.size() - 1; i++) {
			int nx = x + d[i];
			int ny = y + d[i + 1];
			char ch = s[nx][ny];
			if (ch == '.' || ch =='G')q.push(make_tuple(nx, ny, count + 1));

		}
	}
	return count;
}
int main() {
	cout<<meiro({
		"#S######.#",
		".G....#..#",
		".#.##.##.#",
		".#........",
		"##.##.####",
		"....#....#",
		".#######.#",
		"....#.....",
		".####.###.",
		"....#...G#"
	}, 10, 10) << endl;

	cout<<meiro({
		"#S######.#",
		".....G#..#",
		".#.##.##.#",
		".#........",
		"##.##.####",
		"....#....#",
		".#######.#",
		"....#.....",
		".####.###.",
		"....#...G#"
	}, 10, 10) << endl;
	
	cout<<meiro({
		"#S######.#",
		"......#..#",
		".#.##.##.#",
		".#........",
		"##.##.####",
		"....#....#",
		".#######.#",
		"....#.....",
		".####.###.",
		"....#...G#"
	}
	, 10, 10) << endl;
	
return 0;
}



