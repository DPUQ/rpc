#include <bits/stdc++.h>

using namespace std;


int main(){

int nCasos,pisos;
int safe=1,broken;
char pa[7];
int va;
scanf("%d %d", &nCasos, &pisos);
broken=pisos;
while(nCasos--){
  scanf("%d %s",&va,&pa);
  if(pa[0]=='S'&& va > safe){
   safe=va;
  }
  if(pa[0]=='B' && va < broken){
  broken=va;
  }
}

printf("%d %d\n", safe+1,broken-1);

return 0;
}
