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
int R, C;
const int MAX_R = 5;
const int MAX_C = 5;
int d[MAX_R + 1][MAX_C + 1];
void disp() {
  REP(a, 0, R * C) {
    REP(i, 0, R) {
      REP(j, 0, C) {
        if (d[i][j] == a + 1) {
          cout << i + 1 << " " << j + 1 << endl;
        }
      }
    }
  }
}
void dispD() {
  REP(i, 0, R) {
    REP(j, 0, C) { cout << d[i][j] << " "; }
    cout << endl;
  }
  cout << endl;
}
bool dfs(int cnt, int r, int c) {
  // DUMP(cnt,r,c);
  if (r < 0 || r >= R || c < 0 || c >= C) return 0;
  d[r][c] = cnt;
  if (cnt == R * C) return 1;
  // dispD();
  ++cnt;
  REP(i, 0, R) {
    if (i == r) continue;
    REP(j, 0, C) {
      if (j == c || i + j == r + c || i - j == r - c || d[i][j] != 0) continue;
      if (dfs(cnt, i, j)) {
        return 1;
      }
    }
  }
  d[r][c] = 0;
  --cnt;
  return 0;
}

int main() {
  int n;
  cin >> n;
  REP(s, 0, n) {
    cin >> R >> C;
    REP(i, 0, R) {
      REP(j, 0, C) { d[i][j] = 0; }
    }

    auto f = [&] {
      REP(i, 0, R) {
        REP(j, 0, C) {
          if (dfs(1, i, j)) {
            cout << "Case #" << s + 1 << ": POSSIBLE" << endl;
            disp();
            return;
          }
        }
      }
      cout << "Case #" << s + 1 << ": IMPOSSIBLE" << endl;
    };
    f();
  }

  return 0;
}
