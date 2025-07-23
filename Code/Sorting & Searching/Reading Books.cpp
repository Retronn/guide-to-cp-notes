#include<bits/stdc++.h>

using namespace std;



int main(){
    int n;
    long long total=0;
    cin>>n;
    vector<int> time(n);

    for(auto &x:time) 
    {
        cin>>x;
        total+=(long long)x;
    }
    sort(time.begin(), time.end());

    long long maxbook = (long long)time[n-1];

    cout<<max(maxbook*2,total);
}

