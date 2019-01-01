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
int H, W;
int sum;
VEC<VEC<char>> b;
bool dfs(int h, int w, int len) {
  if (h >= H || w >= W) return 0;
  if (b[h][w] != '#') return 0;

  if (h == H - 1 && w == W - 1) {
  DUMP(len);
    if(len==sum) return 1;
    else return 0;
  }
  if (dfs(h + 1, w, len+1) || dfs(h, w + 1, len+1)) return 1;
  return 0;
}

int main() {
  cin >> H >> W;
  b = MATINIT(char, H, W, '.');
  sum = 0;
  REP(i, 0, H) {
    REP(j, 0, W) {
      cin >> b[i][j];
      if (b[i][j] == '#') ++sum;
    }
  }
  DUMP(sum);
  cout << (dfs(0, 0, 1) ? "Possible" : "Impossible") << endl;

  return 0;
}
