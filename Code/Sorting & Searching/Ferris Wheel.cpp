#include<bits/stdc++.h>

using namespace std;



int main(){
    int n,x, gondolas=0, weight=0;
    cin>>n>>x;
    vector<int> children(n);
    for(auto &i : children) cin>>i;

    sort(children.begin(), children.end());

    int l=0, r=n-1;
    while(l<=r)
    {
        weight = children[r] + children[l];
        if(weight <= x)
        {
            l++;
        }
        gondolas++;
        r--;
    }
    cout<<gondolas;
}