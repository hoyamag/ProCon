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

const LL M = 1e9 + 7;
LL mul(LL a, LL b) { return a * b % M; }
int main() {
  LL n, m;
  cin >> n >> m;
  VEC<LL> A(n), B(m);
  REP(i, 0, n) { cin >> A[i]; }
  REP(i, 0, m) { cin >> B[i]; }
  sort(ALL(A), greater<int>());
  sort(ALL(B), greater<int>());
  REP(i, 0, n - 1) {
    if (A[i] == A[i + 1]) {
      cout << 0;
      return 0;
    }
  }
  REP(i, 0, m - 1) {
    if (B[i] == B[i + 1]) {
      cout << 0;
      return 0;
    }
  }
  A.push_back(-1);
  B.push_back(-1);

  LL ai = 0, bi = 0;
  LL ans = 1;
  for (int x = n * m; x > 0; --x) {
    if (A[ai] == x && B[bi] == x) {
      ++ai;
      ++bi;
    } else if (A[ai] == x) {
      ++ai;
      ans = mul(ans, bi);
    } else if (B[bi] == x) {
      ++bi;
      ans = mul(ans, ai);
    } else {
      ans = mul(ans, ai * bi - (n * m - x));
    }
  }
  cout << ans << endl;
  return 0;
}
