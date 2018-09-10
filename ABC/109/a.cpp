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
  int a, b;
  cin >> a >> b;
  bool exist = 0;
  REPC(c, 1, 3) {
    if ((a * b * c) % 2 == 1) {
      exist = 1;
      break;
    }
  }
  Yes(exist);

  return 0;
}
