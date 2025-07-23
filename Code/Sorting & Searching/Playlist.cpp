#include<bits/stdc++.h>

using namespace std;



int main(){
    int n, curmax=0, maxlength=INT_MIN, lastrep=-1;
    cin>>n;
    vector<int> songs(n);
    map<int, int> hashmap;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        songs[i] = x;

        if(hashmap.count(x)==0 || i-hashmap[x]>curmax)
        {
            curmax++;
            
        }
        else{
            curmax= i - hashmap[x];
        }
        hashmap[x] = i;
        maxlength = max(maxlength,curmax);
        
    }

    cout<<maxlength;
}

