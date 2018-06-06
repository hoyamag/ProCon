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
#define DBG(str) // cerr<<(str)<<endl;
int main() {
  int n;
  cin >> n;
  vector<int> l(n + 1, 0), r(n + 1, 0);
  rep(i, 0, n) { cin >> l[i] >> r[i]; }
  sort(all(l), greater<int>());
  sort(all(r));
  ll ma = 0;
  ll sum = 0;
  rep(i, 0, n / 2 + 1) {
    sum += 2 * (l[i] - r[i]);
    ma = max(ma, sum);
    // cerr << sum << " " << ma << endl;
  }
  cout << ma;

  return 0;
}
