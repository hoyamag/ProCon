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

LL MM = 1e9 + 7;
int main() {
  int N, M;
  cin >> N >> M;
  VEC<int> A(M);
  set<int> S;
  REP(i, 0, M) {
    cin >> A[i];
    S.insert(A[i]);
  }
  // DUMP(S);
  sort(ALL(A));
  VEC<LL> p(N + 1, 0);
  p[0] = 1;
  if (S.count(1)==0) p[1] = 1;
  REP(i, 2, N + 1) {
    LL next = 0;
    if (S.count(i - 1) == 0) {
      next += p[i - 1];
    }
    if (S.count(i - 2) == 0) {
      next = (p[i - 2] + next) % MM;
    }

    p[i] = next % MM;
  }
  // DUMP(p);
  cout << p[N] << endl;

  return 0;
}
