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

// http://drken1215.hatenablog.com/entry/2018/06/08/210000
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

LL Sub1(LL N, LL K, VEC<LL> &A) {
  // return comb(N, K)*E(minX) mod 1e9+7
  //   or   comb(N, K)*E(maxX) mod 1e9+7

  // DUMP("Sub1", N, K, A);
  LL sum = 0;
  REP(i, 1, N - K + 1 + 1) {
    sum = (sum + (COM(N - i, K - 1) * (MOD+A[i - 1])%MOD) % MOD) % MOD;
    // DUMP("i, sum, COM(N-i,K-1), A[i-1]", i, sum, COM(N - i, K - 1), A[i -
    // 1]);
  }
  return sum;
}
int main() {
  LL N, K;
  cin >> N >> K;
  VEC<LL> A(N);
  REP(i, 0, N) cin >> A[i];
  sort(ALL(A));
  COMinit();
  LL mi = Sub1(N, K, A);
  reverse(ALL(A));
  LL ma = Sub1(N, K, A);
  // DUMP(ma, mi);
  // DUMP("COM(N,K)", COM(N, K));
  // DUMP("E(minX)", (double)mi / COM(N, K), "E(maxX)", (double)ma / COM(N, K));
  cout << (MOD - mi + ma) % MOD << endl;

  return 0;
}
