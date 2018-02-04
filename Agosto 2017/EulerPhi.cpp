long long EulerPhi(long long n){
	long long ans = n, i;
	for (i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ans -= ans / i;
		}
	}
	if (n > 1) ans -= ans / n
	return ans;
}