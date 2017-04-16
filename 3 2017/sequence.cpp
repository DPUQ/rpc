#include<bits/stdc++.h>

using namespace std;


int main()
{

    long long res,inp,t;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&inp);
        res = inp * (inp+2);
        printf("%lld\n",res);
    }

    return 0;
}
