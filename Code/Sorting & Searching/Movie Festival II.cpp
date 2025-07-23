#include<bits/stdc++.h>

using namespace std;


    bool cmp(pair<int,int> a, pair<int,int> b) {
        if(a.second!=b.second) return a.second<b.second;
        return a.first<b.first;
    }
    
int main(){
    int n, k, ans=0;
    cin>>n>>k;
    vector<pair<int,int>> movies(n);
    multiset<int> endings;
    for(auto &x:movies)
    {
        cin>>x.first>>x.second;
    }

    sort(movies.begin(), movies.end(), cmp);

    for(auto x:movies)
    {
        auto it_nearest = endings.upper_bound(x.first);
        if(it_nearest!=endings.begin() && x.first>=*prev(it_nearest))
        {
            --it_nearest;
            endings.erase(it_nearest);
            endings.insert(x.second);
            ans++;
        }
        else if(k!=0)
        {
            k--;
            endings.insert(x.second);
            ans++;
        }
    }
    cout<<ans;
}

