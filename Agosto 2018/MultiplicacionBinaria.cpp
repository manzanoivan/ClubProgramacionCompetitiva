// Multiplicacion binaria a*b mod m.
Long Multiplicar(Long a, Long b, Long m) {
    Long resultado = 0;
    for (; b; b >>= 1) {
        if (b & 1) resultado = (resultado + a) % m;
        a = (a + a) % m;
    }
    return resultado;
}