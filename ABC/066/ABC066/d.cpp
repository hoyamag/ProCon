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
ll M = 1e9 + 7;
ll frac(int n) {
  static vector<ll> f(1e5 + 1, -1);
  if (f[0] == -1) {
    f[0] = 1;
    rep(i, 0, 1e5 + 1) { f[i + 1] = (i + 1) * f[i] % M; }
  }
  return f[n];
}

ll comb(int n, int r) {
  //#TODO
}
ll inverse_frac(n) {
  //#TODO
}
int main() {
  // http://arc058.contest.atcoder.jp/data/arc/058/editorial.pdf
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n + 1) cin >> a[i];
  int m = n + 1;
  rep(k, 1, n + 2) {
        cout<<comb(m,k)-(2*comb(m-(i-j+1),k-1)<<endl;
  }

  return 0;
}
