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
using namespace std;
#define ul unsigned long long

int main() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<string> s;
	s = vector<string>(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	
	vector<int>x1, y1, x2, y2;
	x1 = vector<int>(q);
	y1 = vector<int>(q);
	x2 = vector<int>(q);
	y2 = vector<int>(q);
	for (int i = 0; i < q; i++)cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];

	for (int qi = 0; qi < q; qi++) {
		int count = 0;
		for (int i = x1[qi] - 1; i < x2[qi]; i++) {
			for (int j = y1[qi]-1; j < y2[qi]; j++) {
				if (s[i][j] == '0') {
					break;
				}
				else {
					// if 隣に探索済みグリッドがあるか
					//		then
					//		if探索済みグリッドに青があるか
					//			then 探索済みグリッドに追加
					//		else 連結成分発見
					// else if そのグリッドは青か then 連結成分発見
				}
			}
		}

	}

	return 0;
}


bool round() {


}