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

void mymax(vector<long> &a) {
	//a is soreted
	int n = a.size();
	if (a[n - 2] > a[n - 1]) {
		swap(a[n - 2], a[n - 1]);
	}

}

void bomb(vector<long> &h, long a, long b, int index, long &deadline) {
	deadline += b;
	h[index] -= a - b;

}


int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<long> h = vector<long>(n, 0);
	for (int i = 0; i < n; i++) cin >> h[i];
	long count = 0;
	sort(h.begin(), h.end());
	long deadline = 0;
	while (1) {
		if (h[h.size() - 1] <= deadline) {
			break;
		}
		count++;
		bomb(h, a, b, h.size() - 1, deadline);
		mymax(h);
	}

	cout << count << endl;
	return 0;
}



