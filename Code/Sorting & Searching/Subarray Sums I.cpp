#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;



int main(){
    int n, k, ans=0;
    cin>>n>>k;

    vector<int> numbers(n);
    for(auto &x:numbers) cin>>x;

    int left = 0, right=0;
    long long cur_sum;

    cur_sum = (long long)numbers[left];
    while (left!=n && right!=n)
    {
        if(cur_sum>(long long)k)
        {
            if(right==left)
            {
                cur_sum-=(long long)numbers[right];
                right++;
                left++;
                if(right==n) break;
                cur_sum+=(long long)numbers[right];
            }
            else{
                cur_sum-=(long long)numbers[left];
                left++;
            }
        }
        else
        {
            if(cur_sum==(long long)k) ans++;
            right++;
            if(right==n) break;
            cur_sum+=(long long)numbers[right];
        }
    }
    
    cout<<ans;
}

