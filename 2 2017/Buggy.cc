#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

string matriz[55];
string func;
int seen[55][55][55];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
int n, m;

struct point{
	ii pos;
	int c;
	int free;
};

bool isValid(int i, int j, int c, int valor){
	if(i >= 0 && i < n && j >= 0 && j < m && matriz[i][j] != '#')
		if(valor < seen[i][j][c]){
			seen[i][j][c] = valor;
			return 1;
		}
	return 0;
}

int res = 60000;

void bfs(point p){
	queue<point> q;
	q.push(p);
	seen[p.pos.first][p.pos.second][0] = 1;
	while(!q.empty()){
		point curr = q.front(); q.pop();
		if(matriz[curr.pos.first][curr.pos.second] == 'E'){
			res = min(res, curr.c);
		}
		int ni, nj;
		if(curr.free < func.length()){
			if(func[curr.free] == 'R'){
				ni = curr.pos.first;
				nj = curr.pos.second + 1;
				if(nj >= m || matriz[ni][nj] == '#')
					nj--;
			}else if(func[curr.free] == 'L'){
				ni = curr.pos.first;
				nj = curr.pos.second - 1;
				if(nj < 0 || matriz[ni][nj] == '#')
					nj++;
			}else if(func[curr.free] == 'U'){
				ni = curr.pos.first - 1;
				nj = curr.pos.second;
				if(ni < 0 || matriz[ni][nj] == '#')
					ni++;
			}else{
				ni = curr.pos.first + 1;
				nj = curr.pos.second;
				if(ni >= n || matriz[ni][nj] == '#')
					ni--;
			}	
			if(isValid(ni, nj, curr.free + 1, curr. c)){
 				point temp = {ii(ni, nj), curr.c, curr.free + 1};
				q.push(temp);
			}
			if(isValid(curr.pos.first, curr.pos.second, curr.free + 1, curr.c + 1)){
				point aux = {ii(curr.pos.first, curr.pos.second), curr.c + 1, curr.free + 1};
				q.push(aux);
			}
		}
		for(int i = 0; i < 4; i++){
			ni = curr.pos.first + dx[i];
			nj = curr.pos.second + dy[i];
			if(isValid(ni, nj, curr.free, curr.c + 1)){
				point temp = {ii(ni, nj), curr.c + 1, curr.free};
				q.push(temp);
			}
		}
	}

}

int main(){
	cin >> n >> m;
	for(int i = 0; i < 55; i++)
		for(int j = 0; j < 55; j++)
			for(int k = 0; k < 55; k++)
				seen[i][j][k] = 60000;
	for(int i = 0; i < n; i++)
		cin >> matriz[i];
	cin >> func;
	point p;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(matriz[i][j] == 'R'){
				p.pos = ii(i, j);
				p.c = 0;
				p.free = 0;
			}
	bfs(p);
	cout << res << endl;
	return 0;
}