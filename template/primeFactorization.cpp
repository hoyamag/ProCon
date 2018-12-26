#include <cmath>
#include <map>
std::map<long long, long long> primeFactorization(long long n) {
  /* prime factorization
   * nを素因数分解する
  */
  std::map<long long, long long> pf;
  for (long long i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      ++pf[i];
    }
  }
  if (n > 1) {
    ++pf[n];
  }
  return pf;
}
