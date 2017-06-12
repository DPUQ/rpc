/**
* Problem G: Geonosis
* Status: YES
* Issue: Graph (Shortest path)
*/

#include<bits/stdc++.h>
using namespace std;
#define INF 1e5
int n;
int dist[550][550];

int toDestroy[550];
long res, temp;
void floydWarshall(){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[toDestroy[i]][toDestroy[j]] = min(dist[toDestroy[i]][toDestroy[j]],
				 dist[toDestroy[i]][toDestroy[k]] + dist[toDestroy[k]][toDestroy[j]]);
			}
		}
		for(int i = 0; i <= k; i++)
			for(int j = 0; j <= k; j++)
					res += dist[toDestroy[i]][toDestroy[j]];
	}
	cout << res << endl;
}

int main(){
	int t, curr;
	cin >> t;
	while(t--){
			res = 0;
			cin >> n;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					cin >> dist[i][j];
					if(i == j){
						dist[i][j] = 0;
					}
				}
			}
			for(int i = n - 1; i >= 0; i--)
				cin >> toDestroy[i];
			floydWarshall();
	}

	return 0;
}