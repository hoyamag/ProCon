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
  int K, Y, X;
  cin >> K >> Y >> X;
  bool odd = 1;
  int cnt = 0;
  int num = 0;
  string s = "yfkpo";
  char d[501][501];
  REP(y, 0, Y) {
    if (odd) {
      REP(x, 0, K) {
        d[y][x] = s[cnt % 5];
        ++cnt;
      }
      odd = !odd;
    } else {
      for (int x = K - 1; x >= 0; --x) {
        d[y][x] = s[cnt % 5];
        ++cnt;
      }
      odd = !odd;
    }
  }
  // REP(i, 0, Y) {
  //   REP(j, 0, K) { cerr << d[i][j]; }
  //   cerr << endl;
  // }
  // cnt = 0;
  // REP(y,0,Y){
  //   REP(x,0,K){
  //     cerr<<s[cnt%5];
  //     cnt++;
  //   }
  //   cerr<<endl;
  // }
  cout << d[Y-1][X-1]<<endl;

  return 0;
}
