/**
* Problem K: Polygonal Park
* Status: YES
* Issue: Geometry  
*/

#include <bits/stdc++.h>
#define ptdec(q,n) fixed << setprecision(q) << n

using namespace std;

int main(){

  int t,hs,aux,n;
  int h,w,sa;
  double  Ta,ta;
  char c;

  cin >> t;

  while(t--){
      cin >> hs;
      aux = 0;
      h = w = 0;
      Ta = sa = ta = 0.0;
      for(int i=0; i < hs; i++){

        cin >> c >> n;

        if(c=='C'){
          sa+= n * n;      	
          aux++;
        }
        else if(c=='S'){
          sa+= n * n;
        }
        else{
          ta+= (sqrt(3)/4) * (n * n);
        }

        if(aux<=2){
          h+=n;
          if(aux==2) aux++;
        }
          	 	
        if (aux>=3 && aux <= 4){
         	w+=n;
         	if(aux==4)aux++;
        }

      }
       	
      double area=h*w;
      area=area - ta - sa;
      cout << ptdec(4,area) << "\n";
    }

  	return 0;
}
