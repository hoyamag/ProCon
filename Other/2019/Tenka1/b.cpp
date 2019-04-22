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
const int MAX_N = 300;
const int MAX_A = 300;
LL dp[MAX_N + 2][MAX_N * MAX_A + 1];
LL MAX_M = MAX_N * MAX_A;

int main() {
  int N;
  cin >> N;
  VEC<int> A(N);
  REP(i, 0, N) cin >> A[i];
  sort(ALL(A));
  REP(i, 0, N) {
    REP(j, 0, MAX_M) { dp[i][j] = 0; }
  }

  if (A[0] + A[1] > A[2]) {
    dp[3][A[2]]++;
  }
  if (A[1] + A[2] > A[0]) {
    dp[3][A[0]]++;
  }
  if (A[0] + A[2] > A[1]) {
    dp[3][A[1]]++;
  }

  DUMP("HI");
  REP(i, 3, N) {
    REP(j, 0, MAX_M + 1) {
      // DUMP(i, j);
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] * 2);
      if (j + A[i] <= MAX_M)
        dp[i + 1][j + A[i]] = max(dp[i + 1][j + A[i]], dp[i][j]);
    }
  }
  DUMP("HI2");
  LL ans = 0;
  REP(i, 0, MAX_M + 1) { ans = ans + dp[N][i]; }
  cout << ans << endl;

  return 0;
}
