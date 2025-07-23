#include<bits/stdc++.h>

using namespace std;



int main(){
    int n, k;
    cin>>n>>k;

    vector<int> values(n), copy(n);
    
    for(int i=0; i<n; i++)
    {
        cin>>values[i];
        copy[i] = values[i];
    }
if(n==1)
{

cout<<"IMPOSSIBLE";

    return 0;
}
    
    sort(values.begin(), values.end());

    int l=0, r=n-1, num1,num2;

    while(l+1!=r && values[r]+values[l]!=k)
    {
        if(values[r]+values[l]>k)
        {
            r--;
        }
        else{
            l++;
        }
    }
    if(values[r]+values[l]!=k)
    {
        cout<<"IMPOSSIBLE";
    }
    else{
        num1=values[l];
        num2=values[r];

        for(int i=0; i<n; i++)
        {
            if(copy[i]==num1)
            {
                cout<<i+1<<" ";
                num1=-1;
            }
            else if(copy[i]==num2)
            {
                cout<<i+1<<" ";
                num2=-1;
            }
        }
    }
}

