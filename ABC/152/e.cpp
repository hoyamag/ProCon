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

long long gcd(long long a, long long b) { /* the greatest common divisor*/
  while (b != 0) {
    long long r = a % b;
    a = b;
    b = r;
  }
  return a;
}

long long lcm(long long a, long long b) { /*the least common multiple*/
  return (a / gcd(a, b)) * b;
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
#include <cmath>
#include <map>
#include <ostream>
#include <vector>
struct PrimeFactorization {
  std::map<long long, long long> pf;
  PrimeFactorization() {}
  PrimeFactorization(long long n) {
    // nを素因数分解する(n==0, 1時に振る舞いが独特なので注意)

    // n==0, n==1 の取扱
    if (n == 0) {
      pf[0] = 1;
    }
    if (n == 1) {
      pf[0] = 0;
    }

    for (long long i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        n /= i;
        ++pf[i];
      }
    }
    if (n > 1) {
      ++pf[n];
    }
  }
  static PrimeFactorization lcm(const std::vector<long long> &a) {
    // calculate lcm of an array, result is prime factorized.
    // https://atcoder.jp/contests/abc152/tasks/abc152_e
    PrimeFactorization res;
    for (auto v : a) {
      PrimeFactorization p(v);
      for (auto e : p.pf) {
        res.pf[e.first] = std::max(res.pf[e.first], e.second);
      }
    }
    return res;
  }
  long long getInt() {
    long long res = 1;
    for (auto v : pf) {
      res *= pow(v.first, v.second);
    }
    return res;
  }
  long long getIntWithMod(long long M) {
    long long res = 1;
    for (auto v : pf) {
      res = res * modpow(v.first, v.second, M) % M;
    }
    return res;
  }
  PrimeFactorization &operator*=(const PrimeFactorization &a) {
    for (auto v : a.pf) {
      pf[v.first] += v.second;
    }
    return *this;
  }
  PrimeFactorization &operator/=(const PrimeFactorization &a) {
    for (auto v : a.pf) {
      pf[v.first] -= v.second;
    }
    return *this;
  }
  PrimeFactorization operator*(const PrimeFactorization &a) {
    PrimeFactorization res(*this);
    return res *= a;
  }
  PrimeFactorization operator/(const PrimeFactorization &a) {
    PrimeFactorization res(*this);
    return res /= a;
  }

 private:
  /* calculate n^p mod M. O(log(p)) */ long long modpow(long long n,
                                                        long long p,
                                                        long long M) {
    long long ans = 1;
    while (p > 0) {
      if (p & 1) ans = (ans * n) % M;
      n = (n * n) % M;
      p >>= 1;
    }
    return ans;
  }
};

std::ostream &operator<<(std::ostream &os, const PrimeFactorization &a) {
  os << "{";
  for (auto v : a.pf) {
    os << v.first << ": " << v.second << ", ";
  }
  os << "}";
  return os;
}
int main() {
  // DUMP(PrimeFactorization(0), PrimeFactorization(1));
  int N;
  cin >> N;
  VEC<LL> A(N);
  LL M = 1e9 + 7;
  REP(i, 0, N) cin >> A[i];
  auto lcmpf = PrimeFactorization::lcm(A);
  // DUMP(lcmv);
  VEC<ModInt> B(N);
  auto lcmv=ModInt(lcmpf.getIntWithMod(M));
  REP(i, 0, N) {
    B[i] = lcmv / A[i];
    // DUMP(B[i]);
  }
  // DUMP(B);
  ModInt sum = 0;
  REP(i, 0, N) { sum += B[i]; }
  cout << sum << endl;

  return 0;
}
