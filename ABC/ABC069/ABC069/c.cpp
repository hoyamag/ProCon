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

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	vector<int> b(4, 0);
	rep(i, n) {
		b[a[i] % 4]++;
	}
	if (b[2] %2==0) b[2] = 0;
	else b[2]=1;
	if (b[0] >= b[1] + b[2] + b[3] - 1) cout << "Yes";
	else cout << "No";



	return 0;
}



