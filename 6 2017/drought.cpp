/**
* Problem D: Drought In Nlogonia
* Status: YES
* Issue: Next Greater Element, Segment tree
*/

#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << #x << " = " << x << endl;
typedef pair<int, int> ii;
typedef long long ll;
const int N = 1e4 + 100;

int A[N];
int M[50000], greatDer[N];
void initialize(int node, int b, int e){
      if (b == e)
          M[node] = b;
      else{
          initialize(2 * node, b, (b + e) / 2);
          initialize(2 * node + 1, (b + e) / 2 + 1, e);
  
          if (A[M[2 * node]] >= A[M[2 * node + 1]])
              M[node] = M[2 * node];
          else
              M[node] = M[2 * node + 1]; 
      }
  } 

int query(int node, int b, int e, int i, int j){
      int p1, p2;

      if (i > e || j < b)
          return -1;
   
 
      if (b >= i && e <= j)
          return M[node];
   
  
      p1 = query(2 * node, b, (b + e) / 2, i, j);
      p2 = query(2 * node + 1, (b + e) / 2 + 1, e, i, j);
   
  
      if (p1 == -1)
          return M[node] = p2;
      if (p2 == -1)
          return M[node] = p1;
      if (A[p1] >= A[p2])
          return M[node] = p1;
      return M[node] = p2;
  }


void nextGreaterElementDer(int n){
	ll next, element;
	ii pairElement;
	vector<ii> s;
	s.push_back(ii(0, A[0]));

	for(ll i = 1; i < n + 1; i++){
		next = A[i];
		while(!s.empty()){
			pairElement = s.back(); s.pop_back();
			element = pairElement.second;
			if(element <= next){
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

	int t, n, a, x[N], h[N], index;
	long long res,less, sum[N];

	cin >> t;

	while(t--){

		cin >> a >> n;
		res = 0;
		for(int i = 0; i < n; i++)
			cin >> x[i];

		sum[0] = 0;
		for(int i = 0; i < n + 1; i++){
			cin >> A[i];
			if(i != 0)
				sum[i] = sum[i - 1] + x[i - 1];
		}
		nextGreaterElementDer(n);
		initialize(1, 0, n);
		for(int i = 0; i < n; i++){
			index = query(1, 0, n, i + 1, n);
			if(A[index] >= A[i]){
				index = greatDer[i];
			}
			res += (min(A[i], A[index]) * (sum[index] - sum[i]));
			i = index - 1;
		}
		res *= a;
		cout << res << endl; 

	}
	return 0;
}
