#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int> numbers(n);

    for(auto &x:numbers) cin>>x;

    long long ans =0L;

    int point1=-1, point2=0, distinct=0;
    unordered_map<int, int> hashmap;
    set<int> distinct_positions;

    while(point2<n)
    {
        if(hashmap.count(numbers[point2])==0)
        {

            distinct++;
            if(distinct>k)
            {
                int new_pos = *distinct_positions.begin();
                int num_to_clear = numbers[new_pos];
                hashmap.erase(num_to_clear);
                point1 = new_pos;
                distinct_positions.erase(distinct_positions.begin());
                distinct--;
            }
        }

        else{
            int pos_to_update = hashmap[numbers[point2]];
            auto it_update = distinct_positions.find(pos_to_update);
            distinct_positions.erase(it_update);
        }
        
        distinct_positions.insert(point2);
        hashmap[numbers[point2]] = point2;

        ans+=(long long)(point2-point1); 
        point2++;
    }
    cout<<ans;
}

