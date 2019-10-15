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
const int LIM_M = 1001;
const int LIM_N = 13;
const int LIM_S = 1 << 12;
const int inf = 1 << 30;
LL dp[LIM_M][LIM_S];
int main() {
  REP(i, 0, LIM_M) {
    REP(j, 0, LIM_S) { dp[i][j] = inf; }
  }
  REP(j, 0, LIM_S) { dp[0][j] = 0; }
  int N, M;
  cin >> N >> M;
  VEC<int> A(M);
  VEC<int> B(M);
  VEC<int> keys(M, 0);
  auto C = MATINIT(int, M, N, -1);
  REP(i, 0, M) {
    cin >> A[i] >> B[i];
    REP(j, 0, B[i]) {
      cin >> C[i][j];
      keys[i] |= (1 << (C[i][j] - 1));
    }
  }
  int lims = 1 << N;
  DUMP(keys);
  REP(hako, 0, lims) {
    REP(key, 0, M) {
      LL nextS = hako | keys[key];
      LL nextV = dp[hako][key] + A[key];
      DUMP(hako, key, nextS, nextV);
      if (nextS != hako) {
        dp[nextS][key] = min(dp[nextS][key], nextV);
      } else {
        if (key - 1 >= 0) dp[hako][key] = dp[hako][key - 1];
      }
    }
  }
  cout << dp[lims - 1][M - 1] << endl;

  return 0;
}
