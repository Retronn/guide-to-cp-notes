#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n=1e6, MOD=1e9+7;
    cin>>t;

    vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    
    vector<int> task(t);

    for(auto &x:task)
    {
        cin>>x;
    }

    for(int i=2; i<=n; i++)
    {
      dp[i][0] = (dp[i-1][0] *2 + dp[i-1][1])%MOD;
      dp[i][1] = (dp[i-1][0] + 4*dp[i-1][1])%MOD;
    }

    for(auto n:task)
    {
        cout<<(dp[n][0]+dp[n][1])%MOD<<endl;
    }
}