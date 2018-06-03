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
#include<map>
#include<set>
using namespace std;

int main() {
	long long n;
	cin >> n;
	vector<unsigned long long>a(n, 0);
	vector<unsigned long long>b(n, 0);
	vector<unsigned long long>c(n, 0);
	for (long long i = 0; i < n; i++) cin >> a[i];
	for (long long i = 0; i < n; i++) cin >> b[i];
	for (long long i = 0; i < n; i++) cin >> c[i];

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	unsigned long long sum = 0;
	for (long long j = 0; j < n; j++) {
		auto albite = lower_bound(a.begin(), a.end(), b[j]);//b[j]以上の値の最初の要素のイテレータ得られる
		auto cubite = upper_bound(c.begin(), c.end(), b[j]);
		long long i = distance(a.begin(), albite);
		long long k = distance(cubite, c.end());
		sum += i*k;
	}
	cout << sum;
	return 0;
}



