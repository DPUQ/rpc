#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
vector<ll> b;
vector<ll> e;
int n;


ll maxCov[200005];

ll next(int i) {
    return upper_bound(b.begin(), b.end(), e[i]) - b.begin();
}

void calc() {
    maxCov[n] = 0;
    for (ll i = n - 1; i >= 0; --i) {
        maxCov[i] = max(e[i] - b[i] + 1 + maxCov[next(i)], maxCov[i + 1]);
    }
}

int main(){
	ll N;
	int k;
	cin >> N >> k;
	n = k;
	vector<ii> aux;
	for(int i = 0; i < k; i++){
		ii temp;
		cin >> temp.first;
		cin >> temp.second;
		aux.push_back(temp);
	}
	sort(aux.begin(), aux.end());
	for(int i = 0; i < k; i++){
		b.push_back(aux[i].first);
		e.push_back(aux[i].second);
	}
	calc();
	cout << (N - maxCov[0]) << endl;
	return 0;
}
