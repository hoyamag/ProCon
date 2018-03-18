int BitCount(int a) {
	int s = 0;
	while (a > 0) {
		if (a & 1) s++;
		a >>= 1;
	}
	return s;
}