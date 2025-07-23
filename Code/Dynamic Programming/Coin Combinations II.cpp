#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int MOD = 1e9 +7;
    int n, x;
    cin>>n>>x;
    vector<int> values(n);
    for(auto &v:values) cin>>v;
    sort(values.rbegin(), values.rend());

    vector<long long> combinations(x+1, 0);
    combinations[0] = 1;
    for(auto v:values)
    {
    for(int i=1; i<=x; i++)
    {
        if(i-v>=0 && combinations[i-v]!=0)
        {
                combinations[i] += combinations[i-v];
                combinations[i] %= MOD;
            }
    }
    }
    cout<<combinations[x];
}