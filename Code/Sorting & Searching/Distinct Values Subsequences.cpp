#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    const int MOD = 1e9+7;
    cin>>n;
    vector<int> dup_cnt(n+1,0);
    vector<long long> dp(n+1,0);
    for(int i=1; i<=n; i++) 
    {
        int x;
        cin>>x;
        dp[i] = dp[i-1] + dp[i-1-dup_cnt[x]] + 1;
        dup_cnt[x]+=1;
        dp[i] %= MOD;
    }

    cout<<dp[n];
        
}

