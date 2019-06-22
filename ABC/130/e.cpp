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
void show(MAT<LL> v){
  REP(i,0,v.size()){
    DUMP(v[i]);
  }
}

int N;
int M;
VEC<LL> S;
VEC<LL> T;
VEC<VEC<LL>> dp;
int main() {
  cin >> N >> M;
  S = VEC<LL>(N + 1, -1);
  T = VEC<LL>(M + 1, -1);
  REP(i, 1, N + 1) { cin >> S[i]; }
  REP(i, 1, M + 1) { cin >> T[i]; }
  dp = MATINIT(LL, N + 1, M + 1, 0);
  REP(i,0,N+1){
    dp[i][0]=1;
  }
  REP(j,0,M+1){
    dp[0][j]=1;
  }
  dp[0][0] = 1;
  DUMP(S);
  DUMP(T);
  REP(i, 1, N + 1) {
    REP(j, 1, M + 1) {
      if (S[i] == T[j]) {
        dp[i][j] = 2 * dp[i - 1][j - 1];
      } 
    }
  }
  show(dp);
  cout<<dp[N][M]<<endl;

  return 0;
}
