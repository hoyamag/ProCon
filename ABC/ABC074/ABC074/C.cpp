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
#define ul unsigned long long
#define ll long long
#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

double noudo(int a, int b) {
	return 100 * b / (a + b);
}

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	list<int> x(0);
	list<int> y(0);
	for (int i = 0; i <= f; i++) {
		for (int j = 0; j <= f; j++) {
			int tmp = 100 * a*i + 100 * b*j;
			if (0 < tmp &&tmp <= f) {
				x.push_back(tmp);
			}
		}
	}
	rup(i, 0, f + 1) {
		rup(j, 0, f + 1) {
			int tmp = c*i + d*j;
			if (tmp <= f) {
				y.push_back(tmp);
			}
		}
	}
	int ansWa = 0;
	int ansSu = 0;
	double density = 0;
	for (auto wa : x) {
		for (auto su : y) {
			if (wa + su <= f && (double)su / wa <= (double)e / 100) {
				double tdens = 100 * su / (wa + su);
				if (tdens > density) {
					density = tdens;
					ansWa = wa;
					ansSu = su;
				}
			}
		}
	}
	cout << ansWa << " " << ansSu;
	return 0;
}



