#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
const long mod = 1000000007;
int edges[5001][5001];
int graphs[5001][5001];
int divs_[5001];

void init() {
    divs_[0] = 0; divs_[1] = 0;
    for(int i = 2; i < 5001; i++) {
        set<int> s;
        s.insert(1);

        for(int j = 2; j*j <= i; j++) {
            if(i%j == 0) {
                s.insert(j);
                s.insert(i/j);
            }
        }
        divs_[i] = s.size();
    }
}

/** Aqui va el DP para llenar */

void fillDivs(int n)
{

    long comb[51][51];

     for(int i = 0; i<= 49; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int k = 1; k < i; k++)
            comb[i][k] = ( (comb[i-1][k]%mod)  + (comb[i-1][k-1]%mod) )%mod;
    }

    init();

    for(int m=0;m<=n;m++)
        for(int k=0;k<=5000;k++)
                edges[m][k]=0,graphs[m][k]=1;

    for(int m = 1; m<=n; m++)
    {

        for(int k = 1; k<= n; k++)
        {
            if(divs_[m] > k){
                edges[m][k] = ( (edges[m-1][k]%mod )+ (k%mod) )%mod;
                graphs[m][k] =( (comb[divs_[m]][k]%mod) * (graphs[m-1][k]%mod) ) % mod;
            }

            else{
                edges[m][k] = ( (edges[m-1][k]%mod ) + (divs_[m]%mod) )%mod;
                graphs[m][k] = graphs[m-1][k];
            }
        }

    }

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fillDivs(5000);

    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << edges[n][k] << " " << graphs[n][k] << "\n";
    }


    return 0;
}
