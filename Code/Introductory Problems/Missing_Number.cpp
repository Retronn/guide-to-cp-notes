#include<bits/stdc++.h>

using namespace std;



int main(){

int n,a,b, sum=0;
cin>>n;
b=n;
while(n!=0)
{
    sum+=n;
    n--;
}

for(int i=0; i<b-1; i++){
    cin>>a;
    sum-=a;
}

cout<<sum;
}