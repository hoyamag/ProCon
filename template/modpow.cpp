/* calculate n^p mod M. O(log(p)) */
long long modpow(long long n, long long p, long long M) {
  long long ans = 1;
  while (p > 0) {
    if (p & 1)
      ans = (ans * n) % M;
    n = (n * n) % M;
    p >>= 1;
  }
  return ans;
}
