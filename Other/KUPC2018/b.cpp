#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init)                                          \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T> using VEC = std::vector<T>;
template <class T> using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail> void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}
MAT<char> c;
int H, W;
list<char> ans;

bool dfs(int nh, int nw) {
  //DUMP(nh, nw);
  if (nh == -1) {
    return 1;
  } else if (nw < 0 || W <= nw) {
    return 0;
  } else if (c[nh][nw] == 'x') {
    return 0;
  } else if (nh == 0 && c[nh][nw] != 'x') {
    return 1;
  } else {
    REP(i, 0, 3) {
      if (dfs(nh - 1, nw - 1 + i)) {
        char t;
        if (i == 0)
          t = 'L';
        else if (i == 1)
          t = 'S';
        else
          t = 'R';
        ans.push_front(t);
        return 1;
      }
    }
  }
  return 0;
}
int main() {
  ans = list<char>();
  cin >> H >> W;
  c = MATINIT(char, H, W, 0);
  REP(h, 0, H) REP(w, 0, W) cin >> c[h][w];
  //DUMP(c);
  bool possible;
  REP(w, 0, W) {
    if (c[H - 1][w] == 's')
      possible = dfs(H - 1, w);
  }
  if (possible) {
    for (auto v : ans) {
      cout << v;
    }
  } else
    cout << "impossible";
  cout << endl;
  return 0;
}
