#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
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
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto v : m) os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << ", " << p.second << "]";
  return os;
}
map<long long, long long> primeCount(long long n) {
  map<long long, long long> pc;
  long long ma = ceil(sqrt(n));
  for (long long i = 2; i <= ma; ++i) {
    while (n % i == 0) {
      n /= i;
      ++pc[i];
    }
  }
  if (n > 1) {
    ++pc[n];
  }
  return pc;
}

std::map<long long, long long> primeFactorization(long long n) {
  std::map<long long, long long> pc;
  long long ma = ceil(sqrt(n));
  for (long long i = 2; i <= ma; ++i) {
    while (n % i == 0) {
      n /= i;
      ++pc[i];
    }
  }
  if (n > 1) {
    ++pc[n];
  }
  return pc;
}
ostream &operator<<(ostream &os, std::map<long long, long long> &m) {
  for (auto a : m) {
    os << "[" << a.first << " " << a.second << "] ";
  }
  return os;
}

int main() {
  REP(i, 0, 100) { DUMP(primeFactorization(i)); }

  return 0;
}
