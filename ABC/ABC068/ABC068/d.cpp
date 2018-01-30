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

	ull k;
	cin >> k;
	int n = 50;
	vector<ull>a(n);
	rep(i, n)a[i] = i;
	
	ull bias = k / n;
	rep(i, n)a[i] += bias;
	rep(i, k%n) {
		ull mi = n+bias, mii;
		rep(i, n) {
			if (a[i] < mi) {
				mi = a[i];
				mii = i;
			}
		}
		rep(i, n) {
			if (i != mii) {
				a[i]--;
			}
			else {
				a[i] += n;
			}
		}
	}
	cout << n << endl;
	rep(i, n)cout << a[i] << " ";
	return 0;

}

