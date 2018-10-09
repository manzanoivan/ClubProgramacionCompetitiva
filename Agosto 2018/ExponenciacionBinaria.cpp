// Exponenciacion binaria a^n mod m.
Long Exponenciar(Long a, Long n, Long m) {
    Long resultado = 1;
    for (; n; n >>= 1) {
        if (n & 1) resultado = (resultado * a) % m;
        a = (a * a) % m;
    }
    return resultado;
}