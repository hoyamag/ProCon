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
  VEC<VEC<int>> way(H, VEC<int>(W, 1));

  auto f = [&](int h, int w) {
    queue<pair<int, int>> q;
    stack<tuple<int, int, int, int>> path;
    q.push({h, w});
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      if (!path.empty())
        path.pop();
      int y = p.first;
      int x = p.second;
      way[y][x] = 0;
      if (a[y][x] == 1 && y != h && x != w) {
        while (!path.empty()) {
          auto t = path.top();
          cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << " "
               << get<3>(t);
          path.pop();
        }
      }
      q.pop();
      if (y + 1 < h) {
        q.push({y + 1, x});
        path.push(make_tuple(y, x, y + 1, x));
      }
      if (y - 1 >= 0) {
        q.push({y - 1, x});
        path.push(make_tuple(y, x, y - 1, x));
      }
      if (x + 1 < w) {
        q.push({y, x + 1});
        path.push(make_tuple(y, x, y, x + 1));
      }
      if (x - 1 >= 0) {
        q.push({y, x - 1});
        path.push(make_tuple(y, x, y, x - 1));
      }
    }
  };

  return 0;
}
