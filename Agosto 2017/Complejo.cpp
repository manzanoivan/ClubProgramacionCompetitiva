#include <iostream>
typedef double Double;
struct complejo{
  Double r, img;
  complejo(){}
  complejo( Double a, Double b ) : r(a), img(b){}
  inline complejo operator+( const complejo& b ) const{
    return complejo( r+b.r, img+b.img );
  }
  inline complejo operator-(const complejo& b)const{
    return complejo( r-b.r, img-b.img );  
  }
  inline complejo operator*(const complejo& b)const{
    return complejo( r*b.r - img*b.img, img*b.r+b.img*r );
  }
  inline complejo operator/(const int& n)const{
    return complejo( r/n, img/n );
  }
};

int main(){
  return 0;
}