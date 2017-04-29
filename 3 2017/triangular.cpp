#include <bits/stdc++.h>
#define MAX_VALOR 500000

using namespace std;
typedef long long ll;
typedef vector<ll> vll;

long long nv[MAX_VALOR];


long long niveles()
{
    long long i,p;
    int impar=1;
    for(i=0; i < MAX_VALOR; i++)
    {
        p=4*impar;
        impar+=2;
        if(i==0){
        nv[0]=4;
        }else{
          nv[i]=p+nv[i-1];
        }

    }

}

long long binarySearch(long long  x)
{
    long long r = MAX_VALOR, l = 0LL;
    while (l <= r)
    {
        long long m = l + (r-l)/2;
        if (nv[m] == x)
            return m;
        if (nv[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);

    long nCasos;
    long long numero,nivel,numeros,aux;
    long long  x,y;
    cin >> nCasos;
    niveles();

    //ofstream of("a.txt");

    while(nCasos--)
    {
        x=y=0;
        cin >> numero;
        nivel=binarySearch(numero);
        numeros=4*(2*nivel+1);
        numero= numero-nv[nivel-1];
        if(nivel > 0)
        {
            y=nivel*-1;
            x=nivel*2;
        }
        if(numero <= numeros/2)
        {
            numero=numero-1;
            x=x-numero;
        }
        else if(numero > (numeros/2) && numero <= (numeros*3)/4 )
        {
            aux=numero-(numeros/2);
            x=x-(numeros/2)+aux+1;
            y=y+aux;
        }else{
             aux=numero-(numeros*3)/4;
             x=x-(numeros/2)+(((numeros*3)/4)-(numeros/2))+aux+1;
             y=nivel-aux+1;
        }
         cout << x << " " << y << "\n";

    }


return 0;
}

