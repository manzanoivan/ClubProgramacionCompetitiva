typedef unsigned long long Long;
// Multiplicacion binaria a*b mod m.
Long Multiplicar(__int128 a, __int128 b, __int128 m) {
	return (Long)(( a*b )%m);
}

// Exponenciacion binaria a^n mod m.
Long Exponenciar(Long a, Long n, Long m) {
	Long resultado = 1ll;
	for (; n; n >>= 1ll) {
		if (n & 1) resultado = Multiplicar(resultado, a, m);
		a = Multiplicar(a, a, m);
	}
	return resultado;
}
 
//Tomado de geeksForGeeks
bool miillerTest(Long d, Long n){
	Long a = rand();
	a *= (Long)rand();
	a = a%(n-4ll);
	a += 2ll; //a = [2, n-2]
	Long x = Exponenciar(a, d, n);
	if (x == 1ll || x == n-1)
	   return true;
	while (d != n-1ll){
		x = Multiplicar( x, x, n );
		d *= 2ll;
		if (x == 1ll)	return false;
		if (x == n-1ll)	return true;
	}
	return false;
}

bool isPrime(Long n, int k){
	if (n <= 1ll || n == 4ll)  return false;
	if (n <= 3ll) return true;
	Long d = n - 1ll;
	while (!(d&1ll))
		d /= 2ll;
	for (int i = 0; i < k; i++)
		 if (miillerTest(d, n) == false)
			  return false;
	return true;
}

Long gcd( Long a, Long b ){
	if( b == 0ll ) return a;
	return gcd(b, a%b);
}

Long pollard_rho(Long n, Long c) {
    Long x = 2ll, y = 2ll, i = 1ll, k = 2ll, d;
    while (1) {
        x = (Multiplicar(x, x, n) + c);
        if (x >= n)	x -= n;
        d = gcd(x - y, n);
        if (d > 1ll) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

map<Long, int> mapa;
void Factorizar( Long n ){
	srand (time(NULL));
	if (n == 1)	return;
	if (isPrime(n, 10)) {
		mapa[n]++;
		return ;
	}
	Long d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
	Factorizar( d );
	Factorizar( n/d );
}