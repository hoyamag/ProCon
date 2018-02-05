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
int que(int i) {
	// arg: 0-indexed
	static char q[10];
	static char sv = 'V', sm = 'M', sf = 'F';
	printf("%d\n", i);
	fflush(stdout);
	scanf("%s", q);
	if (q[0] == sv) {
		cout << i << endl;
		exit(0);
	}
	else if (q[0] == sm) return 0;
	else if (q[0] == sf) return 1;
}

int main() {
	int n;
	cin >> n;
	vector<int>a(n, 0);
	int base = que(0);
	int midv;
	int lb = 0, ub = n;
	while (ub - lb >= 1) {
		int mid = (lb + ub) / 2;
		midv = que(mid);
		int expect = (mid % 2 == 0 ? base : !base);
		if (expect ==midv) {
			lb = mid;
		}
		else {
			ub = mid;
		}
	


	}

	return 0;
}



