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
struct cake {
  LL value;
  int a, b, c;
};
bool operator<(cake a, cake b) { return a.value < b.value; }

int main() {
  LL X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  VEC<LL> A(X), B(Y), C(Z);
  REP(i, 0, X) cin >> A[i];
  REP(i, 0, Y) cin >> B[i];
  REP(i, 0, Z) cin >> C[i];
  sort(ALL(A), greater<LL>());
  sort(ALL(B), greater<LL>());
  sort(ALL(C), greater<LL>());

  priority_queue<cake> sums;
  sums.push({A[0] + B[0] + C[0], 0, 0, 0});
  map<tuple<int, int, int>, bool> used;
  REP(i, 0, K) {
    auto t = sums.top();
    cout << t.value << endl;
    // DUMP(t.value, t.a, t.b, t.c);
    sums.pop();
    if (t.a + 1 < X) {
      tuple<int, int, int> tup = make_tuple(t.a + 1, t.b, t.c);
      if (used.count(tup) == 0) {
        sums.push({A[t.a + 1] + B[t.b] + C[t.c], t.a + 1, t.b, t.c});
        used[tup] = true;
      }
    }
    if (t.b + 1 < Y) {
      tuple<int, int, int> tup = make_tuple(t.a , t.b+1, t.c);
      if (used.count(tup) == 0) {
        sums.push({A[t.a] + B[t.b + 1] + C[t.c], t.a, t.b + 1, t.c});
        used[tup] = true;
      }
    }
    if (t.c + 1 < Z) {
      tuple<int, int, int> tup = make_tuple(t.a , t.b, t.c+1);
      if (used.count(tup) == 0) {
        sums.push({A[t.a] + B[t.b] + C[t.c + 1], t.a, t.b, t.c + 1});
        used[tup] = true;
      }
    }
  }

  return 0;
}
