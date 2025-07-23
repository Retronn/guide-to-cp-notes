#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> tasks(n);
    long long reward = 0, time_spent=0;

    for(auto &x:tasks) cin>>x.first>>x.second;
    sort(tasks.begin(), tasks.end());

    for(auto x:tasks)
    {
        time_spent+=x.first;
        reward+= (x.second - time_spent);
    }
    cout<<reward;
}

