#include<bits/stdc++.h>

using namespace std;





int main(){
    int n, k;
    cin>>n>>k;
    vector<pair<int,int>> numbers(n);

    for(int i=0; i<n; i++) 
    {cin>>numbers[i].first;
    numbers[i].second = i+1;
    }
    sort(numbers.begin(), numbers.end());

    
    for(int i=0; i<n; i++)

    {
        pair<int,int> x = numbers[i];
        int sumleft = k-x.first;
        if(sumleft<2 || n<3) {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        int left = 0, right = n-1;

        while(left!=right)
        {
            if(left==i) left++;
            if(right==i) right--;
            if(left==n || right<0) break;
            int cur_sum = numbers[right].first + numbers[left].first;

            if(cur_sum==sumleft)
            {
                cout<<x.second<<" "<<numbers[right].second<<" "<<numbers[left].second;
                return 0;
            }
            else if(cur_sum<sumleft) left++;
            else right--;
        }

    }

     cout<<"IMPOSSIBLE";
}

