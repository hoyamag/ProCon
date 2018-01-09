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

bool isPrime(int n) {
	static int lim = 1e5;
	static bool done = false;
	static vector<bool> isp(lim + 1, 1);
	if (!done) {
		isp[0] = isp[1] = false;
		for (int i = 2; i <= lim; i++) {
			if (isp[i]) {
				for (int j = i + i; j <= lim; j += i) {
					isp[j] = false;
				}
			}
		}
		done = true;
	}
	return isp[n];
}

int main() {
	int lim = 1e5;
	vector<int>cumlativeSum(lim + 1, 0);
	for (int i = 1; i <= lim; i++) {
		int isLike = i % 2 == 1 && isPrime(i) && isPrime((i + 1) / 2) ? 1 : 0;
		cumlativeSum[i] = cumlativeSum[i - 1] + isLike;
	}
	int q;
	cin >> q;
	vector<int>l(q), r(q);
	rep(i, q)cin >> l[i] >> r[i];
	rep(i, q)cout << cumlativeSum[r[i]] - cumlativeSum[l[i]-1] << endl;


	return 0;
}



