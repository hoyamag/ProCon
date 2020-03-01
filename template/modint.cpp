#include <bits/stdc++.h>

// ABC129 https://youtu.be/L8grWxBlIZ4?t=9860
struct ModInt {
  static const int MOD = 1000000007;
  long long x;
  ModInt(long long x = 0) : x((x % MOD + MOD) % MOD) {}
  ModInt& operator+=(const ModInt a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt& operator-=(const ModInt a) {
    if ((x += MOD - a.x) >= MOD) x -= MOD;
    return *this;
  }
  ModInt& operator*=(const ModInt a) {
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
  bool operator==(const ModInt a) const {
    return this->x == a.x && this->MOD == a.MOD;
  }
  bool operator!=(const ModInt a) const {
    return this->x != a.x || this->MOD != a.MOD;
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
  ModInt& operator/=(const ModInt a) { return (*this) *= a.inv(); }

  // for prime MOD
  ModInt operator/(const ModInt a) const {
    ModInt res(*this);
    return res /= a;
  }
};
std::ostream& operator<<(std::ostream& os, const ModInt& a) {
  os << a.x;
  return os;
}
ModInt Combination(long long n, long long k) {
  // simple algorithm
  ModInt res = 1;
  for (long long i = 1; i < k + 1; i++) {
    ModInt a = n - i + 1;
    res *= a / i;
  }
  return res;
