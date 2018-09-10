#include <algorithm>
#include <bitset>
#include <cstdio>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
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
void show(VEC<VEC<int>> a) {
  int h = a.size();
  int w = a[0].size();
  REP(i, 0, h) {
    REP(j, 0, w) { cerr << a[i][j] << " "; }
    cerr << endl;
  }
}

int main() {
  int H, W;
  cin >> H >> W;
  VEC<VEC<int>> a(H, VEC<int>(W, 0));
  REP(h, 0, H) {
    REP(w, 0, W) {
      int b;
      cin >> b;
      a[h][w] = b % 2 == 1;
    }
  }
  stringstream stream;
  int cnt = 0;
  // cerr << endl;
  // show(a);
  // cerr << endl;

  REP(h, 0, H) {
    REP(w, 0, W - 1) {
      if (a[h][w] == 1) {
        cnt++;
        stream << h + 1 << " " << w + 1 << " " << h + 1 << " " << w + 2 << endl;
        a[h][w + 1] = (a[h][w + 1] + 1) % 2 == 1;
        a[h][w] = 0;
        // cerr << endl;
        // show(a);
        // cerr << endl;
      }
    }
  }
  //cerr << "HI" << endl;
  REP(h, 0, H - 1) {
    if (a[h][W - 1]) {
      cnt++;
      stream << h + 1 << " " << W << " " << h + 2 << " " << W << endl;
      a[h+1][W - 1] = (a[h+1][W - 1] + 1) % 2 == 1;
      a[h][W - 1] = 0;
      // cerr << endl;
      // show(a);
      // cerr << endl;
    }
  }
  cout << cnt << endl;
  cout << stream.str() ;
  return 0;
}
