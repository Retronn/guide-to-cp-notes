#include<bits/stdc++.h>

using namespace std;

struct Range{
    int enter;
    int exit;
    int original_index;
};

bool CmpByExit(const Range& a, const Range& b)
{
    if(a.exit!=b.exit) return a.exit<b.exit;
    return a.enter<b.enter;
}

int main(){
    int n;
    cin>>n;

    vector<Range> ranges(n);
    vector<int> allocation(n);
    set<pair<int,int>> rooms;
    int room_allocated;

    for(int i=0; i<n; i++){

        cin>>ranges[i].enter>>ranges[i].exit;
        ranges[i].original_index = i;
    }
    
    sort(ranges.begin(), ranges.end(), CmpByExit);
    
    for(auto range:ranges)
    {
        if(rooms.size()==0) {
            rooms.insert({range.exit, 1});
            allocation[range.original_index] = 1;
            continue;
        }

        auto it = rooms.lower_bound({range.enter, INT_MIN});

        if(it!=rooms.begin())
        {
            --it;
            room_allocated = (*it).second;
            rooms.erase(it);
        }
        else{
            room_allocated = rooms.size() +1;
        }

        rooms.insert({range.exit, room_allocated});
        allocation[range.original_index] = room_allocated;
    }


    cout<<rooms.size()<<"\n";
    for(auto x: allocation) cout<<x<<" ";
}

