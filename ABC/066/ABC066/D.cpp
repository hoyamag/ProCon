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

ul comb(ul n, ul m) {
	//nCm
	ul up = 1;
	ul bottom = 1;
	for (ul i = n; i > n - m; i--)up *= i;
	for (ul i = 1; i <= m; i++) bottom *= i;
	return up / bottom;
}

int main() {
	int n;
	cin >> n;
	vector<int>a = vector<int>(n + 1);
	rup(i, 0, n + 1)cin >> a[i];

	rup(i, 0, n+2) {
		cout << comb(n+1, i) << endl;
	}

	return 0;
}




