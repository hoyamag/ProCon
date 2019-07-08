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

int N;
VEC<LL> A;
VEC<LL> ans;
bool small(LL a) {
  int cur = a;
  LL sum = 0;
  REP(i, 0, N - 1) {
    if (i % 2 == 1) {
      cur = A[i] - cur;
      sum += cur;
    }
    ans[i] = 2 * cur;
  }
  DUMP(a, cur, sum);
  DUMP(ans);
  DUMP();
  return a < cur;
}
int main() {
  cin >> N;
  A = VEC<LL>(N);
  ans = VEC<LL>(N);
  REP(i, 0, N) cin >> A[i];
  VEC<int> Y(N, -1);
  LL l = 0;
  LL r = 1e9;
  while (abs(l - r) >= 2) {
    LL mid = l + r / 2;
    auto issmall = small(mid);
    DUMP(l, r, mid, issmall);
    if (issmall) {
      l = mid;
    } else
      r = mid;
  }
  small(r);
  DUMP(ans);

  return 0;
}
