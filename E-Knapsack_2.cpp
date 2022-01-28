// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
using namespace std;


int n;
lli cap;
vector<lli>price;
vector<lli>weight;
lli memo[110][100010];

lli knapsack(int idx, lli val){
    if (idx >= n)
        return val == 0? 0 : 1e14;

    if (memo[idx][val] != -1)
        return memo[idx][val];

    lli ret1 = 1e14, ret2 = 1e14;

    if (price[idx] <= val){
        ret1 = weight[idx] + knapsack(idx+1, val - price[idx]);
    }
    
    ret2 = knapsack(idx+1, val);

    memo[idx][val] =  min(ret1, ret2);
    return memo[idx][val];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    cin>>n>>cap;

    lli p, w;
    lli max_val = 0;
    for(int i=0; i<n; i++){
        cin>>w>>p;
        price.push_back(p);
        weight.push_back(w);
        max_val += p;
    }

    memset(memo, -1, sizeof(memo));
    lli ans;
    for(ans = max_val; ans >= 0; ans--){
        if(knapsack(0, ans) <= cap)
            break;
    }

    cout<<ans;
    
    return 0;
}