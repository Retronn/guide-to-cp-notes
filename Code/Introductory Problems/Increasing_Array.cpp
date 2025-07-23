#include<bits/stdc++.h>

using namespace std;



int main(){

long long n, top=-1, ans=0;
cin>>n;
long long arr[n];
for(long long i=0; i<n; i++) 
{

    cin>>arr[i];

    if(arr[i]<top)
    {
        ans+= top-arr[i];
    }
    else top=arr[i];

}

cout<<ans;
}