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
const int MAXN = 50;
const int inf = 1 << 30;
VEC<VEC<int>> X;
VEC<VEC<int>> Y;
void show(VEC<VEC<int>> M) {
  REP(i, 0, M.size()) { DUMP(M[i]); }
}

int main() {
  int N;
  cin >> N;
  X = MATINIT(int, N, N, inf);
  Y = MATINIT(int, N, N, inf);
  REP(i, 0, N) {
    X[i][i] = 0;
    Y[i][i] = 0;
  }
  VEC<int> x(N), y(N);
  REP(i, 0, N) {
    std::cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  REP(i, 0, N) {
    REP(j, 0, N) {
      if (i == j) continue;
      X[i][j] = x[j] - x[i];
      Y[i][j] = y[j] - y[i];
    }
  }
  // show(X);
  // DUMP();
  // show(Y);
  // DUMP();
  int count = 0;
  REP(i, 0, N) {
    REP(j, 0, N) {
      int p = X[i][j];
      int q = Y[i][j];
      // DUMP("begin, i,j,p,q", i, j, p, q);
      int cnt = 0;
      REP(h, 0, N) {
        if (h == p) continue;
        REP(w, 0, N) {
          if (w == q || h == w) continue;
          if (X[h][w] == p && Y[h][w] == q) {
            // DUMP("    ", h, w, cnt);
            ++cnt;
          }
        }
      }
      // DUMP("end, p,q,cnt", p, q, cnt);
      count = max(count, cnt);
    }
  }
  cout << N - count << endl;

  return 0;
}
