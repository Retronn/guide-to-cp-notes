#include<bits/stdc++.h>

using namespace std;



int main(){

string a;
cin>>a;
int maxx=0, sum=0;

for(int i=0; i<a.length()-1; i++)
{
    if(a[i]==a[i+1])
    {
        sum+=1;
    }
    else{
        maxx = max(maxx, sum);
        sum=0;
    }
    if(i==a.length()-2)
    {
maxx = max(maxx, sum);
    }
}
cout<<maxx+1;
}