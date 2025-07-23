#include<bits/stdc++.h>

using namespace std;



int main(){

int n;
cin>>n;


for(int i=1; i<=n; i++)
{
if(i==1)
{
    cout<<"0\n";
}
else{
    cout<< i*i*(i*i-1)/2 - 4*(i-2)*(i-1)<<"\n";
}

}

