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

#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

vector<vector<int>> warshallFloyd(int n, vector<int>a, vector<int>b, vector<int>c) {
	// n : グラフのノードの数
	const int C_LIMIT = (int)INT_MAX/2;//100001;
	int m = c.size();
	vector<vector<int>> d = vector<vector<int>>(n, vector<int>(n, C_LIMIT));
	for (int i = 0; i < n; i++) d[i][i] = 0;
	for (int i = 0; i < m; i++) {
		d[a[i] - 1][b[i] - 1] = d[b[i] - 1][a[i] - 1] = c[i];
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	return d;

}



int main() {
	int N, M, R;
	cin >> N >> M >> R;
	vector<int>r(R, 0);
	vector<int>a(M, 0);
	vector<int>b(M, 0);
	vector<int>c(M, 0);
	rup(i, 0, R) cin >> r[i];
	rup(i, 0, M) cin >> a[i] >> b[i] >> c[i];
	vector<vector<int>> d = warshallFloyd(N, a, b, c);
	sort(r.begin(), r.end());
	long long minv = INT_MAX;

	do {
		long long sum = 0;
		for (int j = 1; j < r.size();j++){
			sum += d[r[j - 1] - 1][r[j] - 1];
		}
		minv = min(minv, sum);
	} while (next_permutation(r.begin(), r.end()));

	
	cout << minv<<endl;

	return 0;
}



