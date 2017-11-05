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
#define lol long long
#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

vector<lol> a;


lol sum(lol begin, lol end) {
	lol sum = 0;
	for (lol i = begin; i < end; i++) {
		sum += a[i];
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	a = vector<lol>(n, 0);
	rup(i, 0, n) cin >> a[i];
	lol s = (lol)ceil(n / 2);
	lol x = sum(0, s);
	lol y = sum(s, n);
	lol eva = abs(x - y);
	
	while (1) {
		if (s == 1 || s == n - 1) {
			break;
		}

		lol nx = x;
		lol ny = y;
		lol ns = s;
		if (x > y) {
			nx -= a[ns - 1];
			ny += a[ns - 1];
			ns--;
		}
		else {
			nx += a[ns];
			ny -= a[ns];
			ns++;
		}
		lol newEva = abs(nx - ny);
		if (newEva < eva) {
			x = nx;
			y = ny;
			s = ns;
			eva = newEva;
		}
		else {
			break;
		}
		
	}

	cout << eva;
	return 0;
}



