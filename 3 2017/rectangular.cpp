/**
* Problem G: Rectangular Sum
* Status: YES
* Issue: Maths
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long           ll;
typedef unsigned long long  ull;

const ll  MOD  = ll( 1e9 )+7LL;

ll mod_pow( ll b, ll e, ll mod = MOD )
{
    ll r = 1;
    while( e > 0 )
    {
        if( e&1 ) r = ( r*b )%mod;
        b = ( b*b )%mod;
        e >>= 1;
    }
    return r;
}
ll inv( ll x )
{
    return mod_pow( x, MOD-2 );
}
ll sum2( ll x, ll y )
{
    x = x+y;
    return ( x > MOD ? x-MOD : x );
}
ll sub( ll x, ll y )
{
    x = x-y;
    return ( x < 0 ? x+MOD : x );
}

ll mul( ll a, ll b, ll mod = MOD )
{
    ll x = 0, y = a%mod;
    while( b )
    {
        if( b&1 )
        {
            x = ( x+y )%mod;
        }
        y = ( y+y )%mod;
        b >>= 1;
    }
    return x;
}

const ll inv2 = inv( 2 );
const ll inv3 = inv( 3 );
const ll inv6 = inv(6);

ll sum(ll n)
{
    return mul( mul( n, sum2( n, 1LL ) ), inv2 );
}

ll sum3(ll n)
{
    return mul( mul( sum( n ), sum2( mul( 2, n ), 1 ) ), inv3 );
}

ll solve( ll n )
{
    ll row = n/2 + 1;
    ll col = n-row+1;
    ll sumRow = sub( sum( sum( row ) ), sum( sum( row-1LL ) ) );
    ll sumCol= sum2(mul(mul(mul(col,col-1),inv2),row ),(mul(mul(mul(col+1,col),col-1),inv6)));
    return sum2(mul(sumRow,col),mul(sumCol,row));
}

int main( )
{

    int t,c=0;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",++c,solve(n));
    }

    return 0;
}

