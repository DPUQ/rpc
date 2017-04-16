#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, int> ii;
int main(){
	

	int t;
	int n, k, f;
	cin >> t;
	while(t--){
		cin >> n >> k;
		string names[3000];
		int freq[3000];
		priority_queue<ii, deque<ii>, greater<ii> > pq;
		for(int i = 0; i < n; i++){
			cin >> names[i] >> f;
			freq[i] = f;
			pq.push(ii(f, i));
		}

		while(k--){
			ii curr = pq.top(); pq.pop();
			cout << curr.first << " " << names[curr.second] << endl;
			pq.push(ii(curr.first + freq[curr.second], curr.second));
		}

	}

	return 0;
}
