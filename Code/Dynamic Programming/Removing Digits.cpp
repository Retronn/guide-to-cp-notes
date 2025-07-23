#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string string_number;
    int n;
    cin>>n;
    vector<int> steps(n+1);
    steps[0] = 0;

    for(int i =1; i<=n; i++)
    {
        steps[i] = INT_MAX;
        string_number = to_string(i);
        for(auto char_digit:string_number)
        {
            int digit = char_digit - '0';
            if(i - digit >=0 && steps[i-digit]!=INT_MAX)
            {
                steps[i] = min(steps[i], steps[i-digit]+1);
            }
        }
    }
    cout<<steps[n];
}