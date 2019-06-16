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

int main() {
  int N, Q;
  cin >> N >> Q;
  VEC<VEC<LL>> I(N, VEC<LL>(3));
  REP(i, 0, N) {
    cin >> I[i][0] >> I[i][1] >> I[i][2];
    I[i][0] -= I[i][2];
    I[i][1] -= I[i][2];
  }
  VEC<LL> D(Q);
  auto f = [](VEC<LL> a, VEC<LL> b) { return a[0] < b[0]; };
  sort(ALL(I), f);
  REP(i, 0, Q) { cin >> D[i]; }
  int ans = 0;
  REP(i, 0, Q) {
    int ok = 0;
    int ng = N - 1;

    while (abs(ok - ng) > 1) {
      int mid = ok + ng / 2;
      if (I[mid][0] > D[i]) {
        ng = mid;
      } else {
        ok = mid;
      }
    }
    cout << I[ok][2] << endl;
  }

  return 0;
}
