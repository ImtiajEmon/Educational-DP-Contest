// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

int k;
const int nmax = 1e5 + 10;
int height[nmax];
int memo[nmax];

//it return the cost of going to stone i from stone 1
int dp(int i){
    if (memo[i] != -1)
        return memo[i];
        
    if (i == 1)
        return 0;

    int MIN = 1e9;
    //This loop calculate the minimum within all possible(i-k) candidates
    for(int j = max(i-k, 1); j < i; j++){
        int cand = dp(j) + abs(height[i] - height[j]);
        MIN = min(MIN, cand);
    }

    memo[i] = MIN;
    return memo[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    int n;
    cin>>n>>k;

    for(int i = 1; i <= n; i++){
        cin>>height[i];
    }

    int ans = dp(n);
    cout<<ans<<endl;

    return 0;
}