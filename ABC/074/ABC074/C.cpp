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


int main() {
	// ABC074C AC
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	double ma = 0;
	int answ, anss;
	for (int i = 0; 100 * a*i <= f; i++) {
		for (int j = 0; 100 * b*j <= f; j++) {
			for (int k = 0; c*k <= f; k++) {
				for (int l = 0; d*l <= f; l++) {
					int w = 100 * a*i + 100 * b*j;
					int s = c*k + d*l;
					if (w + s <= f && 100 * s <= w*e) {
						double can = (double)100 * s / (w + s);
						if (ma <= can) {
							answ = w + s;
							anss = s;
							ma = can;
						}

					}
				}
			}
		}
	}
	cout << answ<<" "<<anss << endl;
	return 0;
}



