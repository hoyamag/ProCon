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
LL f(LL N, LL X, VEC<LL> &a) {
  DUMP("call",N, X, a);
  int n = a.size();
  if(n==0)
    return 0;
  if (n == 1) {
    return 5 * a[0] + 2 * X;
  } else {
    VEC<LL> b1((n + 1) / 2), b2(n / 2);
    for (int i = 0; i < n; i += 2) {
      b1[i] = a[i];
      if (i + 1 < n)
        b2[i] = a[i + 1];
    }
    LL f1 = f((n + 1) / 2, X, b1);
    LL f2 = f(n / 2, X, b2);
    LL partial = f1 + f2;
    LL combine = 0;
    int i = 0;
    int k = 2 * n + 1 - 2 * i;
    while (k >= 5) {
      combine += k * a[i];
      i++;
      k -= 2;
    }
    combine += 5 * a[n - 1] + (n + 1) * X;
    DUMP(f1,f2, combine);
    return min(partial, combine);
  }
}

int main() {
  LL N, X;
  cin >> N >> X;
  VEC<LL> a(N);
  REP(i, 0, N) { cin >> a[i]; }
  cout << f(N, X, a) << endl;

  return 0;
}
