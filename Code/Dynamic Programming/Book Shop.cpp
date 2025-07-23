#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    const int MOD = 1e9+7;

    int n, money;
    cin>>n>>money;

    vector<pair<int,int>> books(n);
    vector<int> pages_for_sum(money+1, 0);
    
    for(auto &x:books) cin>>x.first;
    for(auto &x:books) cin>>x.second;


        for(auto book:books)
        {
    for(int i=money; i>0; i--)
    {
       
        

            if(i-book.first>=0)
            {
                pages_for_sum[i] = max(pages_for_sum[i], pages_for_sum[i-book.first] + book.second);
                
            }
        
    }
        }
    cout<<pages_for_sum[money];
}