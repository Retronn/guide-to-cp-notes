#include<bits/stdc++.h>

using namespace std;



int main(){
    int n, largest = INT_MIN;
    cin>>n;
    vector<int> cubes(n);
    multiset<int> towers;
    
    
    for(auto &x:cubes) cin>>x;

    towers.insert(cubes[0]);


    for(int i=1; i<n; i++)
    {
        auto it = towers.upper_bound(cubes[i]);
        if(it == towers.end())
        {
            towers.insert(cubes[i]);
        }
        else{
            towers.erase(it);
            towers.insert(cubes[i]);
        }
    }

    cout<<towers.size();
}

