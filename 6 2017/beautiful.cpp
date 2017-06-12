/**
* Problem B: Beautiful Triad
* Status: YES
* Issue: Maths (Combinatorics)
*/
#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	long long n, k, res;
	cin >> t;
	while(t--){
		cin >> n >> k;
		res = (k + 1) * (k + 1) * (k + 1) * (n - k + 1) - (k * k * k) * (n - k);
		cout << res << endl;
	}

	return 0;
}