#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int MOD = 1e9+7;

    int n, m;
    cin>>n>>m;
    vector<int> elements(n+2, 0);
    vector<vector<long long>> dp(n+1, vector<long long>(m+2,0));

    for(int i=1; i<=n; i++) cin>>elements[i];

    for(int i=1; i<=m; i++) dp[0][i] = 1;


    if(elements[1]==0)
    {
        for(int i=1; i<=m; i++) dp[1][i]+=1;
    }
    else{
        dp[1][elements[1]] = 1;
    }

    for(int i=2; i<=n; i++)
    {
        if(elements[i]!=0)
        {
            int v = elements[i];
            dp[i][v] += dp[i-1][v] + dp[i-1][v+1] + dp[i-1][v-1];
            dp[i][v]%=MOD;
        }
        else{
            for(int v=1; v<=m; v++)
            {
                dp[i][v] += dp[i-1][v] + dp[i-1][v+1] + dp[i-1][v-1];
                dp[i][v]%=MOD;
            }
        }
    }

    long long ans=0;

    for(auto num:dp[n]){
        ans+=num;
        ans%=MOD;
    }
    cout<<ans;


}