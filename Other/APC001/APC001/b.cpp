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
	vector<ll>a(n), b(n), d(n,0);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, n) {
		cin >> b[i];
		d[i] = b[i] - a[i];
	}
	ll sum = 0;
	ll misum = 0;
	rep(i, n) {
		if (d[i] > 0) {
			sum += d[i] / 2;
		}
		else if (d[i] < 0) {
			misum += d[i];
		}
	}
	if (abs(misum )<= sum) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
		

	return 0;
}



