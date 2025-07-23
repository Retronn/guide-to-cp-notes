#include<bits/stdc++.h>

using namespace std;



int main(){
    int n,m,k, ans=0;
    cin>>n>>m>>k;
    int desired[n], sizes[m];
    

    for(auto &x : desired) cin>>x;
    for(auto &x : sizes) cin>>x;

    sort(desired, desired+n);
    sort(sizes, sizes+m);

    int l=0, r=m-1;
    

    for(int i=0; i<n; i++)
    {

        if(sizes[l]-k>desired[i]) continue;

        

        while(l<=r && sizes[l]-k<desired[i] && abs(sizes[l]-desired[i])>k)
        {
            l++;
        }

        if(l>r)
        {
            break;
        }

        if(abs(sizes[l]-desired[i])<=k)
        {
            ans++;
            l++;
        }
}
cout<<ans;
}