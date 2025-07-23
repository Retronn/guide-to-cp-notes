#include<bits/stdc++.h>
using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   vector<int> sums;
   vector<bool> check(100000000,true);
   int n;
   cin>>n;

   for(int i=0; i<n;i++)
   {
    int x;
    cin>>x;
    int size = sums.size();
    for(int j=0; j<size; j++)
    {
        if(check[sums[j]+x]==true)
        {
            check[sums[j]+x] = false;
            sums.push_back(sums[j]+x);
        }

    }

    if(check[x]==true)
        {
            check[x] = false;
            sums.push_back(x);
        }

   }

   cout<<sums.size()<<"\n";
   sort(sums.begin(), sums.end());
   for(auto x:sums) cout<<x<<" ";
   
  
}