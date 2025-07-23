#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;



int main(){
    int n;
    cin>>n;

    set<pair<int,int>> values;

    for(int i=1; i<=n; i++)
    {
        int value;
        cin>>value;

        auto it = values.lower_bound({value, INT_MIN});
        
        if(it==values.begin())
        {
            cout<<0<<" ";
        }
        else{
            --it;
            cout<<(*it).second<<" ";
        }

        values.insert({value,i});
        auto it_del = values.find({value,i});
        
        if(next(it_del)!=values.end())
        {
            it_del++;
            values.erase(it_del, values.end());
        }

    }

}

