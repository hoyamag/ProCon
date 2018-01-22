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

int main() {
	ll n, k;
	cin >> n >> k;
	int size = 2*k-1;
	auto t = vector < vector<pair<int, int>>>(size, vector<pair<int, int>>(size, make_pair<int, int>(0,0)));
	rep(i,n){
		int x, y;
		string c;
		cin >> x >> y >> c;
		if (c == "B") t[x%k][y%k].first++;
		else t[x%k][y%k].second++;
	}
	rep(i, size)rep(j, size)t[i][j] = t[i%k][j%k];
	auto cs = vector < vector<pair<int, int>>>(size, vector<pair<int, int>>(size, make_pair<int, int>(0,0)));
	cs[0][0] = t[0][0];
	rep(i, size) {
		rep(j, size) {
			cs[i][j].first = cs[i - 1][j].first + cs[i][j - 1].first - cs[i - 1][j - 1].first;
			cs[i][j].second = cs[i - 1][j].second + cs[i][j - 1].second - cs[i - 1][j - 1].second;
		}
	}


	return 0;
}



