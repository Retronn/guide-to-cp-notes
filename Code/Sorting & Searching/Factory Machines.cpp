#include<bits/stdc++.h>

using namespace std;


int main(){
    long long n, k;
    cin>>n>>k;

    vector<long long> efficiencies(n);

    for(auto &x:efficiencies) cin>>x;

    sort(efficiencies.begin(), efficiencies.end());

    long long l=1, r=efficiencies[0]*k, mid;

    if(l==r){
        cout<<l;
        return 0;
    }

    while(l!=r-1)
    {
        mid = (long long) ((r+l)/2);

        long long details = 0;
        for(long long i=0; i<n; i++)
        {
            details += (long long)(mid/efficiencies[i]);
        }

        if(details>=k) r=mid;
        else l=mid;
    }

    long long details_l = 0;

    for(long long i=0; i<n; i++)
        {
            details_l += (long long)(l/efficiencies[i]);
        }
    if(details_l>=k) cout<<l;
    else cout<<r;
}

