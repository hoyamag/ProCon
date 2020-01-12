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

struct Cell {
  int h;
  int w;
  int dist;
};
int main() {
  int H, W;
  cin >> H >> W;
  VEC<string> S(H);
  REP(i, 0, H) cin >> S[i];
  // int dp[H][W][H][W];
  // const int lim = INT32_MAX;
  // REP(i, 0, H) {
  //   REP(j, 0, W) {
  //     REP(k, 0, H) {
  //       REP(l, 0, W) { dp[i][j][k][l] = lim; }
  //     }
  //   }
  // }

  int ma = 0;
  REP(sh, 0, H) {
    REP(sw, 0, W) {
      // DUMP("sh, sw:", sh,sw);
      queue<Cell> q;
      auto used = VEC<VEC<bool>>(H, VEC<bool>(W, 0));
      q.push({sh, sw, 0});
      int far = 0;
      while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int h = p.h;
        int w = p.w;
        int dist = p.dist;

        if (h < 0 || H <= h || w < 0 || W <= w) continue;
        if (S[h][w] == '#') continue;
        if (used[h][w]) continue;

        far = dist;
        used[h][w] = true;
        // dp[sh][sw][h][w] = dist;

        q.push({h + 1, w, dist + 1});
        q.push({h - 1, w, dist + 1});
        q.push({h, w + 1, dist + 1});
        q.push({h, w - 1, dist + 1});
      }
      ma = max(ma, far);
    }
  }
  cout << ma << endl;

  return 0;
}
