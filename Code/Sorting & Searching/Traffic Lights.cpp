#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);     
    int n,m;
    cin>>n>>m;
    set<int> road;
    multiset<int> differences;

    road.insert(0);
    road.insert(n);
    differences.insert(n);

    for(int i=0; i<m; i++)
    {
        int traffic_light, difference, new_dif1, new_dif2;
        cin>>traffic_light;

        road.insert(traffic_light);

        auto it = road.find(traffic_light);
        auto it_bef = prev(it);
        auto it_aft = next(it);

        difference = *it_aft - *it_bef;

        new_dif1 = *it_aft - *it;
        new_dif2 = *it - *it_bef;

        auto dif_it = differences.find(difference);
        differences.erase(dif_it);

        differences.insert(new_dif1);
        differences.insert(new_dif2);
        
        auto ans = differences.end();
        --ans;
        cout<<*ans<<" ";
    }
}

