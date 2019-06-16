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
string L;
int N;
LL dp[100003][2][2];
/* calculate n^p mod M. O(log(p)) */ long long modpow(long long n, long long p,
                                                      long long M) {
  long long ans = 1;
  while (p > 0) {
    if (p & 1) ans = (ans * n) % M;
    n = (n * n) % M;
    p >>= 1;
  }
  return ans;
}
LL M = 1e9 + 7;

LL F(LL n, bool freeA, bool freeB) {
  static LL M = 1e9 + 7;
  if (n == 1) return 1;
  LL k1 = modpow(3, n, M);
  if (freeA && freeB) {
    return k1;
  }
  LL k2 = F(n - 1, 1, freeB);
  LL k3 = F(n - 1, freeA, 1);
  return ((k1 + k2) % M + k3) % M;
}
int main() {
  // cerr<<pow(2,100000)<<endl;
  cin >> L;
  N = L.length();
  REP(i, 0, N + 1) {
    dp[i][0][0] = 0;
    dp[i][1][0] = 0;
    dp[i][0][1] = 0;
    dp[i][1][1] = 0;
  }
  dp[0][0][0] = 0;
  dp[0][1][0] = 0;
  dp[0][0][1] = 0;

  dp[1][0][0] = 1;

  auto update = [&](int i, bool a, bool b) {
    if(a && b){
      dp[i+1][a][b]= (3*dp[i][a][b])%M;
      return ;
    }
    dp[i + 1][1][b] = (dp[i + 1][1][b] + dp[i][a][b]) % M;
    dp[i + 1][a][1] = (dp[i + 1][a][1] + dp[i][a][b]) % M;
    dp[i + 1][a][b] = (dp[i + 1][a][b] + dp[i][a][b]) % M;
  };
  REP(i, 1, N) {
      update(i,0,0);
      update(i,1,0);
      update(i,0,1);
      update(i,1,1);
      DUMP(dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
  }
      DUMP(dp[N][0][0], dp[N][0][1], dp[N][1][0], dp[N][1][1]);
  cout<<(dp[N][0][0]+dp[N][0][1] + dp[N][1][0] + dp[N][1][1])%M<<endl;
  return 0;
}
