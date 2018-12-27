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
LL f(LL n) {
  static vector<int> res(9, -1);
  if (n <= 0) return 1;
  if (res[n] != -1) return res[n];
  res[n] = f(n - 1) + f(n - 2);
  return res[n];
}

const LL M = 1000000007;
int main() {
  int H, W, K;
  cin >> H >> W >> K;
  auto dp = MATINIT(LL, H + 1, W + 1, 0);
  dp[0][1] = 1;
  REP(h, 1, H + 1) {
    REP(w, 1, W + 1) {
      dp[h][w] = (dp[h - 1][w] * (f(w - 2) * f(W - w - 1)) % M) % M;
      // cerr << dp[h][w] << "=" << dp[h - 1][w] << "*" << f(w - 2) << "*" << f(W - w - 1) << endl;
      if (w - 1 > 0)
        dp[h][w] =
            (dp[h][w] + (dp[h - 1][w - 1] * (f(w - 3) * f(W - w - 1))) % M) % M;
      if (w + 1 <= W)
        dp[h][w] =
            (dp[h][w] + (dp[h - 1][w + 1] * (f(w - 2) * f(W - w - 2))) % M) % M;
    }
  }
  // REP(i, 0, 9) cerr << f(i) << endl;
  // REP(i, 0, H + 1) cerr << dp[i] << endl;
  cout << dp[H][K] << endl;
}