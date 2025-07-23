#include<bits/stdc++.h>

using namespace std;





int main(){
    int n, k;
    cin>>n>>k;
    vector<pair<int,int>> numbers(n);
    vector<tuple<int,int,int>> sums;

    
    for(int i=0; i<n; i++) 
    {cin>>numbers[i].first;
    numbers[i].second = i+1;
    }
    if(n<4) {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=0; i<n; i++){
        int num1, idx1;
        num1=numbers[i].first;
        idx1=numbers[i].second;
        for(int j=0; j<n; j++)
        {
            if(j==i) continue;
            int num2, idx2;
            num2=numbers[j].first;
            idx2=numbers[j].second;
            sums.push_back({num1+num2, idx1, idx2});
        }
    }

    sort(sums.begin(), sums.end());

    int left=0, right = sums.size()-1;

    while (left!=right)
    {
        int new_sum = get<0>(sums[left])+ get<0>(sums[right]);

        if(new_sum==k)
        {
            set<int> values;
            values.insert(get<1>(sums[left]));
            values.insert(get<2>(sums[left]));
            values.insert(get<1>(sums[right]));
            values.insert(get<2>(sums[right]));
            if(values.size()==4){
                cout<<get<1>(sums[left])<<" "<<get<2>(sums[left])<<" "<<get<1>(sums[right])<<" "<<get<2>(sums[right]);
                return 0;
            }
            left++;
        }
        else if(new_sum<k) left++;
        else right--;
    }
    
    cout<<"IMPOSSIBLE";
}

