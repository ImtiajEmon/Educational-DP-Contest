// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e5 + 10;
vector<vector<int>> adj(nmax); //adj list
int memo[nmax];

int solve(int x){
    if (memo[x] != -1) return memo[x];

    int ret = 0;
    for(auto y : adj[x]){
        ret = max(ret, solve(y) + 1);
    }

    return memo[x] = ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int N, M;
    cin>>N>>M;

    for(int i = 0; i < M; i++){
        int x, y;
        cin>>x>>y;

        // For directed
        adj[x].push_back(y);
    }

    memset(memo, -1, sizeof(memo));

    int ans = -1;
    for(int u = 1; u <= N; u++){
        ans = max(ans, solve(u));
    }

    cout<<ans<<endl;
    
    return 0;
}