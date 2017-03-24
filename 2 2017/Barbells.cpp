#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<long long> barbells,plates, sets;
map<long long, vector< long > > mp;
set<long long> res;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    long long b,p;

    for(int i=0;i<n;i++){
        cin >> b;
        barbells.push_back(b);
    }

    for(int i=0;i<m;i++){
        cin >> p;
        plates.push_back(p);
    }

    long mask = (1<< m);
    long long acc=0;

    for(long i=0;i<mask;i++){
        acc=0;
        for ( int j = 0; j < m ;  j++ ) {
                if( ( i & ( 1 << j ) ) != 0 )
                          acc+= plates[j] ;
        }
        mp[acc].push_back(i);
        sets.push_back(acc);
    }

    for(int i=0;i<sets.size();i++){
        int v = sets[i];
        for(int j=0; j< mp[v].size();j++){
            if(  (i & mp[v][j])==0 ){
                for(int k=0;k<n;k++){
                    res.insert(barbells[k]+ (v*2) );
                }
                break;
            }
        }
    }

    set<long long>::iterator it;
    for(it=res.begin();it!= res.end();it++){
        cout << *it << "\n";
    }

    return 0;
}
