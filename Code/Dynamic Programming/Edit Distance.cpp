#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word_1, word_2;
    

    cin>>word_1>>word_2;
    vector<vector<int>> dp(word_1.size() + 1, vector<int>(word_2.size() +1,0));

    
    for(int i=0; i<=word_1.size(); i++)
    {
        for(int j=0; j<=word_2.size(); j++)
        {
            if(i==0)
            {
                dp[i][j] = j-i;
            }
            else if(j==0)
            {
                dp[i][j] = i;
            }
            else if(word_1[i-1]!=word_2[j-1]){
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1],dp[i-1][j])) + 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    cout<<dp[word_1.size()][word_2.size()];
}