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

	long long N;
	cin >> N;
	for (int h = 1; h <= 3500; h++) {
		for (int n = 1; n <= 3500; n++) {
			long long d = 4 * h*n - N*(n + h);
			if (d != 0) {
				double w = (double)N*h*n / d;
				if (w >1 && w == floor(w)) {
					cout << h << " " << n << " " << (long long)w<<endl;
					return 0;
				}
			}
		}
	}


	return 0;
}



