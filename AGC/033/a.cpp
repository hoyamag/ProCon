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
int dist(int h1, int w1, int h0, int w0) { return abs(h1 - h0) + abs(w1 - w0); }

int main() {
  int H, W;
  cin >> H >> W;
  char A[H][W];
  int d[H][W];
  VEC<pair<int, int>> black;
  REP(i, 0, H) {
    REP(j, 0, W) {
      cin >> A[i][j];
      if (A[i][j] == '#') black.push_back({i, j});
      d[i][j] = 1 << 30;
    }
  }
  REP(i, 0, H) {
    REP(j, 0, W) {
      if (A[i][j] == '.') {
        REP(k, 0, black.size()) {
          d[i][j] = min(d[i][j], dist(i, j, black[k].first, black[k].second));
        }
      }
    }
  }
  int ma = 0;
  REP(i, 0, H) {
    REP(j, 0, W) {
      if (A[i][j] == '.') ma = max(ma, d[i][j]);
    }
  }
  cout << ma << endl;

  return 0;
}
