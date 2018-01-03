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
bool RecurrenceFormula(vector<int>dx, int obj) {
	int ma = 8000;
	vector<vector<bool>>dpx(dx.size() + 1, vector<bool>(ma + 1, false));
	dpx[0][0] = true;
	for (int i = 1; i < dpx.size(); i++) {
		rep(j, dpx[i].size()) {
			bool left = j - dx[i-1] >= 0 ? dpx[i - 1][j - dx[i-1]] : false;
			bool right = j + dx[i-1] <= ma ? dpx[i - 1][j + dx[i-1]] : false;
			dpx[i][j] = left || right;
		}
	}
	return dpx[(int)dx.size()][obj];

}

int main() {
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	int n = s.length();
	int fcnt = 0;
	bool isx = true;
	vector<int>dx;
	vector<int>dy;
	rep(i, n) {
		if (s[i] == 'F')fcnt++;
		else {
			isx ? dx.push_back(fcnt) : dy.push_back(fcnt);
			fcnt = 0;
			isx = !isx;

		}
	}
	isx ? dx.push_back(fcnt) : dy.push_back(fcnt);


	bool xcan = RecurrenceFormula(vector<int>(dx.begin() + 1, dx.end()), abs(x - dx[0]));
	bool ycan = RecurrenceFormula(dy, abs(y));
	cout << (xcan&&ycan ? "Yes" : "No") << endl;
	return 0;
}



