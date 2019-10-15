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
ULL sum(ULL n) { return (n * (n + 1) / 2) % ((LL)1e9 + 7); }

int main() {
  ULL N, K;
  cin >> N >> K;
  VEC<ULL> A(N);
  VEC<LL> same(2002, 0);
  REP(i, 0, N) {
    cin >> A[i];
    same[A[i]]++;
  }
  ULL orig = 0;
  REP(i, 0, N) {
    REP(j, i + 1, N) {
      if (A[i] > A[j]) orig++;
    }
  }
  // DUMP(orig);
  ULL MOD = 1e9 + 7;
  sort(ALL(A));
  reverse(ALL(A));
  ULL num;
  ULL ans = orig * K;
  // DUMP(A);
  VEC<ULL> lowerNum(2002, 0);
  REP(i, 0, N - 1) {
    if (A[i] == A[i + 1]) continue;
    lowerNum[A[i]] = N - i - 1;
  }
  // DUMP(lowerNum);
  REP(i, 0, lowerNum.size()) {
    ULL s = (lowerNum[i] * sum(K - 1)) % MOD;
    // DUMP(lowerNum[i], sum(K-1), s);
    ans = (ans +  (s*same[i])%MOD)%MOD;
  }
  cout << ans << endl;

  return 0;
}
