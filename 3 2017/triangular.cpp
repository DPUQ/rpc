/**
* Problem H: Humbertov and the Triangular Spiral
* Status: YES
* Issue: Binary Search, Maths
*/

#include <bits/stdc++.h>
#define MAX_VAL 500000

using namespace std;

long long lv[MAX_VAL];


long long levels()
{
    long long i,p;
    int odd=1;
    for(i=0; i < MAX_VAL; i++)
    {
        p=4*odd;
        odd+=2;
        if(i==0)
        {
            lv[0]=4;
        }
        else
        {
            lv[i]=p+lv[i-1];
        }

    }

}

long long binarySearch(long long  x)
{
    long long r = MAX_VAL, l = 0LL;
    while (l <= r)
    {
        long long m = l + (r-l)/2;
        if (lv[m] == x)
            return m;
        if (lv[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long t;
    long long n,level,points,aux;
    long long  x,y;
    cin >> t;
    levels();

    while(t--)
    {
        x=y=0;
        cin >> n;
        level=binarySearch(n);
        points=4*(2*level+1);
        n -= lv[level-1];
        if(level > 0)
        {
            y = level*-1;
            x = level*2;
        }
        if(n <= points/2)
        {
            n --;
            x -= n;
        }
        else
        {
            x -= (points/2);

            if(n > (points/2) && n <= (points*3)/4 )
            {
                aux = n - (points/2);
                x += (aux+1);
                y += aux;
            }
            else
            {
                aux = n - (points*3)/4;
                x += (((points*3)/4)-(points/2) + (aux+1));
                y = level - aux+1;
            }
        }
        cout << x << " " << y << "\n";

    }


    return 0;
}

