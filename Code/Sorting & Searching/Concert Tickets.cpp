#include<bits/stdc++.h>

using namespace std;



int main(){
    int n, m, ticket;
    cin>>n>>m;
    vector<int> clients(m);
    multiset<int> tickets;
    for(int i=0; i<n; i++)
    {

        cin>>ticket;
        tickets.insert(ticket);
    }
    for(auto &x:clients) cin>>x;


    

    for(int i=0; i<m; i++)
    {

      
       if(tickets.size()==0 || *tickets.begin()>clients[i]) {
        cout<<-1<<endl;
        continue;
       }

       auto it = tickets.upper_bound(clients[i]);

       --it;
       cout<<*it<<endl;
       tickets.erase(it);
    }

}

