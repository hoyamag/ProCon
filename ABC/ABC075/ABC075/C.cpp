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
using namespace std;
int conSize(int n, int m, vector<vector<int>> g, int begin, vector<int> &color) {
	if (color[begin] == 1) return 0;
	int size = 1;
	color[begin] = 1;
	for (int i = 0; i < g[begin].size(); i++) {
		size += conSize(n, m, g, g[begin][i], color);
	}
	return size;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	int bridge = 0;
	vector<int> color(n, 0);
	vector<int> cc = color;
	int iniSize = conSize(n, m, g, 0, cc);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			vector<vector<int>> g2 = g;
			int deleteEdgeNode1 = i;
			int deleteEdgeNode2 = g2[i][j];
			for (auto it = g2[deleteEdgeNode2].begin(); it != g2[deleteEdgeNode2].end();) {
				if (*it == deleteEdgeNode1) it = g2[deleteEdgeNode2].erase(it);
				else ++it;
				
			}
			g2[i].erase(g2[i].begin() + j);
			vector<int> cc = color;
			int newSize = conSize(n, m, g2, 0, cc);
			if (newSize != iniSize)bridge++;
		}
	}
	cout << bridge/2;
	return 0;
}



