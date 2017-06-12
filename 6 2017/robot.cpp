/**
* Problem J: The Robot’s Grid
* Status: YES
* Issue: DP
*/

#include<bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;


int r, c;
ll dp [30][30];

ll countPaths(){
 
    for (int i = 0; i < r; i++)
        dp[i][0] = 1;
 
    for (int j = 0; j < c; j++)
        dp[0][j] = 1;

    for (int i = 1; i < r; i++){
        for (int j = 1; j < c; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
 
    }
    return dp[r-1][c-1];
}


int main(){

	int t;
	cin >> t;
	while(t--){
		cin >> r >> c;
    	cout << countPaths() << endl;
	}

	return 0;
}