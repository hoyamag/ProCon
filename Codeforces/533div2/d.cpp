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

bool inRange(int l, int x, int r) { return l <= x && x < r; }
int main() {
  int n, m, p;
  cin >> n >> m >> p;
  VEC<LL> s(p);
  REP(i, 0, p) cin >> s[i];
  auto g = MATINIT(char, n, m, '.');

  VEC<queue<pair<int, int>>> q(p, queue<pair<int, int>>());

  int cnt = 0;
  int lim = n * m;
  REP(i, 0, n) {
    REP(j, 0, m) {
      cin >> g[i][j];
      if (g[i][j] == '#') --lim;
      if (g[i][j] != '.' && g[i][j] != '#') g[i][j] = g[i][j] - '0' - 1;
      DUMP(g[i][j]);
      if (g[i][j] <= 9) {
        q[g[i][j]].push({i, j});
        ++cnt;
      }
    }
  }
    REP(x, 0, n) {
      REP(y, 0, m) { cerr << (g[x][y] <= 9 ? (int)g[x][y] : g[x][y]); }
      cerr << "\n";
    }
  DUMP("HI");
  int i = 0;
  while (cnt < lim) {
    for (int time = 0; time < s[i]; ++time) {
      int size = q[i].size();
      for (int j = 0; j < size; ++j) {
        int x, y;
        tie(x, y) = q[i].front();
        DUMP(x,y);
        q[i].pop();
        if (!inRange(0, x, n) || !inRange(0, y, m)) continue;
        if (g[x][y] == '.') {
          g[x][y] = i;
          ++cnt;
          if(g[x+1][y]=='.')q[i].push({x + 1, y});
          if(g[x-1][y]=='.')q[i].push({x - 1, y});
          if(g[x][y+1]=='.')q[i].push({x, y + 1});
          if(g[x][y-1]=='.')q[i].push({x, y - 1});
        }
      }
    }
    ++i;
    REP(x, 0, n) {
      REP(y, 0, m) { cerr << (g[x][y] <= 9 ? (int)g[x][y] : g[x][y]); }
      cerr << "\n";
    }
    DUMP(cnt,i);
  }

  VEC<int> ans(p, 0);
  REP(i, 0, n) {
    REP(j, 0, m) {
      if (g[i][j] <= 9) ++ans[g[i][j]];
    }
  }

  return 0;
}
