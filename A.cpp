//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#
int stoii(string s){
    int ans = 0;
    for(auto it: s){
        int cur = it-'0';
        ans = ans*10+cur;
    }
    return ans;
}


vector<vector<int>> adj;
vector<int> vis;
void solve(){
    int n;
    cin>>n;
    adj.resize(n+1,vector<int>());
    vis.resize(n+1,false);
    string k;
    getline(cin,k);
    for(int i = 1 ;i<=n ;i++){
        string s;
        getline(cin,s);
        // cout<<i<<" ";
        stringstream ss(s);
        for(int x;ss>>x;){
            // cout<<x<<" ";
            adj[i].push_back(x);
            if(ss.peek() == ' ') ss.ignore();
        }
        // cout<<endl;
    }
    int s,e;
    cin>>s>>e;
    queue<pair<int,int>> q;
    q.push({s,0});
    while(q.size()){
        int u = q.front().first;
        int val = q.front().second;
        q.pop();
        if(vis[u]) continue;
        if(u== e){
            cout<<val;
            return ;
        }
        vis[u] = true;
        for(auto child : adj[u]){
            if(!vis[child]){
                q.push({child,val+1});
            }
        }
    }
    cout<<-1;
}
int main(){
    
    int t ;
    t = 1 ;
    
    while(t--){
            solve();

    }
    
}


