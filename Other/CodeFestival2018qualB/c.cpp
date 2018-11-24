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

int main() {
  int n;
  cin >> n;
  VEC<string> s(n, string(n, '.'));
  MAT<bool>f=MATINIT(bool, n+2,n+2,0);

  int nextj = 0;
  REP(i, 0, n) {
    REP(j, 0, n) {
      if (j % 5 == nextj) {
        s[i][j] = 'X';
        f[i+1][j+1]=1;
        f[i][j+1]=1;
        f[i+1][j]=1;
        f[i+2][j+1]=1;
        f[i+1][j+2]=1;
      }
    }
    nextj = (nextj + 3) % 5;
  }
  REP(i, 0, n) {
    REP(j, 0, n) { cout << (f[i+1][j+1] == 0 ? 'X' : s[i][j]); }
    cout << endl;
  }
  return 0;
}
