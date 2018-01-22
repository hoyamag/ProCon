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
#define inrange(n, lb, ub) ((lb)<=(n) && (n) <=(ub))
vector < vector<int>> imos2(vector < vector<int>> mat) {
	//imos2
	// mat = {
	//		0,1,0,2
	//		3,4,1,1
	//		0,3,1,9}
	// return = {
	//		0,1,1,3
	//		3,8,9,12
	//		3,11,13,25}
	// return[i][j] means sum of mat[k][l] ( k = 0~i, l = 0~j)

	int n = mat.size();
	int m = mat[0].size();
	for (int i = 0; i < n; i++)for (int j = 0; j < m-1; j++) mat[i][j + 1] += mat[i][j];
	for (int i = 0; i < n; i++)for (int j = 0; j < m-1; j++) mat[j + 1][i] += mat[j][i];
	return mat;

}
int imos2rectangle(const vector<vector<int>>&imos2table, int xl, int yl, int xr, int yr) {
	// a sum of the numbers included in a rectangle area of original table; rectangle area, between xl and xr, yl and yr.
	// imos2table indicates sum of originalTable[k][l] ( k = 0~i, l = 0~j)
		// imos2table = {// should be produced by function "imos2"
		//		0,1,1,3
		//		3,8,9,12
		//		3,11,13,25
		//		3,11,13,25}
		// xl = 1, yl =0, xr = 3, yr = 2
		// return = 12

	int n = imos2table.size();
	int m = imos2table[0].size();
	if (xl > xr || yl > yr) return 0;
	bool fxl = xl - 1 >= 0;
	bool fyl = yl - 1 >= 0;
	int left = fyl ? imos2table[xr][yl - 1] : 0;
	int up = fxl ? imos2table[xl - 1][yr] : 0;
	int corner = fxl&&fyl ? imos2table[xl - 1][yl - 1] : 0;
	int body = imos2table[xr][yr];
	return body - left - up + corner;
}
int main() {
	int n, k;
	cin >> n >> k;
	auto t = mat(int, 2 * k, 2 * k, 0);
	rep(i, n) {
		ll x, y;
		string c;
		cin >> x >> y >> c;
		if (c == "B") t[x % (2 * k)][y % (2 * k)]++;
		else t[(x + k) % (2 * k)][y % (2 * k)]++;
	}
	auto mos = imos2(t);
	int ma = 0;
	rep(i, k)rep(j, k) {
		int xl = i;
		int xr = i + k - 1;
		int yl = j;
		int yr = j + k - 1;
		int center = imos2rectangle(mos, xl, yl, xr, yr);
		int upleft = imos2rectangle(mos, 0, 0, xl - 1, yl - 1);
		int upright = imos2rectangle(mos, 0, yr + 1, xl - 1, 2 * k - 1);
		int lowleft = imos2rectangle(mos, xr + 1, 0, 2 * k - 1, yl - 1);
		int lowright = imos2rectangle(mos, xr + 1, yr + 1, 2 * k - 1, 2 * k - 1);
		int num = center + upleft + upright + lowleft + lowright;
		ma = max({ ma, num, n - num });
	}
	cout << ma;
	return 0;

}



