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
#include<utility>
#include<tuple>
#include<cstdlib>
#include<cmath>
using namespace std;
#define ull unsigned long long
#define ll long long

int main() {
	ll n, z, w;
	cin >> n >> z >> w;
	vector<ll>a(n, 0);
	for (int i = 0; i < n; i++)cin >> a[i];
	if(n>1)	cout << max(abs(a[n - 1] - a[n - 2]), abs(a[n - 1] - w))<<endl;
	else cout << abs(a[n - 1] - w) << endl;

	return 0;
}



