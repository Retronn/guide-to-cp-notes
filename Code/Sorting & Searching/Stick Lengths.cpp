#include<bits/stdc++.h>

using namespace std;



int main(){
    long long n, ans=0;
    cin>>n;
    vector<long long> strings(n);
    for(auto &x:strings) cin>>x;
    sort(strings.begin(), strings.end());

    long long mid = strings[(long long)((n-1)/2)];

    for(long long i=0; i<n; i++)
    {
        ans+=abs(strings[i]-mid);
    }
    cout<<ans;

    
}