#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin>>n>>x;
    vector<int> values(n);
    for(auto &v:values) cin>>v;

    vector<long long> combinations(x+1);
    combinations[0] = 0;
    

    for(int i=1; i<=x; i++)
    {
        combinations[i] = LONG_LONG_MAX;   
        for(auto v:values)
        {
            if(i-v>=0 && combinations[i-v]!=LONG_LONG_MAX)
            {
                combinations[i] = min(combinations[i], combinations[i-v]+1);
            }
        }
    }

    if(combinations[x]!=LONG_LONG_MAX) cout<<combinations[x];
    else cout<<-1;
}