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

// ABC129 https://youtu.be/L8grWxBlIZ4?t=9860
struct ModInt {
  static const int MOD = 1000000007;
  long long x;
  ModInt(long long x = 0) : x((x % MOD + MOD) % MOD) {}
  ModInt &operator+=(const ModInt a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  ModInt operator+(const ModInt a) const {
    ModInt res(*this);
    return res += a;
  }
  ModInt operator-(const ModInt a) const {
    ModInt res(*this);
    return res -= a;
  }
  ModInt operator*(const ModInt a) const {
    ModInt res(*this);
    return res *= a;
  }
  ModInt pow(long long t) const {
    if (!t) return 1;
    ModInt a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  // for prime MOD
  ModInt inv() const {
    // オイラーの定理より
    // https://ja.wikipedia.org/wiki/%E3%83%A2%E3%82%B8%E3%83%A5%E3%83%A9%E9%80%86%E6%95%B0
    return pow(MOD - 2);
  }
  // for prime MOD
  ModInt &operator/=(const ModInt a) { return (*this) *= a.inv(); }

  // for prime MOD
  ModInt operator/(const ModInt a) const {
    ModInt res(*this);
    return res /= a;
  }
};
std::ostream &operator<<(std::ostream &os, const ModInt &a) {
  os << a.x;
  return os;
}
// http://drken1215.hatenablog.com/entry/2018/06/08/210000

const int MAX = 210000;
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

ModInt Com(LL n, LL k) {
  ModInt res = 1;
  REP(i, 1, k + 1) {
    ModInt a = n - i + 1;
    res *= a / i;
  }
  return res;
}

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  ModInt ans;
  // COMinit();
  // ans=ModInt(2).pow(N)-COM(N,A)-COM(N,B);
  ans = ModInt(2).pow(N) - Com(N, A) - Com(N, B);
  cout << ans - 1 << endl;

  return 0;
}
