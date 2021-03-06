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
int ans;
const int MAX_AB = 1000;
int dp[MAX_AB + 1][MAX_AB + 1];
int inf = 1 << 30;
int dfs(int A, int B, int C, int v) {
  if (A == 0 && B == 0) return inf - 1;
  if (A < 0 || B < 0 || C < 0) return inf - 1;
  if (dp[A][B] != inf) return dp[A][B];

  if (A + B == C && v > 0) {
    dp[A][B] = v;
    DUMP("    ", A, B, C, v, dp[A][B]);
    return v;
  }
  DUMP(A, B, C, v, dp[A][B]);
  dp[A][B] = min(dp[A][B], dfs(A - 1, B, C, v + 1));
  dp[A][B] = min(dp[A][B], dfs(A + 9, B - 1, C, v + 1));
  dp[A][B] = min(dp[A][B], dfs(A - 11, B + 1, C, v + 1));
  dp[A][B] = min(dp[A][B], dfs(A, B - 1, C, v + 10));
  return dp[A][B];
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  ans = 1 << 30;
  REP(i, 0, MAX_AB + 1) {
    REP(j, 0, MAX_AB + 1) { dp[i][j] = inf; }
  }
  int ans = dfs(A, B, C, 0);
  if (ans >= inf - 1) {
    cout << "Impossible" << endl;
  } else {
    cout << dfs(A, B, C, 0) << endl;
  }

  return 0;
}
