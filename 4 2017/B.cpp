/**
* Problem B: Balloons
* Status: YES
* Issue: Trivial
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	int n, b;

	while(cin >> n >> b && n + b){
		int sum = 0;
		for(int i = 0; i < n; i++){
			int temp;
			cin >> temp;
			sum += temp;
		}
		cout << (int)(b / sum) << endl;
	}

	return 0;
}
