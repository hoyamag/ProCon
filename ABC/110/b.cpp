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

int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  VEC<int> x(n), y(m);
  REP(i, 0, n) cin >> x[i];
  REP(i, 0, m) cin >> y[i];
  sort(ALL(x));
  sort(ALL(y));
  int xmax = x[n - 1];
  int ymin = y[0];
  string ans = xmax < ymin ? "No War" : "War";
  DUMP(xmax, ymin);
  if (xmax < ymin && X < ymin && ymin <= Y) {

    ans = "No War";
  } else
    ans = "War";
  cout << ans << endl;
 

  return 0;
}
