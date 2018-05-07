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
	sort(all(a), greater<int>());
	
	int al, bo;
	al = bo = 0;
	rep(i, n) {
		if (i % 2 == 0) {
			al += a[i];
		}
		else {
			bo += a[i];
		}
	}
	cout << al - bo;

	return 0;
}



