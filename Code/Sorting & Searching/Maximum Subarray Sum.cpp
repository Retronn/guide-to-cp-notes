#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    long long sum=0L, maxsum=LLONG_MIN;
    cin>>n;
    vector<int> nums(n);
    for(auto &x:nums) 
    
    {
        cin>>x;

        sum+=(long long)(x);

        maxsum=max(sum,maxsum);

        if(sum<0) sum=0;
    }


    cout<<maxsum;
}