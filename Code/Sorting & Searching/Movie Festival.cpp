#include<bits/stdc++.h>

using namespace std;


    bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second<b.second;
    }
int main(){
    int n, counter=1;
    cin>>n;
    vector<pair<int,int>> movies(n);
    for(auto &x:movies) cin>>x.first>>x.second;


    sort(movies.begin(), movies.end(),  cmp);

    int last = movies[0].second;

    for(int i=1; i<n; i++)
    {
        if(movies[i].first>=last)
        {
            counter++;
            last = movies[i].second;
        }
    }

    cout<<counter;
}

