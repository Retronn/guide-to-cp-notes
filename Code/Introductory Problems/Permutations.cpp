#include<bits/stdc++.h>

using namespace std;



int main(){

int n;
cin>>n;
int border1 = (int)(n/2), border2=border1+1;
int pointer1 = 1, pointer2 = n;
if(n==1)
{
    cout<<"1";
}
else if(n<4){
    cout<<"NO SOLUTION";
}

else{

if(n%2==1){
    cout<<border2<<" ";
}
else{
    cout<<border1<<" ";
}
while(pointer1!=border1 && pointer2!=border2)
{
    cout<<pointer2<<" ";

    cout<<pointer1<<" ";

    pointer2-=1;
    pointer1+=1;
}
if(n%2==1)
{
    cout<<pointer2<<" ";
cout<<border1;
}
else{
    cout<<border2;
}
}

}

