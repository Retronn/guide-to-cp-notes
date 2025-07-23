#include<bits/stdc++.h>

using namespace std;



int main(){
    int n, counter=0, maxi=0, last=0;
    cin>>n;
    vector<int> timeIn(n), timeOut(n);
    

    for(int i=0; i<n; i++){
        cin>>timeIn[i]>>timeOut[i];
    }

    sort(timeIn.begin(), timeIn.end());
    sort(timeOut.begin(), timeOut.end());

    
    for(int i=0; i<n; i++)
    {
        if(last==n-1) break;
        if(timeIn[i]<timeOut[last])
        {
            counter++;
            maxi = max(counter,maxi);
        }
        else{
            last++;
        }
    }
    
    cout<<maxi;
}

