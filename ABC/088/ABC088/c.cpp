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
#define rep1n(i, n) for(int i=1;i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
int main() {
	int n = 3;
	auto c = mat(int, n, n, 0);
	rep(i, n)rep(j, n)cin >> c[i][j];
	vector<int>a(n, 0), b(n, 0);
	rep(i, n)b[i] = c[0][i];
	rep1n(i, n - 1)a[i] = c[i][0] - b[0];
	bool al = true;
	rep(i, n)rep(j, n) {
		if (c[i][j] != a[i] + b[j]) {
			al = false;
			break;
		}
	}
	Yes(al);

	return 0;
}



