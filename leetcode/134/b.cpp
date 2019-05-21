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
const int MAX_N = 50;
bool searched[MAX_N][MAX_N];
int origColor;
bool dfs(vector<vector<int>> &grid, int r0, int c0, int color) {
  if (r0 < 0 || grid.size() <= r0 || c0 < 0 || grid[0].size() <= c0) return 1;
  if (searched[r0][c0]) return 0;
  if (grid[r0][c0] != origColor) {
    return 1;
  }
  searched[r0][c0] = 1;
  if (dfs(grid, r0, c0 + 1, color)) grid[r0][c0] = color;
  if (dfs(grid, r0 + 1, c0, color)) grid[r0][c0] = color;
  if (dfs(grid, r0, c0 - 1, color)) grid[r0][c0] = color;
  if (dfs(grid, r0 - 1, c0, color)) grid[r0][c0] = color;
  return 0;
}
class Solution {
 public:
  vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0,
                                  int color) {
    origColor = grid[r0][c0];
    REP(i, 0, MAX_N) {
      REP(j, 0, MAX_N) { searched[i][j] = 0; }
    }
    dfs(grid, r0, c0, color);
    return grid;
  }
};
void show(vector<vector<int>> grid) {
  REP(i, 0, grid.size()) {
    REP(j, 0, grid[i].size()) { cerr << grid[i][j] << " "; }
    cerr << endl;
  }
}
int main() {
  auto a = Solution();
  VEC<VEC<int>> t;
  t.push_back({1, 1});
  t.push_back({1, 2});
  show(a.colorBorder(t, 0, 0, 3));
  t.clear();
  t.push_back({1, 2, 2});
  t.push_back({2, 3, 2});
  show(a.colorBorder(t, 0, 1, 3));

  return 0;
}
