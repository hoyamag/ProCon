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
bool dp[101][10001][101];

int main() {
  REP(i, 0, 20) { cout << i * (i - 1) / 2 << endl; }
  int N, K;
  cin >> N >> K;
  int M = N - 1;
  // if (K == N - 2) {
  //   cout << M << endl;
  //   REP(i, 0, M) { cout << i + 1 << " "<<i + 2 << endl; }
  // } else {
  //   cout << -1 << endl;
  // }

  // REP(a, 3, N - 1) {
  //   int b = N + 2 - a;
  //   int numA = max(0LL, a - 1);
  //   int numB = max(0, b - 2);
  //   DUMP(a, b, numA, numB);
  //   if (numA + numB == K) {
  //     cout << M << endl;
  //     REP(i, 0, a - 1) { cout << 1 << " " << i + 2 << endl; }
  //     REP(i, 0, b - 1) { cout << a << " " << a + i << endl; }
  //     return 0;
  //   }
  // }
  // cout << -1 << endl;
  if (K < N - 2 || K > (N - 1) * (N - 2) / 2) {
    cout << -1 << endl;
    return 0;
  }
  REP(i, 0, N + 1) {
    REP(k, 0, N * N) {
      REP(r, 0, N) { dp[i][k][r] = 0; }
    }
  }
  dp[0][0][0]=1;
  dp[1][0][0]=1;
  dp[2][0][1]=1;

  int KMAX = N * (N - 1) / 2;
  int RMAX = N;
  REP(i1, 0, N + 1) {
    REP(i2, 0, N + 1 - i1) {
      REP(k1, 0, KMAX + 1) {
        REP(k2, 0, KMAX + 1) {
          REP(r1, 0, RMAX + 1) {
            REP(r2, 0, RMAX + 1) {
              if (dp[i1][k1][r1] && dp[i2][k2][r2]) {
                dp[i1 + i2][k1 + k2 + r1 + r2][r1 + 1] = 1;
                dp[i1 + i2][k1 + k2 + r1 + r2][r2 + 1] = 1;
              }
            }
          }
        }
      }
    }
  }
  REP(i,0,RMAX+1){
    if(dp[N][K][i]){
      cout<<M<<endl;
      return 0;
    }
  }

  return 0;
}
