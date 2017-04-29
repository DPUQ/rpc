/**
* Problem D: DPA Numbers I
* Status: YES
* Issue: Simple Math
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		int sum = 0;
		for(int i = 1; i < n; i++){
			if(n % i == 0 && i != n){
				sum += i;
			}

		}

		if(sum == n)
			cout << "perfect\n";
		else if(sum > n)
			cout << "abundant\n";
		else
			cout << "deficient\n";

	}

	return 0;
}
