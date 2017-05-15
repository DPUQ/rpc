/**
* Problem H: Hidden card trick
* Status: YES
* Issue: Josephus Problem
*/

#include<bits/stdc++.h>
using namespace std;
unsigned long long n;

string toBin(){
	int divisor = 2;
	int rest;
	stringstream stream;
	while(n >= divisor){
   		rest = n % 2;
   		stream << rest;
   		n = n/divisor;
  	}
  	string s;
  	stream >> s;
  	return s;
}

int main(){

	while(cin >> n && n){

		string bin = toBin();
		unsigned long long res = 1;
		int pot = bin.length();
		for(int i = bin.length() - 1; i >= 0; i--){
			if(bin[i] == '1')
				res += ((long long)1 << pot);
			pot--;
		}
		cout << res << endl;
	}

}
