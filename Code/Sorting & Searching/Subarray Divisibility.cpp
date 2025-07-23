#include<bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
 
 
int main(){
    long long n, k, ans=0, prefix_sum=0;
    cin>>n;
    k=n;
    map<long long,int> rem_counts;
    vector<long long> numbers(n);

    rem_counts[0]= 1;
    for(auto &x:numbers)
    {
        cin>>x;
        long long remainder = x%k;
        if(remainder<0) remainder+=k;
        prefix_sum = (prefix_sum+remainder)%k;

        if(rem_counts.count(prefix_sum)>0) 
        {
            ans+=rem_counts[prefix_sum];
            rem_counts[prefix_sum] +=1;
        }
        else rem_counts[prefix_sum] = 1;
        
    }
    cout<<ans;
 
}
