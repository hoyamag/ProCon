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
#define ul long long

#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

ul frac(int n) {
	ul res = 1;
	const ul m = (ul)1e9+7;
	for (int i = 1; i <= n; i++) {
		res = (res*i)%m;
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;
	if (abs(n - m) > 1) {
		cout << 0;
	}
	else {
		ul monkey, dog;
		dog = frac(n);
		monkey = frac(m);
		if (n == m) {
			cout << (2*dog * monkey) % ((ul)1e9 + 7);
		}
		else {
			cout << (dog * monkey) % ((ul)1e9 + 7);
		}
	}
	return 0;
}

