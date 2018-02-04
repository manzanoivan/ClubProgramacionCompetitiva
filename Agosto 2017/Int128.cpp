#include <iostream>
using namespace std;

typedef __int128 Intsote;

//Función para imprimir el __int128 (Bien robada de stackOverflow)
ostream& operator<<( ostream& dest, __int128_t value ){
    ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( ios_base::badbit );
        }
    }
    return dest;
}

int main(){

	Intsote a = 1ll;
	for( int i = 0; i < 100; i++ ){
		a <<= 1;
	}

	cout << a << endl;

	return 0;
}