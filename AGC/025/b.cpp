#include<bitset>
#include<math.h>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
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
#define rep(i, a, n) for(int i=(a);i<(int)(n);i++)
#define repc(i, a, n) for(int i=(a);i<=(int)(n);i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init) vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout<<(cond? "Yes":"No")<<endl;
#define YES(cond) cout<<(cond? "YES":"NO")<<endl;
#define DBG(str) cerr<<(str)<<endl;
int main() {
	int n, d1, d2;
	cin >> n >> d1 >> d2;;
	int cnt = 0;
	if (d1 > d2)swap(d1, d2);
	if (n <= 2 && d1 != 2 && d2 != 2) {
		cerr << 1 << endl;
		rep(i, 0, 2 * n * 2 * n) {
			cout << i << "," << i << endl;
			cnt++;
			if (cnt == n*n) {

				return 0;
			}
		}

	}
	else if (d1 != 1 && d2 != 2) {
		cerr << 2 << endl;
		rep(i, 0, 2 * n) {
			rep(j, 0, 2 * n) {
				cout << i << "," << j << endl;
				cnt++;
				if (cnt == n*n) {
					return 0;
				}
			}
		}
	}
	else if (d1 != 2 && d2 != 4) {
		cerr << 3 << endl;
		rep(i, 0, 2 * n) {
			rep(j, 0, 2 * n) {
				cout << i << "," << j << endl;
				cnt++;
				j++;
				if (cnt == n*n) {
					return 0;
				}
			}
		}

	}
	else if (d1 != 4 && d2 != 8) {
		cerr << 4 << endl;
		rep(i, 0, 2 * n) {
			rep(j, 0, 2 * n) {
				cout << i << "," << j << endl;
				cnt++;
				j++;
				if (cnt == n*n) {
					return 0;
				}
			}
			i++;
		}

	}
	else if (n > 3) {
		cerr << 5 << endl;
		if (d1 != 9 && d2 != 18) {
			rep(i, 0, 2 * n) {
				rep(j, 0, 2 * n) {
					cout << i << "," << j << endl;
					cnt++;
					j += 2;
					if (cnt == n*n) {
						return 0;
					}
				}
				i += 2;
			}
		}
	}

	return 0;
}



