#include<bits/stdc++.h>

using namespace std;


int CountZeros(long long n)
{
    if(n%5==0)
    {
        return 1+CountZeros(n/5);
    }
    return 0;
}

int main(){


long long n,ans=0;
cin>>n;

while(n%5!=0){
    n--;
}

while(n>1){
    ans+=CountZeros(n);
    n-=5;
}
cout<<ans;
}