#include<bits/stdc++.h>
using namespace std;        

int main(){
    int n,a,b;
    long long maxima = LONG_LONG_MIN, sum=0;
    cin>>n>>a>>b;
    multiset<long long> active_sums;
    vector<long long> prefix_sums(n+1);

    prefix_sums[0] = 0;

    

    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        sum+=(long long)x;
        prefix_sums[i] = sum;

    }

    int pnt_left = 0, pnt_right = a;
    
    while (pnt_right<=n)
    
    {
        int range = pnt_right - pnt_left;


        if(range>b)
        {
            auto it = active_sums.find(prefix_sums[pnt_left]);
            if(it!=active_sums.end())
            {
                active_sums.erase(it);
            }
            
            pnt_left++;
        }
        else{
            int ind_to_add =  (pnt_right-a);
            active_sums.insert(prefix_sums[ind_to_add]);
            maxima = max(maxima, (long long)(prefix_sums[pnt_right] - *active_sums.begin()));
            pnt_right++;
        }
    }

    cout<<maxima;
}

