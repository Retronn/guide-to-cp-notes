#include<bits/stdc++.h>

using namespace std;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  set<int> children;

  for(int i=1; i<=n; i++) children.insert(i);


  auto it = children.begin();
  for(int i=1; i<=n; i++)
  {
    ++it;
    if(it == children.end()) it = children.begin();
    cout<<*it<<" ";
    it = children.erase(it);
    if(it == children.end()){
        it = children.begin();
    }
  }

}

