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
LL add(LL a, LL b) { return (a + b) % M; }
LL mul(LL a, LL b) { return a * b % M; }

int main() {
  LL n, l, r;
  cin >> n >> l >> r;
  VEC<LL> N(3, (r - l + 1) / 3);
  for (int i = 0; i < (r - l + 1) % 3; ++i) {
    ++N[(l + i) % 3];
  }
  //DUMP(N);
  auto dp = MATINIT(LL, n + 1, 3, 0);
  dp[0][0]=1;

  REP(i, 1, n + 1) {
    REP(c, 0, 3) {
      REP(t, 0, 3) {
        dp[i][c] = add(dp[i][c], mul(dp[i - 1][t], N[(c + 3 - t) % 3]));
      }
    }
  }
  cout<<dp[n][0]<<endl;

  return 0;
}
