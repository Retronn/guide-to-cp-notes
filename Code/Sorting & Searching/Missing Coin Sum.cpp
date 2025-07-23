#include<bits/stdc++.h>

using namespace std;



int main(){
    long long n, ans=0;
    cin>>n;
    vector<long long> coins(n);
    for(auto &x:coins) cin>>x;
    sort(coins.begin(), coins.end());

    long long cursum = 1;

    for(long long i=0; i<n; i++)
    {
        if(cursum>=coins[i])
        {
            cursum+=coins[i];
        }
        else break;
    }
    cout<<cursum;

    
}