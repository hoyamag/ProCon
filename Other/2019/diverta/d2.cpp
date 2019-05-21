
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
LL N;
LL dfs(map<LL, LL> &pf, LL Sum) {
  DUMP("dfs", pf, Sum);
  if (pf.size() == 0) {
    LL m = max(Sum - 1, 1LL);
    DUMP("edge ", m, N, N / m, N % m);
    if (N / m == N % m)
      return m;
    else
      return 0;
  }
  LL ans = 0;
  pair<long, long> r = *pf.begin();
  pf.erase(pf.begin());
  REP(i, 0, r.second + 1) {
    LL t = pow(r.first, i);
    DUMP("         ", i, r, pf, t, Sum * t);
    ans += dfs(pf, Sum * t);
  }
  pf.insert(r);
  return ans;
}
int main() {
  cin >> N;
  LL sum = 0;
//   REP(m, 1, N) {
//     if (N / m == N % m) {
//       DUMP(m, sum);
//       sum += m;
//     }
//   }
//   DUMP("simple", sum);

  auto pf = primeFactorization(N);
  LL ans = dfs(pf, 1LL);
  cout << ans << endl;

  return 0;
}
