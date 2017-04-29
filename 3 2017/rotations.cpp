/**
* Problem L: Rotations
* Status: YES
* Issue: Ad-hoc, Bitwise
*/

#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
int main(){

	int t;
	cin >> t;
	vector<bool> valid;

	while(t--){
        int binValues[5];
		valid.assign(32,0);
		long long n;
		cin >> n;
		bitset<32> bits_(n);
		for(int i = 0; i < 5; i++)
			binValues[i] = 1 << i;

		int cont = 0, pos;
		long sum;
		for(int i = 0; i < 32; i++){
			sum = 0;
			for(int j = 0; j < 5; j++){
				pos = (i + j) % 32;
				if(bits_[pos] == 1)
					sum += binValues[j];
			}
			if(!valid[sum]){
				valid[sum] = true;
				cont++;
			}
		}
		if(cont == 32)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

	}

	return 0;
}
