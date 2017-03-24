#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
const int N = 2e5+10;
long long t[2 * N], n;

void build() {
	for (int i = n - 1; i > 0; --i) t[i] = min(t[i<<1], t[i<<1|1]);
}

long long query(long long l, long long r) {
	long long res = LONG_LONG_MAX;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = min(res, t[l++]);
		if (r&1) res = min(res, t[--r]);
	}
	return res;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ofstream cou("output.o");
	long long q, indexleft, indexrigth, midpoint;
	long long p, l, r;
	cin >> n >> q;
	for (long long i = 0; i < n; i++)
		cin >> t[n + i];
	build();

	while(q--){
		cin >> p >> l >> r;
		l--; r--;

		while(l <= r){
			indexleft = l;
			indexrigth = r + 1;
			while(indexleft < indexrigth){
				midpoint = (indexrigth + indexleft) / 2;
				long long rmq_ = query(l, midpoint + 1);
				if(rmq_ > p){
					indexleft = midpoint + 1;
				}else{
					indexrigth = midpoint;
				}
			}
			if(indexleft <= r){
				p = p % t[n + indexleft];
				l = indexleft + 1;
			}else{
				break;
			}
		}
		cout << p << endl;
	}

	return 0;
}