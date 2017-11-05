#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<list>
#include<queue>
#include <algorithm>
using namespace std;


int main() {
	long n, m;
	cin >> n >> m;

	vector<int>p(n);
	vector<int>l(n);
	vector<int>r(n);
	vector<int>x(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> x[i];
	}

	for (int i = 0; i < m; i++) {
		if (l[i] <= x[i] && x[i] <= r[i]) {
			vector<int> copy = p;
			sort(copy.begin() + l[i] - 1, copy.end() - (n - r[i]));
			if (p[x[i] - 1] != copy[x[i] - 1]) {
				cout << "No"<<endl;
			}
			else {
				cout << "Yes"<<endl;
			}
		}
		else {// out of sort
			cout << "Yes" << endl;
		}
	}

	return 0;
}




