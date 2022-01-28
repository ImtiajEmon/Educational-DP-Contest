// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
using namespace std;


int n;
vector<lli>price;
vector<int>weight;
lli memo[110][100000 + 10];

lli knapsack(int idx, int remain_cap){
    if (idx >= n)
        return 0;

    if (memo[idx][remain_cap] != -1)
        return memo[idx][remain_cap];

    lli ret1 = 0, ret2 = 0;

    if (weight[idx] <= remain_cap)
        ret1 = price[idx] + knapsack(idx+1, remain_cap - weight[idx]);
    
    ret2 = knapsack(idx+1, remain_cap);

    memo[idx][remain_cap] =  max(ret1, ret2);
    return memo[idx][remain_cap];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int cap;
    cin>>n>>cap;

    lli p; int w;
    for(int i=0; i<n; i++){
        cin>>w>>p;
        price.push_back(p);
        weight.push_back(w);
    }

    memset(memo, -1, sizeof(memo));
    lli ans = knapsack(0, cap);
    cout<<ans;
    
    return 0;
}