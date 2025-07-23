

using namespace std;
#include <bits/stdc++.h>




#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


struct CompareSecondAsc {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {

        if (a.second != b.second) {
            return a.second < b.second;
        }

        return a.first < b.first;
    }
};



using ordered_set_by_second = tree<
    pair<int, int>, 
    null_type, 
    CompareSecondAsc, 
    rb_tree_tag, 
    tree_order_statistics_node_update
  >;


  struct Range{
    int x;
    int y;
    int original_index;
  };

  bool compareRangesAsc(const Range& a, const Range& b)
  {
    if(a.x!=b.x)
    {
      return a.x<b.x;
    }
    return a.y>b.y;
  }

    bool compareRangesDesc(const Range& a, const Range& b)
  {
    if(a.x!=b.x)
    {
      return a.x>b.x;
    }
    return a.y<b.y;
  }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  vector<Range> ranges(n);
  vector<int> contain(n), contained(n);

  ordered_set_by_second ends, ends_two;


  for(int i=0; i<n; i++)
  {
    pair<int, int> x;

    cin>>x.first>>x.second;
    ranges[i].x = x.first;
    ranges[i].y = x.second;
    ranges[i].original_index = i;
    ends.insert(x);
    ends_two.insert(x);
  } 
  
  sort(ranges.begin(), ranges.end(), compareRangesAsc);

  for(auto range:ranges)
  {
    pair<int,int> x;
    x.first = range.x;
    x.second = range.y;
    
    auto it_of_max_range = ends.upper_bound({INT_MAX, x.second});
    --it_of_max_range; 
    int order = ends.order_of_key(*it_of_max_range);
    contain[range.original_index] = order;

    auto it_delete_e = ends.find(x);
    ends.erase(it_delete_e);

  }

  sort(ranges.begin(), ranges.end(), compareRangesDesc);

  for(auto range:ranges)
  {
    pair<int,int> x;
    x.first = range.x;
    x.second = range.y;

    
    auto it_of_max_range = ends_two.lower_bound({INT_MIN, x.second});
    int order = ends_two.order_of_key(*it_of_max_range);

    contained[range.original_index] = (ends_two.size()-(order+1));

    auto it_delete_e = ends_two.find(x);
    ends_two.erase(it_delete_e);

  }


  for(auto x: contain)
  {
    cout<<x<<" ";
  }
  cout<<endl;
  for(auto x: contained)
  {
    cout<<x<<" ";
  }

}

