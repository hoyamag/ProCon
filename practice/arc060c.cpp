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
const int MAX_N = 50;
const int MAX_A = 50;
const int MAX_X = 50;
LL dp[MAX_N + 1][MAX_N + 1][MAX_X * MAX_N + 1];
int N, A;
VEC<LL> X;
int main() {
  cin >> N >> A;
  X = VEC<LL>(N + 1, 0);
  REP(i, 1, N + 1) cin >> X[i];
  sort(ALL(X));
  int maxX = X[X.size() - 1];
  DUMP(X);

  REP(j, 0, N + 1) {
    REP(k, 0, N + 1) {
      REP(s, 0, N * maxX + 1) {
        LL f = 0;
        if (j == 0 && k == 0 && s == 0)
          f = 1;
        else if (j >= 1 && s < X[j])
          f = dp[j - 1][k][s];
        else if (j >= 1 && k >= 1 && s >= X[j])
          f = dp[j - 1][k][s] + dp[j - 1][k - 1][s - X[j]];
        dp[j][k][s] = f;
        // DUMP(j, k, s, f);
      }
    }
  }
  int k = 1;
  LL ans = 0;
  while (k <= N) {
    // DUMP("   ", N, k, k * A, dp[N][k][k * A]);
    ans += dp[N][k][k * A];
    ++k;
  }
  cout << ans << endl;
}