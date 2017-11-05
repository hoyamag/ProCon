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
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>x(n, 0);
	vector<int>y(n, 0);
	map<int, int> m = {};
	for (int i = 0; i < n; i++) cin >> x[i];
	
	for (int i = 0; i < n; i++) cin >> y[i];
	for (int i = 0; i < n; i++) {
		m[x[i]] = 0;
		m[y[i]] = 0;

	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int b = x[i] ^ y[j];
			if (m.find(b) !=m.end()) {
				m[b]++;
			}
		}
	}
	int count = 0;
	for (auto i = m.begin(); i != m.end(); ++i) {
		count += i->second;
	}
	if (count % 2 == 0)cout << "Karen";
	else cout << "Koyomi";
	return 0;
}



