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
  int n;
  cin >> n;
  VEC<string> w(n);
  REP(i, 0, n) cin >> w[i];
  bool valid = true;
  map<string, int> d;
  REP(i, 0, n - 1) {
    d[w[i]]++;
    char last = w[i][w[i].length() - 1];
    char first = w[i + 1][0];
    DUMP(w[i], last, first);
    if (last != first||d[w[i]]>1) {
      valid = 0;
      break;
    }
  }
    d[w[n-1]]++;
  
  Yes(valid&&d[w[n-1]]<=1);

  return 0;
}
