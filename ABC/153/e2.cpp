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
    REP(j, 0, d[i].size()) { printf("%10d ", d[i][j]); }
    puts("");
  }
  cerr << endl;
}

int main() {
  int H, N;
  cin >> H >> N;
  VEC<int> A(N), B(N);
  REP(i, 0, N) { cin >> A[i] >> B[i]; }
  //   DUMP(A);
  //   DUMP(B);
  auto dp = VEC<VEC<int>>(N + 1, VEC<int>(H + 1, INT32_MAX >> 1));
  REP(i, 0, N + 1) { dp[i][0] = 0; }
  REP(i, 0, N) {
    REP(h, 0, H + 1) {
      //   int nh = min((int)h + A[i], H);
      //   int nc = B[i];
      //   DUMP("nh", nh);
      //   DUMP("d(nh, i), d(h, i)+B(i)", dp[nh][i], dp[h][i] + B[i]);

      if (h < A[i]) {
        dp[i + 1][h] = dp[i][h];
      } else {
        dp[i + 1][h] = min(dp[i][h], dp[i + 1][h - A[i]] + B[i]);
      }
    }
    // DUMP("N", i);
    // show(dp);
  }
  LL ans = INT32_MAX;
  REP(h, 0, H + 1) {
    REP(i, 0, N) {
      LL nh = h + A[i];
      LL nc = dp[N][h] + B[i];
      if (nh >= H) {
        ans = min(ans, nc);
      }
    }
  }

  std::cout << ans << endl;

  return 0;
}
