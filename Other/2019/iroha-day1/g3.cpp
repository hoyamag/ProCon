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

int main() {
  LL N, M, K;
  cin >> N >> M >> K;
  VEC<LL> A(N + 1, 0);
  REP(i, 1, N + 1) { cin >> A[i]; }
  LL dp[M + 1][N + 1];
  REP(j, 0, M + 1) {
    REP(k, 0, N + 1) {
      LL v = -1;
      if (j == 0 && k == 0) v = 0;
      dp[j][k] = v;
    }
  }
  REP(j, 1, M + 1) {
    REP(k, j, N + 1) {
      REP(a, max(0LL, k - K), k) {
        if (dp[j - 1][a] >= 0) dp[j][k] = max(dp[j][k], dp[j - 1][a] + A[k]);

        // cerr << "    dp(" << j - 1 << ", " << a << ") = " << dp[j - 1][a]
        //      << ", A[" << k << "] = " << A[k] << endl;
      }
    //   cerr << "dp(" << j << ", " << k << ") = " << dp[j][k] << endl;
    }
  }

  LL ma = -1;
  REP(k, 0, K) { ma = max(ma, dp[M][N - k]); }
  cout << ma << endl;

  return 0;
}
