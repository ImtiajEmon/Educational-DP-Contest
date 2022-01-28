// Author: IMTIAJ
#include<bits/stdc++.h>
#define endl "\n"
#define lli long long int
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int nmax = 3000 + 5;
string s, t;

int memo[nmax][nmax];
int link[nmax][nmax];
int ans;

int dp(int x, int y){
    if (memo[x][y] != -1)
        return memo[x][y];

    if (x == 0 || y == 0)
        return 0;
    
    if (dp(x-1, y) > dp(x, y-1)){
        ans = dp(x-1, y);
        link[x][y] = 1;
    }

    else{
        ans = dp(x, y-1);
        link[x][y] = 2;
    }

    if(s[x-1] == t[y-1] && dp(x-1, y-1) + 1 > ans){
        ans = dp(x-1, y-1) + 1;
        link[x][y] = 3;
    }

    memo[x][y] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    memset(memo, -1, sizeof(memo));

    cin>>s>>t;

    dp(s.size(), t.size());

    int x = s.size();
    int y = t.size();

    string ans;

    while(x != 0 && y != 0){
        if (link[x][y] == 1)
            x--;

        else if (link[x][y] == 2)
            y--;

        else{
            ans += s[x-1]; // or ans += t[y-1]
            x--;
            y--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
    
    return 0;
}