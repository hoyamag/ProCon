
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

LL Sum(VEC<LL> a) {
  LL s = 0;
  REP(i, 1, a.size()) { s += abs(a[i] - a[i - 1]); }
  return s;
}
int main() {
  int n;
  cin >> n;
  VEC<LL> a(n);
  REP(i, 0, n) cin >> a[i];
  VEC<LL> b = a;
  sort(ALL(a));
  //DUMP(a);
  LL sum = 0;
  auto f = [&](int S) -> VEC<LL> {
    VEC<LL> ret;
    REP(i, 0, n) {
      if (i % 2 == S)
        ret.push_back(a[i / 2]);
      else
        ret.push_back(a[n - i / 2 - 1]);
    }
    return ret;
  };
  auto c0 = f(0);
  auto c1 = f(1);
  LL s0 = Sum(c0);
  LL s1 = Sum(c1);
  //DUMP(c0);
  //DUMP(c1);
  //DUMP(s0, s1);
  LL last0 = c0[n - 1];
  LL last1 = c1[n - 1];
  auto cand = {s0, s1, s0 + abs(c0[0] - last0) - abs(c0[n - 2] - last0),
               s1 + abs(c1[0] - last1) - abs(c1[n - 2] - last1)};
  //DUMP(VEC<LL>(cand));
  std::cout << max(cand) << endl;

  return 0;
}
