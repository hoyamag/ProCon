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
  for (auto p : m) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
void chmax(LL &a, LL b) { a = max(a, b); }

LL dp[2000 + 1][2000 + 1][2];
int main() {
  LL N, L;
  cin >> L >> N;
  VEC<LL> X(N + 1, 0), Y(N + 1, 0);
  REP(i, 1, N + 1) { cin >> X[i]; }
  REP(i, 1, N + 1) { Y[i] = L - X[N - i + 1]; }

  //   REP(l,0,N+1){
  //       REP(r,0,N+1){
  //           cerr<<dp[l][r][0]<<" ";
  //       }
  //       cerr<<endl;
  //   }

  REP(l, 0, N) {
    REP(r, 0, N) {
    //   DUMP(l, r, dp[l][r][0], dp[l][r][1]);
      chmax(dp[l + 1][r][0], dp[l][r][0] + X[l + 1] - X[l]);
      chmax(dp[l][r + 1][1], dp[l][r][0] + X[l] + Y[r + 1]);

      chmax(dp[l][r + 1][1], dp[l][r][1] + Y[r + 1] - Y[r]);
      chmax(dp[l + 1][r][0], dp[l][r][1] + X[l + 1] + Y[r]);
    }
  }
  LL ans = 0;
  REP(i, 0, N) {
    chmax(ans, dp[i][N - i][0]);
    chmax(ans, dp[i][N - i][1]);
  }
  cout << ans << endl;
  return 0;
}
