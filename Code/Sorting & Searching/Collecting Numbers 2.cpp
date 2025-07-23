#include<bits/stdc++.h>

using namespace std;



int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                  

    int n,m;
    cin>>n>>m;
    int ans=1; 
    vector<int> numbers(n + 1), positions(n + 1);
    for(int i=1; i<=n; i++) 
    {
        cin>>numbers[i];
        positions[numbers[i]] = i;
    }

    for(int i=1; i<n; i++) 
    {
        if(positions[i] > positions[i+1])
        {   
            ans++;
        }
    }

    for(int k=0; k<m; k++)
    {
        int idx1, idx2;
        cin>>idx1>>idx2;

        int val1 = numbers[idx1];
        int val2 = numbers[idx2];


        set<int> affected;
        if (val1 > 1) affected.insert(val1 - 1);
        affected.insert(val1);
        if (val2 > 1) affected.insert(val2 - 1);
        affected.insert(val2);

        int breaks_before = 0;

        for (int x : affected) {
            if (x < n && positions[x] > positions[x + 1]) {
                breaks_before++;
            }
        }

        swap(numbers[idx1], numbers[idx2]);
        swap(positions[val1], positions[val2]);

        int breaks_after = 0;

        for (int x : affected) {
            if (x < n && positions[x] > positions[x + 1]) {
                breaks_after++;
            }
        }
        
        ans += (breaks_after - breaks_before);
        
        cout << ans << "\n";
    }
}