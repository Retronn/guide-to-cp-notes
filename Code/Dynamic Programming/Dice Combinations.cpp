#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> values = {1,2,3,4,5,6};
    vector<long long> combinations(n+1, 0);
    combinations[0] = 1;
    const int modulus = 1e9 + 7;

    for(int i=1; i<=n; i++)
    {
        for(auto v:values)
        {
            if(i-v>=0)
            {
                combinations[i] += combinations[i-v];
                combinations[i] %= modulus;
            }
        }
    }
    cout<<combinations[n];
}