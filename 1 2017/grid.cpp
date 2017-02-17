#include <bits/stdc++.h>

using namespace std;

#define INF 250001

typedef pair<int,int> ii;

int n,m;

int mat[501][501];
int sol[501][501];
bool can[501][501];


ii le(ii pa,int k){

return ii(pa.first,pa.second-k);

}

ii ri(ii pa,int k){

return ii(pa.first,pa.second+k);

}

ii up(ii pa,int k){

return ii(pa.first-k,pa.second);

}

ii dow(ii pa,int k){

return ii(pa.first+k,pa.second);

}

bool validar(ii pa){  
 return pa.first>=0 && pa.first<n && pa.second>=0 && pa.second<m && 
 !can[pa.first][pa.second];
}

int main(){

char c;

scanf("%d %d\n",&n,&m);


for(int i = 0; i<n; i++){
for(int j = 0; j<m; j++){
scanf("%c",&c);
mat[i][j] = (int)(c-48);
sol[i][j] = INF;
}
if(n!=n-1)
scanf("%c",&c);
}

queue<ii> cola;
cola.push(ii(0,0));
sol[0][0]=0;
ii aux,enc;

while(!cola.empty()){
  aux=cola.front();
  cola.pop();
  enc = le(aux,mat[aux.first][aux.second]);
  if(validar(enc)){
    cola.push(enc);
    sol[enc.first][enc.second] = sol[aux.first][aux.second]+1;
    can[enc.first][enc.second] = true;
  }
  
  enc = ri(aux,mat[aux.first][aux.second]);
  if(validar(enc)){
    cola.push(enc);
    sol[enc.first][enc.second] = sol[aux.first][aux.second]+1;
    can[enc.first][enc.second] = true;
  }
  
  enc = up(aux,mat[aux.first][aux.second]);
  if(validar(enc)){
    cola.push(enc);
    sol[enc.first][enc.second] = sol[aux.first][aux.second]+1;
    can[enc.first][enc.second] = true;
  }

  enc = dow(aux,mat[aux.first][aux.second]);
  if(validar(enc)){
    cola.push(enc);
    sol[enc.first][enc.second] = sol[aux.first][aux.second]+1;
    can[enc.first][enc.second] = true;
  }

}

if(sol[n-1][m-1] != INF)
printf("%d\n",sol[n-1][m-1]);

else
printf("IMPOSSIBLE\n");

return 0;

}
