/**
* Problem K: King of music
* Status: YES
* Issue: Range Minimax (Sliding Window)
*/

#include<bits/stdc++.h>
#define MAX 1000000

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
vi input(MAX);

vi sliding_window(int n, int w,bool isMin)
{
    deque<ii> window;
    vi res;
    for (int i = 0; i < n; i++)
    {
        if(isMin)
        {
            while (!window.empty() && window.back().first >= input[i])
                window.pop_back();
        }
        else
        {
            while (!window.empty() && window.back().first <= input[i])
                window.pop_back();
        }

        window.push_back(ii(input[i], i));

        while(window.front().second <= i - w)
            window.pop_front();

        res.push_back(window.front().first);
    }

    return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n,w,k;
    vi s_min,s_max;
    bool res;

    while(cin >> n >> w >> k && (n + w + k))
    {
        res = true;
        for(int i = 0; i<n; i++)
            cin >> input[i];

        s_min = sliding_window(n,w,true);
        s_max = sliding_window(n,w,false);

        for(int i = w; i<n && res; i++)
            if(input[i] - s_min[i-1] > k || s_max[i-1] - input[i] > k)
                res = false;

        res? cout << "Yes.\n" : cout << "No.\n";

    }

    return 0;
}
