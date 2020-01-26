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
void show(VEC<VEC<int>> &d) {
  REP(i, 0, d.size()) {
    DUMP(d[i]);
    // REP(j,0,d[i].size()){
    //   cerr
    // }
  }
  cerr<<endl;
}

int main() {
  assert(0);
  int H, N;
  cin >> H >> N;
  VEC<int> A(N), B(N);
  REP(i, 0, N) { cin >> A[i] >> B[i]; }
  DUMP(A);
  DUMP(B);
  auto dp = VEC<VEC<int>>(H + 1, VEC<int>(N + 1, INT32_MAX >> 1));
  REP(i, 0, N+1) { dp[0][i] = 0; }
  REP(h, 0, H) {
    DUMP("H", h);
    show(dp);
    REP(i, 0, N ) {
      int nh = min((int)h + A[i], H);
      DUMP("nh", nh);
      DUMP("d(nh, i), d(h, i)+B(i)", dp[nh][i], dp[h][i]+B[i]);
      dp[nh][i + 1] = min(dp[nh][i], dp[h][i] + B[i]);
    }
  }

  cout << dp[H][N] << endl;

  return 0;
}
