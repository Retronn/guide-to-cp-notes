#include<bits/stdc++.h>

using namespace std;



int main(){

const long long mod = 1e9+7;
long long n,ans=1LL;
cin>>n;


while(n!=0)
{
    ans = ans * 2 % mod;
    n-=1;
}
cout<<ans<<endl;
}