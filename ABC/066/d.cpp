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
ll modpow(ll n, ll p) {
  if (p == 1)
    return n;
  ll odd = (p % 2 == 1) ? n : 1;
  ll mid = modpow(n, p / 2);
  ll ans = ((mid * mid) % M) * odd % M;
  cerr << "modpow(" << n << "," << p << "):" << ans << endl;
  return ans;
}
ll frac(int n) {
  static vector<ll> f(1e5 + 1, -1);
  if (f[0] == -1) {
    f[0] = 1;
    rep(i, 0, 1e5 + 1) { f[i + 1] = (i + 1) * f[i] % M; }
  }
  cerr << "frac(" << n << "):" << f[n] << endl;
  return f[n];
}

ll inverse_frac(int n) {
  static vector<ll> f(1e5 + 1, -1);
  if (f[0] == -1) {
    ll lim = 1e5;
    f[lim] = (ll)modpow(frac(lim), M) % M;
    cerr << "f[lim]:" << f[lim] << endl;
    for (int i = lim - 1; i >= 0; i--) {
      f[i] = (f[i + 1] * M) % M;
    }
  }
  cerr << "invfrac(" << n << "):" << f[n] << endl;
  return f[n];
}
ll comb(int n, int r) {
  return frac(n) * inverse_frac(r) * inverse_frac(n - r) % M;
}
int main() {
  // http://arc058.contest.atcoder.jp/data/arc/058/editorial.pdf
  int n;
  cin >> n;
  int m = n + 1;
  vector<pair<int, int>> b(m, {0, 0});
  rep(i, 0, n + 1) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(all(b));
  int left, right;
  left = right = -1;
  rep(i, 0, m - 1) {
    if (b[i].first == b[i + 1].first) {
      left = min(b[i].second, b[i + 1].second);
      right = max(b[i].second, b[i + 1].second);
      break;
    }
  }

  rep(k, 1, n + 2) {
    cout << comb(m, k) - comb(m - (left - right + 1), k - 1) << endl;
  }

  return 0;
}
