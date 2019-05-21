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
void show(VEC<VEC<int>> m) {
  REP(i, 0, m.size()) {
    REP(j, 0, m[i].size()) { cerr << m[i][j] << " "; }
    cerr << endl;
  }
}
int H, W, N, Sr, Sc;

bool validH(int h) { return 1 <= h && h <= H; }
bool validW(int w) { return 1 <= w && w <= W; }
int main() {
  cin >> H >> W >> N >> Sr >> Sc;
  string S, T;
  cin >> S >> T;

  int Up = Sr;
  int Down = Sr;
  int Left = Sc;
  int Right = Sr;

  REP(j, 0, N) {
    // DUMP(j, S[j], Up, Down, Left, Right);
    if (S[j] == 'U') {
      Up--;
    }
    if (S[j] == 'D') {
      Down++;
    }
    if (S[j] == 'L') {
      Left--;
    }
    if (S[j] == 'R') {
      Right++;
    }
    if (!validH(Up) || !validH(Down) || !validW(Left) || !validW(Right)) {
      //   DUMP(Up, Down, Left, Right);
      cout << "NO" << endl;
      return 0;
    }
    if (T[j] == 'U') {
      if (validH(Down - 1)) Down--;
    }
    if (T[j] == 'D') {
      if (validH(Up + 1)) Up++;
    }
    if (T[j] == 'L') {
      if (validW(Right - 1)) Right--;
    }
    if (T[j] == 'R') {
      if (validW(Left + 1)) Left++;
    }
  }
  cout << "YES" << endl;

  return 0;
}
