#include <bits/stdc++.h>
#define REP(i, a, n) for (long long i = (a); i < (long long)(n); ++i)
#define REPC(i, a, n) for (long long i = (a); i <= (long long)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail>
void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &s) {
  os << "{";
  for (auto p : s) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
std::map<long long, long long> primeFactorization(
    long long n) { /* prime factorization * nを素因数分解する */
  std::map<long long, long long> pf;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      ++pf[i];
    }
  }
  if (n > 1) {
    ++pf[n];
  }
  return pf;
}
ULL S;
VEC<ULL> keys(1e5, 0);

bool solve(ULL value) {
    assert(0);[]
  const ULL lim = 1e9;
  ULL left = 1;
  ULL right = 1;
  while (right < S) {
    right *= value;
  }
  left = right - S;
  DUMP("value, left, right", value, left, right);
  if(left>lim)return 0;
  //   DUMP(left, right);

  auto pright = primeFactorization(right);
  ULL x1 = pow(value, pright[value] / 2);
  ULL y2 = pow(value, (pright[value] + 1) / 2);
  //   DUMP("v", value, x1, y2);
  if (x1 > lim || y2 > lim) return 0;

  auto pf = primeFactorization(left);
  //   DUMP(left, pf);
  int i = 0;
  for (auto v : pf) {
    keys[i] = v.first;
    i++;
  }
  reverse(keys.begin(), keys.begin()+i);
  ULL ma = 1, mb = 1;
  for (auto v : keys) {
    if (v > lim) return 0;
    REP(i, 0, pf[v]) {
      if (ma < mb) {
        ma *= v;
      } else {
        mb *= v;
      }
    }
  }
  ULL y1 = ma;
  ULL x2 = mb;
  if (x1 * y2 < x2 * y1) {
    return 0;
  }
  DUMP(value, x1, y1, x2, y2);
  DUMP(x1 * y2 - x2 * y1, S);
  if (x1 <= lim && x2 <= lim && y1 <= lim && y2 <= lim &&
      x1 * y2 - x2 * y1 == S) {
    cout << 0 << " " << 0 << " " << x1 << " " << y1 << " " << x2 << " " << y2
         << endl;
    return 1;
  }
  return 0;
}
int main() {
  cin >> S;
  REP(i, 2, 1e9 + 1) {
    if (solve(i)) {
      return 0;
    }
  }

  return 0;
}
