#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    const int MOD = 1e9+7;
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<long long>> ways(n, vector<long long>(n, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>grid[i][j];
        }
    }
    if(grid[0][0]!='*') ways[0][0] = 1;
    

    for(int i=0; i<n; i++)
    {
        
        for(int j=0; j<n; j++)
        {
            if(grid[i][j]!='*')
            {
                if(i-1>=0)
                {
                    ways[i][j] += ways[i-1][j];
                }
                
                if(j-1>=0)
                {
                    ways[i][j] += ways[i][j-1];
                }
                
                if(i+1<n)
                {
                    ways[i][j] += ways[i+1][j];
                }

                if(j+1<n)
                {
                    ways[i][j] += ways[i][j+1];
                }
                ways[i][j]%=MOD;
            }
            
        }
    }
    
    cout<<ways[n-1][n-1];

}