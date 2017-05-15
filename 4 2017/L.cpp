/**
* Problem L: Lowest Terms Fractions
* Status: YES
* Issue: Number Theory (comprime number, comprime formula)
*/

#include<bits/stdc++.h>
using namespace std;

typedef  unsigned long long  ull;
typedef long long ll;

const int rounds=10;

ll gcd(ll a, ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}

ll  mod_mul(ull a,ull b,ull mod)
{
    ull ret = 0;
    for (a %= mod, b %= mod; b != 0; b >>= 1, a <<= 1, a = a >= mod ? a - mod : a)
    {
        if (b&1)
        {
            ret += a;
            if (ret >= mod)    ret -= mod;
        }
    }
    return ret;
}

ll  mod_pow(ll a,ll exp,ll mod)
{
    ll ans=1;
    while(exp > 0)
    {
        if(exp & 1)
            ans=mod_mul(ans,a,mod);
        a= mod_mul(a,a,mod);
        exp >>=1;
    }
    return ans;
}

bool witness(ll a, ll n)
{
    ll u=n-1;
    ll t=0;
    if(n==a) return true;
    while(u%2 == 0)
    {
        t++;
        u >>=1;
    }

    ll next=mod_pow(a,u,n);
    if(next==1) return false;
    ll last;
    for(int i=0; i< t; i++)
    {
        last=next;
        next=mod_mul(last,last,n);
        if(next==1)
        {
            return last!=n-1;
        }
    }
    return next != 1;
}


bool miller_rabin(ull n, int it=rounds)
{
    if(n <=1) return false;
    if(n==2) return true;
    if(n%2 == 0) return false;
    for(int i=0; i <it; ++i)
    {
        ll a=rand()% (n-1)+1;
        if(witness(a,n))
        {
            return false;
        }
    }
    return true;
}

long long pollard_rho(ll n)
{
    ll x,y,i=1,k=2,d;

    x=y=rand()%n;

    while(1)
    {
        ++i;
        x=mod_mul(x,x,n);
        x+=2;
        if( x >= n) x-=n;
        if(x==y) return 1;

        d=gcd(abs(x-y),n);
        if(d!=1) return d;
        if(i==k)
        {
            y=x;
            k*=2;
        }

    }

    return 1;

}

set<ll > factorize(ll n)
{
    set<ll > ans;
    if(n==1)
    {
        return ans;
    }
    if(miller_rabin(n))
    {
        ans.insert(n);
    }
    else
    {
        ull d=1ull;

        while(d==1)
            d=pollard_rho(n);
        set<ll> dd = factorize(d);
        ans=factorize(n / d);
        ans.insert(dd.begin(),dd.end());

    }

    return ans;
}


int main()
{

    set<ll> fact;
    ll n;
    double res, sum;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        fact = factorize(n);
        sum = 0;
        res = n;
        for ( set<ll>::iterator it=fact.begin(); it!=fact.end(); ++it)
        {
            double mult = (double)(((double)*it - (double)1)/(double)(*it));
            res *= mult;
        }
        sum = res / 2;
        cout << (ll)res << " ";
        printf("%.4f\n", sum);

    }
}
