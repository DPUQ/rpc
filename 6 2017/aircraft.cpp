/**
* Problem C: AirCraft: Monster
* Status: YES
* Issue: Brute-force, Bitmask
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> ii;
typedef pair<long long, ii> iii;
long long x, a, b;
long long xsum, asum, bsum;
vector<iii> v;

struct greater_
{
    template<class iii>
    bool operator()(iii const &a, iii const &b) const {
    	if(a.first != b.first)
    		return a.first < b.first;
    	if(a.second.first != b.second.first)
    		return a.second.first < b.second.first;
    	return a.second.second < b.second.second; 
    }
};

bool sol(long long ax[50], long long aa[50], long long ab[50], int m, bool o){

	for(int i = 0; i < (1 << m); i++){
			xsum = asum = 0;
			bsum = 0;
			int j;
			for(j = 0; j < m; j++){
				if(i & (1 << j)){
					xsum += ax[j];
					asum += aa[j];
					bsum += ab[j];
					if(xsum > x || asum > a || bsum > b)
						break;
				}
			}
			if(o){
				if(j == m){
					v.push_back(iii(xsum, ii(asum, bsum)));
				}
			}else{
				if(binary_search(v.begin(), v.end(), iii(x - xsum, ii(a - asum, b - bsum)))){
					return true;
				}
				
			}

	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	long long ax[50], aa[50], ab[50], m;
	bool flag;
	string des;
	cin >> t;

	while(t--){
		v.clear();
		cin >> x >> a >> b >> m;
		int mid = ceil((double)m * 0.5);
		for(int i = 0; i < mid; i++){
			cin >> des >> ax[i] >> aa[i] >> ab[i];
		}
		sol(ax, aa, ab, mid, true);
		sort(v.begin(), v.end(), greater_());
		int j = 0;
		for(int i = mid; i < m; i++){
			cin >> des >> ax[j] >> aa[j] >> ab[j];
			j++;
		}
		flag = sol(ax, aa, ab, m - mid, false);

		if(flag)
			cout << "POSSIBLE" << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}
