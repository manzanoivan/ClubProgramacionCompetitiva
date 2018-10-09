// Algoritmo de Euclides extendido entre a y b. Ademas de devolver el gcd(a, b), resuelve la ecuación diofantica con el par (x, y).
//Si el parametro mod no es especificado, se resuelve con aritmetica normal; si mod se especifica, la identidad se resuelve modulo mod.
Long Euclides(Long a, Long b, Long& x, Long& y, Long mod = 0) {
	if (!b) { x = 1, y = 0; return a; }
	Long gcd = Euclides(b, a % b, x, y, mod);
	x = !mod? x - y * (a / b): 
		(mod + x - (y * (a / b)) % mod) % mod;
	swap(x, y); return gcd;
}