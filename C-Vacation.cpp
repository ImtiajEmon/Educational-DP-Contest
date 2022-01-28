// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;


const int nmax = 1e5 + 10;
int a[nmax], b[nmax], c[nmax];
int memo[nmax][3];

int dp(int i, int x){
    if(memo[i][x] != -1)
        return memo[i][x];


    if(i == 1){   // day 1
        if(x == 0) return a[1];
        else if(x == 1) return b[1];
        else if(x == 2) return c[1];
    }

    if(x == 0)
        memo[i][x] = max(dp(i-1, 1) + a[i], dp(i-1, 2) + a[i]);

    if(x == 1)
        memo[i][x] = max(dp(i-1, 0) + b[i], dp(i-1, 2) + b[i]);

    if(x == 2)
        memo[i][x] = max(dp(i-1, 0) + c[i], dp(i-1, 1) + c[i]);

    return memo[i][x];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n; cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    int x = dp(n, 0);
    int y = dp(n, 1);
    int z = dp(n, 2);

    int ans = max(x, y);
    ans = max(ans, z);

    cout<<ans<<endl;

    return 0;
}