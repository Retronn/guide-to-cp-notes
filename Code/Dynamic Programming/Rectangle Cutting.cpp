#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    int a,b;
    cin>>a>>b;
    vector<vector<int>> dp(max(a,b)+1, vector<int>(max(a,b)+1, INT_MAX));



    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {

            if(i!=j){
                for(int k=1; k<=(int)(i/2); k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
                }

                for(int k=1; k<=(int)(j/2); k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]+1);
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    cout<<dp[a][b];
}