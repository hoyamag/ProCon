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

	long long n, c;
	cin >> n >> c;
	vector<long long>a(n, 0);
	long long boxnum = 0;
	for (long long i = 0; i < n; i++)cin >> a[i];
	long long begin = 0;
	long long end = n;
	sort(a.begin(), a.end());
	while (begin < end - 1) {
		for (long long j = end - 1; j > begin; j--) {
			if (a[begin] + a[j] < c) {
				boxnum++;
				begin++;
				end--;
				break;
			}
			else {
				boxnum++;
				end--;

			}
		}
	}
	boxnum += end - begin;
	cout << boxnum;
	return 0;
}




