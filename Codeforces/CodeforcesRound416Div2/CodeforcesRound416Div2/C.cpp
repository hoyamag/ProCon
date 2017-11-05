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

int main() {
	long long a, b, f, k;
	cin >> a >> b >> f >> k;
	if (b < 2*f || b < 2*(a - f)) {
		cout << -1;
		return 0;
	}
	double ave = (double)a / b;
	double pro = ave*k;
	long long minstop = ceil(pro);
	cout << minstop;

	return 0;
}



