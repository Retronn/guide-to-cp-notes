#include<bits/stdc++.h>

using namespace std;



int main(){
    long long a,ans=0,num=-1;
    cin>>a;
    long long counter[200001];

    for(long long i=0; i<a; i++)
    {
        
        cin>>counter[i];

    }
    sort(counter, counter+a);
    for(long long i=0; i<a; i++)
    {
        if(num!=counter[i])
        {
            ans++;
            num=counter[i];
        }
    }
cout<<ans;

}
