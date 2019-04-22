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

LL distance(int r0, int c0, int r1, int c1) {
  return abs(r1 - r0) + abs(c1 - c0);
}

class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    // DUMP("begin", R,C,r0,c0);
    VEC<list<pair<int, int>>> dists(R + C);

    REP(r, 0, R) {
      REP(c, 0, C) { 
        // DUMP(r,c,distance(r,c,r0,c0));
        dists[distance(r, c, r0, c0)].push_back(make_pair(r, c)); }
    }
    vector<vector<int>> ret;
    REP(i, 0, R + C) {
      for (auto v : dists[i]) {
        ret.push_back({v.first, v.second});
      }
    }
    return ret;
  }
};

int main() {
  auto a = Solution();
  auto ret = a.allCellsDistOrder(1, 2, 0, 0);
  cout << ret << endl;
  ret =a.allCellsDistOrder(2,2,0,1);
  cout << ret << endl;
  ret =a.allCellsDistOrder(2,3,1,2);
  cout << ret << endl;
  // cout << a.allCellsDistOrder(2, 2, 0, 1) << endl;
  // cout << a.allCellsDistOrder(2, 3, 1, 2) << endl;
}