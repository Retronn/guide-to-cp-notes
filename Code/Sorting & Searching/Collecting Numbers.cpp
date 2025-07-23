#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;
    int ans=0,  maxnum=INT_MIN;
    vector<int> numbers(n), positions(n+1);
    for(int i=0; i<n; i++) 
    {
        cin>>numbers[i];
        positions[numbers[i]] = i;
    }

    for(int i=1; i<=n; i++) 
    {
        if(i==n)
        {
            ans++;

        }
        if(positions[i]<maxnum)
        {   
            ans++;
        }
        
        maxnum=positions[i];
    }

    cout<<ans;
    
}