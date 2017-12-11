long long gcd(long long a, long long b) {
  // gratest common divisor
	while (b != 0) {
		long long r = a%b;
		a = b;
		b = r;
	}
	return a;
}
