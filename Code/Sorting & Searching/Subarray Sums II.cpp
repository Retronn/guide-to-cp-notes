#include<bits/stdc++.h>
 
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
 
 
int main(){
    long long n, k, ans=0, prefix_sum=0;
    cin>>n>>k;
    map<long long,int> prefix_counts;
    vector<long long> numbers(n);
    prefix_counts[0]= 1;
    for(auto &x:numbers)
    {
        cin>>x;
        prefix_sum+=x;
        long long sum_left = prefix_sum -k;
        if(prefix_counts.count(sum_left)>0) ans+=prefix_counts[sum_left];
        if(prefix_counts.count(prefix_sum)>0) prefix_counts[prefix_sum] +=1;
        else prefix_counts[prefix_sum] = 1;
    }
    cout<<ans;
 
}
