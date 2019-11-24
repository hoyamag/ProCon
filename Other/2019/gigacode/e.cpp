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
struct Car {
  LL x, v, d;
};

int main() {
  int N;
  LL L;
  cin >> N >> L;
  VEC<Car> C(N + 1);
  C[0].x = 0;
  cin >> C[0].v >> C[0].d;
  REP(i, 1, N + 1) { cin >> C[i].x >> C[i].v >> C[i].d; }
  VEC<int> road(L + 1, 0);
  REP(i, 0, N + 1) {
    auto car = C[i];
    REP(x, car.x, min(L, car.x + car.d + 1)) { road[x] = car.v; }
  }
  REP(i, 0, L + 1) {
    if (road[i] == 0) {
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout<<L<<endl;

  return 0;
}
