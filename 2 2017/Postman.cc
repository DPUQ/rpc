#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;

bool wayToSort(ii i, ii j) { return i.first > j.first; };

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<ii> vn;
	vector<ii> vp;
	ii curr;
	int n;
	ll k, curr1, curr2, ktemp;
	int j = 0;

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> curr1 >> curr2;
		if(curr1 < 0)
			vn.push_back(ii(-curr1, curr2));
		else
			vp.push_back(ii(curr1, curr2));
	}
	ll resn = 0, resp = 0;
	ll times;
	sort(vn.begin(), vn.end(), wayToSort);
	sort(vp.begin(), vp.end(), wayToSort);

	for(int i = 0; i < vp.size(); i++){
		curr = vp[i];
		if(curr.second == 0) continue;
		ktemp = k;
		if(curr.second <= k)
			times = 1;
		else
			times = curr.second % k == 0 ? curr.second / k : curr.second / k + 1;
		resn += times * 2 * curr.first;
		ktemp = (times * k) - curr.second;
		j = i + 1;
		while(ktemp > 0 && j < vp.size()){
			if(vp[j].second >= ktemp){
				vp[j].second -= ktemp;
				ktemp = 0;
			}else{
				ktemp -= vp[j].second;
				vp[j].second = 0;
			}
			j++;
		}
	}

	for(int i = 0; i < vn.size(); i++){
		curr = vn[i];
		if(curr.second == 0) continue;
		ktemp = k;
		if(curr.second <= k)
			times = 1;
		else
			times = curr.second % k == 0 ? curr.second / k : curr.second / k + 1;
		resn += times * 2 * curr.first;
		ktemp = (times * k) - curr.second;
		j = i + 1;
		while(ktemp > 0 && j < vn.size()){
			if(vn[j].second >= ktemp){
				vn[j].second -= ktemp;
				ktemp = 0;
			}else{
				ktemp -= vn[j].second;
				vn[j].second = 0;
			}
			j++;
		}
	}
	ll res = resn + resp;
	cout << res << "\n";
	return 0;
}