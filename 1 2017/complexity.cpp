#include <bits/stdc++.h>

using namespace std;
#define MAX_VALOR 110


map<char,int> m;
char palabra[MAX_VALOR];
vector<int> v;


int main(){

scanf("%s", &palabra);

int tam=strlen(palabra);

for(int i=0 ;i < tam; i++){
    char c= palabra[i];
    m[c]++;
}

for(int i=0; i < m.size();i++){
 v.push_back(m[i]);
}

sort(v.begin(),v.end());
int suma=0;
for(int i=0; i< m.size()-2;i++){
   suma+=v[i];
}

  printf("%d\n",suma);

return 0;
}
