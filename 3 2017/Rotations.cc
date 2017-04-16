#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
int main(){

	int t;
	cin >> t;

	while(t--){
		int valid[32], binValues[5];
		bitset<32> bits_;
		for(int i = 0; i < 32; i++){
			bits_[i] = 0;
			valid[i] = 0;
		}
		long long n;
		cin >> n;
		for(int i = 0; i < 5; i++)
			binValues[i] = 1 << i;
		for(long i = 0; i < 32; i++)
			bits_[i] = (n & (1 << i)) != 0;

		int cont = 0, pos;
		long sum;
		for(int i = 0; i < 32; i++){
			sum = 0;
			for(int j = 0; j < 5; j++){
				pos = (i + j) % 32;
				if(bits_[pos] == 1)
					sum += binValues[j];
			}
			if(valid[sum] == 0){
				valid[sum] = 1;
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