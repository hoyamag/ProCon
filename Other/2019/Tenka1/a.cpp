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
const int MAX_N = 2 * 1e5;
const int inf = 1 << 30;
int dp[MAX_N + 2][2];

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  REP(i, 0, N) {
    REP(j, 0, 2) { dp[i][j] = inf; }
  }
  int B = 1;
  int W = 0;
  dp[0][0] = 0;
  dp[0][1] = 0;
  if (S[0] == '#') {
    dp[1][B] = 0;
    dp[1][W] = 1;
  } else {
    dp[1][B] = 1;
    dp[1][W] = 0;
  }
  REP(i, 1, N) {
    if (S[i] == '#') {
      dp[i + 1][W] = dp[i][W] + 1;
      dp[i + 1][B] = min(dp[i][B], dp[i][W]);
    } else {
      dp[i + 1][W] = dp[i][W];
      dp[i + 1][B] = min(dp[i][W] + 1, dp[i][B] + 1);
    }
  }
  // REP(i, 0, N+1) { cerr << dp[i][B] << ", " << dp[i][W] << endl; }

  cout << min(dp[N][B], dp[N][W]) << endl;

  return 0;
}
