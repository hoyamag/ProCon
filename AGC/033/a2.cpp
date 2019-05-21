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
  queue<VEC<int>> q;
  REP(i, 0, H) {
    REP(j, 0, W) {
      cin >> A[i][j];
      if (A[i][j] == '#') q.push({(int)i, (int)j, 0});
    }
  }
  int ma = 0;
  while (!q.empty()) {
    auto e = q.front();
    q.pop();
    int h = e[0];
    int w = e[1];
    int dist = e[2];
    // DUMP(h,w,dist);
    ma = max(ma, dist);
    if (0 <= h + 1 && h + 1 < H && A[h + 1][w] != '#') {
      A[h + 1][w] = '#';
      q.push({h + 1, w, dist + 1});
    }
    if (0 <= h - 1 && h - 1 < H && A[h - 1][w] != '#') {
      A[h - 1][w] = '#';
      q.push({h - 1, w, dist + 1});
    }
    if (0 <= w + 1 && w + 1 < W && A[h][w + 1] != '#') {
      A[h][w + 1] = '#';
      q.push({h, w + 1, dist + 1});
    }
    if (0 <= w - 1 && w - 1 < W && A[h][w - 1] != '#') {
      A[h][w - 1] = '#';
      q.push({h, w - 1, dist + 1});
    }
  }
  cout << ma << endl;

  return 0;
}
