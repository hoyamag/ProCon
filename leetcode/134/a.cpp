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

class Solution {
 public:
  vector<int> numMovesStones(int a, int b, int c) {
    VEC<int> A = {a, b, c};
    sort(ALL(A));
    a = A[0], b = A[1], c = A[2];
    // DUMP(a, b, c);
    int mi = 0;
    if (c - a == 2)
      mi = 0;
    else if (c - b == 2 || b - a == 2)
      mi = 1;
    else {
      if (c - b - 1 >= 1) mi++;
      if (b - a - 1 >= 1) mi++;
    }
    int ma = (b - a - 1) + (c - b - 1);
    return {mi, ma};
  }
};
int main() {
  auto a = Solution();

  auto b = a.numMovesStones(1, 2, 5);
  cout << b << endl;
  b = a.numMovesStones(4, 3, 2);
  cout << b << endl;
  b = a.numMovesStones(3, 5, 1);
  cout << b << endl;

  return 0;
}