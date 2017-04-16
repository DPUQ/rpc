#include <bits/stdc++.h>
using namespace std;
typedef long long           ll;
typedef unsigned long long  ull;

const ll  MOD  = ll( 1e9 )+7LL;

ll mod_pow( ll b, ll e, ll mod = MOD ) {
  ll r = 1;
  while( e > 0 ) {
    if( e&1 ) r = ( r*b )%mod;
    b = ( b*b )%mod;
    e >>= 1;
  }
  return r;
}
 ll inv( ll x ) { return mod_pow( x, MOD-2 ); }
 ll suma2( ll x, ll y ) { x = x+y; return ( x > MOD ? x-MOD : x ); }
 ll resta( ll x, ll y ) { x = x-y; return ( x < 0 ? x+MOD : x ); }

ll mul( ll a, ll b, ll mod = MOD ) {
  ll x = 0, y = a%mod;
  while( b ) {
    if( b&1 ) {
      x = ( x+y )%mod;
    }
    y = ( y+y )%mod;
    b >>= 1;
  }
  return x;
}

const ll inv2 = inv( 2 );
const ll inv3 = inv( 3 );
const ll inv6=inv(6);

ll suma(ll n)
{
   return mul( mul( n, suma2( n, 1LL ) ), inv2 );
}

ll suma3(ll n){
 return mul( mul( suma( n ), suma2( mul( 2, n ), 1 ) ), inv3 );
}

ll solucion( ll numero )
{
    ll fila = numero/2 + 1;
    ll columna = numero-fila+1;
    ll sumaFila = resta( suma( suma( fila ) ), suma( suma( fila-1LL ) ) );
    ll sumaCol= suma2(mul(mul(mul(columna,columna-1),inv2),fila ),(mul(mul(mul(columna+1,columna),columna-1),inv6)));
    return suma2(mul(sumaFila,columna),mul(sumaCol,fila));
}

int main( )
{

    int nCasos,contador=1;
    scanf("%d",&nCasos);
    while(nCasos--)
    {
        ll numero;
        scanf("%lld",&numero);
        printf("Case #%d: %lld\n",contador,solucion(numero));
        contador++;
    }

    return 0;
}

