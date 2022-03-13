//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;
struct rec{
    string s;
    int a;
    char f;
    int x,y;
};
bool cmp(rec one ,rec two){
     if(one.a == two.a){
         if(one.f == two.f){
            return one.s<two.s;
         }
         return one.f<two.f;
     }
     return one.a>two.a;
}
void solve(){
    int m;
    cin>>m;
    vector<pair<int,int>> v(m);
    for(int i = 0 ;i<m ;i++){
        cin>>v[i].first>>v[i].second;
    }
    int n;
    cin>>n;
    vector<rec> v2(n);
    vector<vector<rec>> ans;
    ans.resize(m,vector<rec>());
    for(int i = 0 ;i<n; i++){
        cin>>v2[i].s>>v2[i].a>>v2[i].f>>v2[i].x>>v2[i].y;
    }
    for(int i = 0 ; i<n ;i++){
        int t  = -1;
        int val = INT_MAX;
        for(int j = 0 ;j<m ;j++){
            int dist = (v2[i].x-v[j].first)*(v2[i].x-v[j].first) + (v2[i].y-v[j].second)*(v2[i].y-v[j].second);
            if(dist<val){
                val = dist;
                t = j;
            }
        }
        ans[t].push_back(v2[i]);
    }
    for(int i = 0 ;i<m ;i++){
        if(ans[i].size())
        sort(ans[i].begin(),ans[i].end(),cmp);
    }
    for(int i = 0 ;i<m ;i++){
        if(ans[i].size()){
            for(int j =0 ;j<ans[i].size() ;j++){
                cout<<ans[i][j].s<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"Empty Centre\n";
        }
    }

}
int main(){
    int t ;
    t = 1 ;
    while(t--){
            solve();

    }
    
}


