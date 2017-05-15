/**
* Problem F: Funny String
* Status: YES
* Issue: DP (LIS)
*/

#include<bits/stdc++.h>
using namespace std;

int dp[1005][30];
int t, f;
string s;
int sol(int u, int prev){
	if(u == s.length())
		return 0;
	if(dp[u][prev] != -1 && (int)s[u] >= prev)
		return dp[u][prev];
	if((int)s[u] >= prev)
		return dp[u][prev] = max(sol(u + 1, prev), 1 + sol(u + 1, ((int)s[u] + f) % 26));
	return dp[u][prev] = sol(u + 1, prev);
}

int main(){
	cin >> t;
	while(t--){
		cin >> s >> f;
		for(int i = 0; i < s.length(); i++)
			s[i] -= 97;
		for(int i = 0; i < 1005; i++)
			for(int j = 0; j < 30; j++)
				dp[i][j] = -1;
		cout << sol(0, 0) << endl;
	}
}
