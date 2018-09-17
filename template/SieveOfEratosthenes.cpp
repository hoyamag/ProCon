bool isPrime(int n) {
  // returns whether n is prime number or not
  // n should be in range [0, lim].
  // to see detail, search "Sieve of Eratosthenes"
  static int lim = 1e5;
  static bool done = false;
  static vector<bool> isp(lim + 1, 1);
  if (!done) {
    isp[0] = isp[1] = false;
    for (int i = 2; i <= lim; i++) {
      if (isp[i]) {
        for (int j = i + i; j <= lim; j += i) {
          isp[j] = false;
        }
      }
    }
    done = true;
  }
  return isp[n];
}
