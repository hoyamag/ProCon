long long gcd(long long a, long long b) {
  // the greatest common divisor
	while (b != 0) {
		long long r = a%b;
		a = b;
		b = r;
	}
	return a;
}
long long lcm(long long a, long long b) {
  //the least common multiple
	return (a / gcd(a, b))*b;
}
