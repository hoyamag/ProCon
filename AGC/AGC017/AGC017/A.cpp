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

#define rup(i, a, b) for(int (i) = (a); (i) < (b); (i)++)
#define rdn(i, a, b) for(int (i) = (a); (i) > (b); (i)--)

ul frac(ul n) {
	static vector<ul> ans = vector<ul>(5000, 0);
	ans[0] = 1;
	if (ans.size() > n && ans[n] != (ul)0) return ans[n];
	else {
		
		ans[n] = n * frac(n - 1);
		return ans[n];
	}
	
}

ul comb(ul a, ul b)
{//aCb
	ul up = 1;
	ul low = 1;
	/*for (ul i = a; i > a - b; i--) {
		up *= i;
	}
	for (ul i = b; i > 0; i--) {
		low *= i;
	}
	return up / low;*/
	return frac(a) / (frac(b) * frac(a - b));
}

int main() {
	int n;
	bool p;
	cout<<frac(2)<<endl;
	cout << comb(45, 24);
	ul a1 = frac(45);
	ul b = frac(24);
	ul c = frac(21);
	cin >> n >> p;

	vector<int> a = vector<int>(n, 0);
	rup(i, 0, n) cin >> a[i];

	rup(i, 0, n) a[i] = a[i] % 2;
	int numof1 = 0;
	rup(i, 0, n) {
		if (a[i] == 1)numof1++;
	}
	
	ul sum = 0;
	for (int i = 0; i <= n - numof1; i++) {
		sum += comb(n - numof1, i);
	}

	ul sum1 = 0;
	if (p == 0) {
		for (ul i = 0; 2 * i <= numof1; i++) {
			sum1 += comb(numof1, 2 * i);
		}
	}
	else {
		for (ul i = 1; 2 * i - 1 <= numof1; i++) {
			sum1 += comb(numof1, 2 * i - 1);
		}

	}
	cout << sum1*sum;

	return 0;
}




