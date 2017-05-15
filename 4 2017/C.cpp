/**
* Problem C: Cable Way
* Status: YES
* Issue: Next Greater Element
*/

#include<bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<ll, ll> ii;

ll dist[500005];
ll high[500005];
ll greatDer[500005];
ll greatIzq[500005];
ll n;

double dist_(ll x1, ll y1, ll x2, ll y2){
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) *(y2 - y1));
}

void sol(int i){
	int x1, x2, y1, y2;
	cout << greatIzq[i] << " " << greatDer[i] << " ";
	double dist1 = dist_(dist[i], high[i], dist[greatIzq[i]], high[greatIzq[i]]);
	double dist2 = dist_(dist[i], high[i], dist[greatDer[i]], high[greatDer[i]]);
	printf("%.4f %.4f\n", dist1, dist2);
}

void nextGreaterElementIzq(){
	ll next, element;
	ii pairElement;
	vector<ii> s;
	s.push_back(ii(n - 1, high[n - 1]));

	for(ll i = n; i >= 0; i--){
		next = high[i];
		while(!s.empty()){
			pairElement = s.back(); s.pop_back();
			element = pairElement.second;
			if(element < next){
				greatIzq[pairElement.first] = i;
			}else{
				s.push_back(pairElement);
				break;
			}
		}
		s.push_back(ii(i, next));
	}
}

void nextGreaterElementDer(){
	ll next, element;
	ii pairElement;
	vector<ii> s;
	s.push_back(ii(0, high[0]));

	for(ll i = 1; i < n + 2; i++){
		next = high[i];
		while(!s.empty()){
			pairElement = s.back(); s.pop_back();
			element = pairElement.second;
			if(element < next){
				greatDer[pairElement.first] = i;
			}else{
				s.push_back(pairElement);
				break;
			}
		}
		s.push_back(ii(i, next));
	}

}

int main(){

	ll d, h;

	cin >> n;

	for(ll i = 0; i < n + 2; i++)
		cin >> dist[i] >> high[i];

	nextGreaterElementDer();
	nextGreaterElementIzq();

	for(ll i = 1; i < n + 1; i++)
		sol(i);
	return 0;
}
