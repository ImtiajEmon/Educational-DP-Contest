// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 1e5 + 10;
int height[nmax];
int memo[nmax];

//it return the cost of going to stone i from stone 1
int dp(int i){
    if (memo[i] != -1)
        return memo[i];
        
    if (i == 1)
        return 0;

    //int ans = min((dp(max(i-1, 1)) + abs(height[i] - height[i-1])),
    //(dp(max(i-2, 1)) + abs(height[i] - height[i-2]))); #[line 23 to 27]

    int j = max(i-1, 1);
    int ans = dp(j) + abs(height[i] - height[j]);

    j = max(i-2, 1);
    ans = min(ans, dp(j) + abs(height[i] - height[j]));

    memo[i] = ans;
    return memo[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n, h;
    cin>>n;

    for(int i = 1; i <= n; i++){
        cin>>height[i];
    }

    int ans = dp(n);
    cout<<ans<<endl;

    return 0;
}