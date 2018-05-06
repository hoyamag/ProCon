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
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
#define DBG(str) cerr << (str) << endl;
#define DispVec(vec)                                                           \
  cerr << "DispVec:";                                                          \
  for (auto v : vec)                                                           \
    cerr << v << " ";                                                          \
  cerr << endl;
ll comb(int n, int r) {
  if (n < r)
    return 0;
  double c = 1;
  cerr << "comb(" << n << "," << r << ")";
  for (int i = 0; i < r; i++) {
    c *= (double)(n - i) / (i + 1);
  }
  cerr << ":" << c << endl;
  return (long long)round(c);
}

ll frac(int n) {
  static vector<int> f(1e5, -1);
  f[0] = 1;
  if (f[n] != -1)
    return f[n];
  else {
    cerr << "frac:" << to_string(f[n]) << endl;
    f[n] = n * frac(n - 1);

    return f[n];
  }
}
int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> cs(n + 1, 0);
  cs[0] = 0;
  rep(i, 1, n + 1) cs[i] = cs[i - 1] + a[i - 1];
  DispVec(cs);
  map<ll, int> m;
  rep(i, 0, cs.size()) m[cs[i]]++;
  ll sum = 0;
  for (auto v : m) {
    cerr << ":" << v.first << " " << v.second << endl;
    sum += comb(v.second, 2);
  }
  cout << sum;

  return 0;
}
