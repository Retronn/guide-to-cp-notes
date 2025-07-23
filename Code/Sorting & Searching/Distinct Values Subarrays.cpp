#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> numbers(n);

    for(auto &x:numbers) cin>>x;

    long long ans =0L;

    int point1=-1, point2=0;
    unordered_map<int, int> hashmap;

    while(point2<n)
    {
        
        if(hashmap.count(numbers[point2]) != 0 && (point2-point1)>point2-hashmap[numbers[point2]])
        {
            point1 = hashmap[numbers[point2]];
        }
        hashmap[numbers[point2]] = point2;
        ans+=(long long)(point2-point1); 
        point2++;
    }
    cout<<ans;
}

