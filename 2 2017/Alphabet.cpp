#include<bits/stdc++.h>
using namespace std;

string s;
int dp[55];
int sol(int pos){
    if(dp[pos] != -1)
        return dp[pos];
    int res = 0;
    for(int i = pos + 1; i < s.length(); i++){
        if(s[i] > s[pos])
            res = max(res, 1 + sol(i));
    }
    return dp[pos] = res;
}

int main(){
    cin >> s;
    for(int i = 0; i < 55; i++){
        dp[i] = -1;
    }
    int res = -1;
    for(int i = 0; i < s.length(); i++){
        res = max(res, 1 + sol(i));
    }

    cout << 26 - res << endl;

}
