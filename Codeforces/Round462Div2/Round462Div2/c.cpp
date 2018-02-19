#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<sstream>
#include<list>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<set>
#include<utility>
#include<initializer_list>
#include<tuple>
#include<regex>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(t) t.begin(), t.end()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));

int main() {

	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n)cin >> a[i];
	vector<int>b(n, 0);
	vector<bool>is2(n, 0);
	int now = a[0];
	b[0] = 1;
	int j = 0;
	rep(i, n - 1) {
		if (a[i + 1] == now) {
		}
		else {
			j++;
			now = a[i + 1];
		}
		++b[j];
		if (a[i + 1] == 1)is2[j] = false;
		else is2[j] = true;

	}
	int sumax = 0;
	rep(i, n) {
		if (is2[i] == true) {
			int sum = 0;
			for (int j = -1; j < 3; j++) {
				if (i + j >= 0 && i + j < n) {
					sum += b[i + j];
				}
				sumax = max(sumax, sum);
			}
		}
	}


	cout << sumax << endl;

	return 0;
}



