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
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
LL calc(LL X, VEC<LL> &a) {
  int n = a.size();
  if (a[n - 1] == 0)
    n--;
  int i = 0;
  int k = 2 * n + 1 - 2 * i;
  LL combine = 0;

  while (k >= 5) {
    combine += k * a[i];
    i++;
    k -= 2;
  }
  combine += 5 * a[n - 1] + (n + 1) * X;
  return combine;
}
LL f(LL N, LL X, VEC<LL> &a, int gsize) {
  DUMP("call", N, X, a,gsize);
  int n = a.size();
  if (n == 0)
    return 0;
  if (n == 1) {
    return 5 * a[0] + 2 * X;
  } else {
    VEC<VEC<LL>> b(gsize, VEC<LL>((N + gsize - 1) / gsize, 0));
    int j = 0;
    for (int i = 0; i < n; i += gsize) {
      b[i % gsize][j]=a[i];
      if (i == gsize - 1)
        j++;
    }
    LL sum = 0;
    DUMP(b);
    REP(i, 0, gsize) { sum += calc(X, b[i]); }
    return sum;
  }
}

int main() {
  LL N, X;
  cin >> N >> X;
  VEC<LL> a(N);
  REP(i, 0, N) { cin >> a[i]; }
  LL mi = LLONG_MAX;
  REPC(i, 1, N) {
    mi = min(mi, f(N, X, a, i));
    DUMP(i, mi);
  }
  cout << mi << endl;

  return 0;
}
