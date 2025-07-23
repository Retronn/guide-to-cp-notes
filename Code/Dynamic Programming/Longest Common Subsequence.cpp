#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n,m;
   cin>>n>>m;

   vector<int> ar_1(n), ar_2(m);
   vector<vector<vector<int>>> 
   dp(n+1, vector<vector<int>>(m+1, {0,-1,-1,-1}));
   // 0 - cnt
   // 1 - x prev
   // 2 - y prev
   // 3 - number
    
   for(auto &x:ar_1) cin>>x;
   for(auto &x:ar_2) cin>>x;

   
   for(int i=1; i<=n; i++)
   {
    for(int j=1; j<=m; j++)
    {
        if(ar_1[i-1] != ar_2[j-1])
        {
            if(dp[i-1][j][0]>dp[i][j-1][0])
            {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
                dp[i][j][2] = dp[i-1][j][2];
                dp[i][j][3] = dp[i-1][j][3];
            }
            else{
                dp[i][j][0] = dp[i][j-1][0];
                dp[i][j][1] = dp[i][j-1][1];
                dp[i][j][2] = dp[i][j-1][2];
                dp[i][j][3] = dp[i][j-1][3];
            }
          
            
        }
        else{
            if(dp[i][j-1][0] > dp[i-1][j-1][0]+1)
            {
                dp[i][j][0] = dp[i][j-1][0];
                dp[i][j][1] = dp[i][j-1][1];
                dp[i][j][2] = dp[i][j-1][2];
                dp[i][j][3] = dp[i][j-1][3];
            }
            else{
                dp[i][j][0] = dp[i-1][j-1][0] + 1;
                dp[i][j][1] = i-1;
                dp[i][j][2] = j-1;
                dp[i][j][3] = ar_1[i-1];
            }

           
        }
    }
   }

   cout<<dp[n][m][0]<<endl;
   vector<int> ans;

   int i=n, j=m;

   while(dp[i][j][3]!=-1)
   {
    ans.push_back(dp[i][j][3]);
    int prev_i = i, prev_j = j;
    i = dp[prev_i][prev_j][1];
    j = dp[prev_i][prev_j][2];
   }

   for(int i = ans.size()-1; i>=0; i--)
   {
    cout<<ans[i]<<" ";
   }
}