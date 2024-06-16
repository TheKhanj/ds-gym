int mySqrt(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	long long l = 0, r = x;
	while (l != r - 1) {
		long long mid = (l + r) / 2;
		if (mid * mid <= x)
			l = mid;
		else
			r = mid;
	}
	return l;
}
