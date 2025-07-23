#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k, pnt=0;
    long long cur_sum = 0;
    cin>>n>>k;
    vector<int> numbers(n);
    multiset<long long> sums;
    long long minK = 0, maxK = 0, mid;

    for(auto &x:numbers){
        cin>>x;
        maxK+=x;
    }
 
    
 
 
    while (minK!=maxK-1)
    {
        mid = (long long)((minK+maxK)/2);
        cur_sum = 0;
        int cnt = 1;
        
        for(auto x:numbers)
        {
            if(cur_sum == 0 )
            {
                cur_sum = x;
                if(cur_sum>mid)
                {
                    cnt = INT_MAX;
                    break;
                }
                continue;
            }
            if(cur_sum + x <= mid)
            {
                cur_sum+=x;
            }
            else{
                cur_sum = x;
                if(cur_sum>mid)
                {
                    cnt = INT_MAX;
                    break;
                }
                cnt++;
            }
        }
 
        if(cnt<=k)
        {
            maxK = mid;
        }
        else{
            minK = mid;
        }
 
    }
    
    cout<<maxK;
   
}
