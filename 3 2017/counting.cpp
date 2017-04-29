/**
* Problem C: Counting Edges and Graphs
* Status: YES
* Issue: DP, Maths
*/
#include<bits/stdc++.h>
using namespace std;

const long mod = 1000000007;
int edges[5001][5001];
int graphs[5001][5001];
int divs_[5001];

void fillDivs(int n)
{
    int aux,numberOfDivisors;
    divs_[0] = 0;
    divs_[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        numberOfDivisors = 0;

        for (int j = 1; j*j <= i; ++j)
        {
            if (i % j == 0)
            {
                aux = i/j;
                if (aux != j)
                    numberOfDivisors++;

                numberOfDivisors++;
            }
        }
        divs_[i] = numberOfDivisors-1;
    }
}

void fillDP(int n)
{

    long comb[50][50];

    for(int i = 0; i < 50; i++)
    {
        comb[i][0] = comb[i][i] = 1;
        for(int k = 1; k < i; k++)
            if(i - 1 < k)
				comb[i][k] = comb[i - 1][k - 1] % mod;
			else
				comb[i][k] = ( (comb[i - 1][k] % mod) + (comb[i - 1][k - 1]%mod) ) % mod;
    }

    fillDivs(n);

    for(int m=0; m<=n; m++)
            edges[1][m]=0,graphs[1][m]=1;

    for(int m = 2; m<=n; m++)
    {

        for(int k = 1; k<= n; k++)
        {
            if(divs_[m] > k)
            {
                edges[m][k] = ( (edges[m - 1][k] % mod )+ ( k % mod) ) % mod;
                graphs[m][k] =( (comb[divs_[m]][k] % mod) * (graphs[m - 1][k] % mod) ) % mod;
            }

            else
            {
                edges[m][k] = ( (edges[m - 1][k] % mod ) + (divs_[m] % mod) )%mod;
                graphs[m][k] = graphs[m - 1][k];
            }
        }

    }

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fillDP(5000);

    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << edges[n][k] << " " << graphs[n][k] << "\n";
    }


    return 0;
}
