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

void swap(vector<long> &v, long in1, long in2) {
	long t = v[in1];
	v[in1] = v[in2];
	v[in2] = t;
}

int main() {
	long n;
	cin >> n;
	vector<long>p = vector<long>(n, 0);
	rup(i, 0, n) cin >> p[i];
	vector<long>seq = vector<long>(n, 0);
	vector<int>same = vector<int>(n, 0);
	rup(i, 0, n)seq[i] = i + 1;
	rup(i, 0, n)same[i] = (p[i] == seq[i]);
	list<long> index;
	rup(i, 0, n) {
		if (same[i]) {
			index.push_back(i);
		}
	}
	int count = 0;
	while (!index.empty()) {
		if (index.size() >= 2) {
			long i1 = index.front();
			index.pop_front();
			long i2 = index.front();
			index.pop_front();
			swap(p, i1, i2);
			count++;
		}
		else {
			long i1 = index.front();
			index.pop_front();
			for (int i = 0; i < n; i++) {
				if (p[i1] != p[i]) {
					swap(p, i1, i);
					count++;
					break;
				}
			}
		}
	}
	
	cout << count;
	return 0;
}



