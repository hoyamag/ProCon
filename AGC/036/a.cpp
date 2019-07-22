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

int main() {
  LL S;
  cin >> S;
  auto pf = primeFactorization(S);
  VEC<LL> keys;
  for (auto v : pf) {
    keys.push_back(v.first);
  }
  LL lim = 1e9;
  DUMP(keys);
  reverse(ALL(keys));
  LL a = 1;
  LL ma = 1, mb = 1;
  for (auto v : keys) {
    REP(i, 0, pf[v]) {
      if (ma < mb) {
        ma *= v;
      } else {
        mb *= v;
      }
      if (ma > lim || mb > lim) {
        DUMP(v, pf[v], ma, mb);
        assert(0);
      }
    }
  }
  // for (a = sqrt(S) + 1; a >= 1; a--) {
  //   LL b = S / a;
  //   LL bp = (S + a - 1) / a;
  //   if (b == bp) {
  //     ma = a;
  //     mb = b;
  //     break;
  //   }
  // }
  cout << 0 << " " << 0 << " " << 0 << " " << ma << " " << mb << endl;

  return 0;
}
