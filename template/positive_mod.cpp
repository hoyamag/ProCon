long long positive_mod(long long a, long long b) {
  /*mod演算。return value range [0,b-1]*/
  if (b < 0)
    assert(false);
  if (a < 0) {
    a += (LL)(ceil(((double)-a / b))) * b;
  }
  return a % b;
}
