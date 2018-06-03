#include <algorithm>
#include <bitset>
#include <cstdio>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define ull unsigned long long
#define ll long long
#define rep(i, a, n) for (int i = (a); i < (int)(n); i++)
#define repc(i, a, n) for (int i = (a); i <= (int)(n); i++)
#define all(t) t.begin(), t.end()
#define rall(t) t.rbegin(), t.rend()
#define mat(type, row, col, init)                                              \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
#define DBG(str) cerr << (str) << endl;
int main() {
  int w, h, n;
  cin >> w >> h >> n;
  vector<int> x(n), y(n), a(n);
  rep(i, 0, n) cin >> x[i] >> y[i] >> a[i];
  int a1, a2, a3, a4;
  a1 = a3 = 0;
  a2 = w;
  a4 = h;
  rep(i, 0, n) {
    if (a[i] == 1)
      a1 = max(a1, x[i]);
    if (a[i] == 2)
      a2 = min(a2, x[i]);
    if (a[i] == 3)
      a3 = max(a3, y[i]);
    if (a[i] == 4)
      a4 = min(a4, y[i]);
  }
  cout << max(a2 - a1, 0) * max(a4 - a3, 0);

  return 0;
}
