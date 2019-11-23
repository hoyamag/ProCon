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
LL calc(int T, VEC<int> &A, VEC<int> &B) {
  int N = A.size();
  auto dp = VEC<VEC<int>>(N + 1, VEC<int>(T + 1, 0));
  REP(i, 0, N + 1) {
    REP(j, 0, T + 1) { dp[i][j] = 0; }
  }
  REP(i, 0, N) {
    REP(t, 0, T + 1) {
      dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
      if (t - A[i] >= 0) dp[i + 1][t] = max(dp[i][t - A[i]] + B[i], dp[i][t]);
    }
  }
  // REP(i,0,N){
  //   DUMP(dp[i]);
  // }
  return dp[N][T];
}
int main() {
  int N, T;
  cin >> N >> T;
  VEC<int> A(N), B(N);
  REP(i, 0, N) { cin >> A[i] >> B[i]; }
  VEC<pair<int,int>>P;
  REP(i,0,N){
    P[i].first=B[i];
    P[i].second=A[i];
  }
  sort(ALL(P));
  LL ans = 0;
  REP(i, 0, N) {
    int ta = A[i];
    A[i] = 1;
    
    ans = max(ans, calc(T, A, B));
    A[i] = ta;
  }
  cout << ans << endl;

  return 0;
}
