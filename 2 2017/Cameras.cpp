#include <bits/stdc++.h>

using namespace std;

class Fenwick{

    public:
    vector <int> tree;
    int maxVal;

    Fenwick(int n) {
        maxVal=n;
        tree= vector<int>(maxVal+1,0);
    }

    int query(int idx){
        int sum =0;
        while(idx > 0){

            sum+= tree[idx];
            idx -= (idx & -idx);
        }

        return sum;
    }

    void update(int idx, int val){
        while(idx<=maxVal){
            tree[idx]+=val;
            idx+= (idx & -idx);
        }
    }

    void init(int a[],int n){
        for(int i=0;i<n;i++)
            update(i+1,a[i]);
    }

};


int a[100000];

int main(){
    int n,m,r;
    scanf("%d %d %d",&n,&m,&r);

    int idx;

    for(int i=0;i<m;i++){
        scanf("%d",&idx);
        idx--;
        a[idx]++;
    }

    Fenwick f(n);
    f.init(a,n);

    int res=0;
    for(int i=0;i<=n-r;i++){
        int q = f.query(i+r) - f.query(i);

        if(q==0){
            f.update(i+r,1);
            f.update(i+r-1,1);
            a[i+r-1]=a[i+r-2]=1;
            res+=2;
        }
        if(q==1){
            if(a[i+r-1]==0){
                f.update(i+r,1);
                 a[i+r-1]=1;
            }else{
                f.update(i+r-1,1);
                a[i+r-2]=1;
            }
            res++;
        }
    }
    printf("%d\n",res);
    return 0;
}
