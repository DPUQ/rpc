/**
* Problem H: Paint
* Status: YES
* Issue: Data Structures
*/

#include <bits/stdc++.h>
using namespace std ;

vector< pair<long long, long long > > tamInterv;
map<long long, long long> dp ;
std::map<long long ,long long >::iterator it;

int main() {
   long long tam,nCasos;
   scanf("%lld %lld",&tam,&nCasos);
    long long n1,n2;
    pair< long long, long long> aux;


    while(nCasos--){
    scanf("%lld %lld",&n1,&n2);
    aux.second=n1;
    aux.first=n2;
    aux.first++;
    tamInterv.push_back(aux);
    }

   sort(tamInterv.begin(), tamInterv.end()) ;



   for (int i=0;i < tamInterv.size(); i++) {
       it = dp.upper_bound(tamInterv[i].second);
      long long totalIntervalo = tamInterv[i].first - tamInterv[i].second ;

      if (it != dp.begin())
         totalIntervalo += (--it)->second ;

      if (dp.size() == 0 || totalIntervalo > dp.rbegin()->second)
         dp[tamInterv[i].first] = totalIntervalo ;

     }


   printf("%lld\n",tam-dp.rbegin()->second);

}
