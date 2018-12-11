#include <iostream>
#include <cmath>
using namespace std ;
typedef unsigned long long ll ;
ll triangle(ll p) {
   if (p & 1)
      return p * ((p + 1) >> 1) ;
   else
      return (p >> 1) * (p + 1) ;
}
ll factorsum(ll p) {
   ll hif = sqrt(p) ;
   ll below = triangle(hif) ;
   ll r = p + triangle(p) - below ;
   for (ll f=2; f*f<=p; f++) {
      r += f * (p/f) ;
      if (f*f != p) {
         ll cnt = p/f ;
         r += triangle(cnt) - below ;
      }
   }
   return r ;
}
int main() {
   ll a, b ;
   cin >> a >> b ;
   ll s = factorsum(b) - factorsum(a-1) ;
   cout << s << endl ;
}
