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
int top(int n) {
  int k = 0;
  while (n) {
    k = n % 10;
    n /= 10;
  }
  return k;
}
int main() {
  int N;
  cin >> N;
  LL cnt = 0;
  VEC<VEC<int>> P(10, VEC<int>(10, 0));

  REP(i, 1, N + 1) {
    int h = top(i);
    int t = i % 10;
    // DUMP(i, h, t);
    if (t == 0) continue;
    P[h][t]++;
  }
  REP(i, 0, 10) { DUMP(i, P[i]); }

  REP(h, 1, 10) {
    REP(t, 1, 10) {
      // DUMP(a, h, t, cnt);
      cnt += P[h][t] * P[t][h];
    }
  }
  cout << cnt << endl;

  return 0;
}
