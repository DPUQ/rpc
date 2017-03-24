#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> VI;
typedef vector<VI> VVI;

int n, m;
string matriz[50];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);

  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

void floodfill(int i, int j){
	if(i >= 0 && i < n && j >= 0 && j < m){
		if(matriz[i][j] == 'L'){
			matriz[i][j] = '*';
			floodfill(i + 1, j);
			floodfill(i - 1, j);
			floodfill(i, j + 1);
			floodfill(i, j - 1);
		}
		matriz[i][j] = '*';
	}
	else
		return;
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> matriz[i];
	}
	int cont = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matriz[i][j] == 'L'){
				cont++;
				floodfill(i, j);
			}
		}
	}
	
	int id = 0;
	int ni, nj, u, v;
	map<ii, int> mapa;
	VVI w(n * m, VI(n * m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(matriz[i][j] == 'C'){
				ii temp_ = ii(i, j);
				if(mapa.find(temp_) == mapa.end())
					mapa[temp_] = u = id++;
				else
					u = mapa[temp_];
				for(int k = 0; k < 4; k++){
					ni = i + dx[k];
					nj = j + dy[k];
					if(ni >= 0 && ni < n && nj >= 0 && nj < m && matriz[ni][nj] == 'C'){
						ii temp = make_pair(ni, nj);
						if(mapa.find(temp) == mapa.end()){
							mapa[temp] = v = id++;
						}else{
							v = mapa[temp];
						}
						w[u][v] = 1;
					}

				}
			}
		}
	}
	
	VI mr;
    VI mc;
    int res=BipartiteMatching(w,mr,mc);

    cout << cont + (id - res / 2) << endl;
	return 0;
}
