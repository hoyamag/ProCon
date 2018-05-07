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
  int n, t;
  cin >> n >> t;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  ll mi = a[0];
  vector<ll> b(n, 0);
  rep(i, 1, n) {
    b[i] = a[i] - mi;
    mi = min(mi, a[i]);
  }
  sort(all(b));
  ll ma = b[n - 1];
  int ans = upper_bound(all(b), ma) - lower_bound(all(b), ma);
  cout << ans;

  return 0;
}
