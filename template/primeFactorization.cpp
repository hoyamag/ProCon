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