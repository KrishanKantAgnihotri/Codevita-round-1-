//Author : Krishan Kant Agnihotri        
#include<bits/stdc++.h>
using namespace std;

struct rec{
	int id;
	int p;
	int c1,c2,c3;
};
bool cmp(rec one,rec two){
	if(one.p == two.p){
		return one.id<two.id;
	}
	return one.p>two.p;
}
void solve(){
	int c;
	cin>>c;
	int n;
	cin>>n;
	vector<int> v(c+1);
	for(int i = 1 ;i<=c ;i++){
		cin>>v[i];
	}
	vector<rec> v2(n);
	for(int i = 0 ;i<n ;i++){
		string s;
		cin>>s;
		int j = 0 ; 
		while(s[j]!=',') j++;
		v2[i].id = i+1;
		j++;
		int cur = 0 ; 
		for(;s[j]!=',';j++){
			if(s[j] == '.') continue;
			cur = cur*10+ (s[j]-'0');
		}
		v2[i].p = cur;
		j++;
		for(int k = 0 ;k<3 ;k++){
		bool ok = false;
		cur = 0 ; 
		while(s[j]!='-'){
			j++;
		}
		j++;
		while((j<(int)s.length()) &&s[j]!=','){
			cur = cur*10+(s[j]-'0');
			j++;
		}
		j++;
		if(k == 0){
			v2[i].c1 = cur;
		}
		else if(k == 1){
			v2[i].c2 = cur;
		}
		else 
			v2[i].c3 = cur;
		if(j>(int)s.length()) break;
	  }
	}
	// for(int i = 0 ;i<n ;i++){
	// 	cout<<v2[i].id<<" "<<v2[i].p<<" "<<v2[i].c1<<" "<<v2[i].c2<<" "<<v2[i].c3<<endl;
	// }
	sort(v2.begin(),v2.end(),cmp);
	vector<bool> vis(n,false);
	vector<int> ans(c+1);
	for(int i = 1 ;i<=c ;i++){
		ans[i] = INT_MAX;
	}
	bool ov = false;
	for(int i = 0 ;i<n ;i++){
		int cc = v2[i].c1;
		if(v[cc]>0){
			v[cc]--;
			ans[cc] = min(ans[cc],v2[i].p);
			vis[i] = true;
			continue;
		}
		cc = v2[i].c2;
		if(v[cc]>0){
			v[cc]--;
			ans[cc] = min(ans[cc],v2[i].p);
			vis[i] = true;
			continue;
		}
		cc = v2[i].c3;
		if(v[cc]>0){
			v[cc]--;
			ans[cc] = min(ans[cc],v2[i].p);
			vis[i] = true;
			continue;
		}
		ov = true;
	}
	if(!ov){
		vector<pair<int,int>> fans;
		for(int i =1 ;i<=c ;i++){
			if(ans[i]!=INT_MAX){
				fans.push_back({ans[i],i});
			}
			else{
				fans.push_back({-ans[i],i});
			}
		}
		sort(fans.rbegin(),fans.rend());
		for(int i = 0 ;i<c ;i++){
			if(fans[i].first!=-INT_MAX){
			string res = to_string(fans[i].first);
			cout<<"C-"<<fans[i].second<<" "<<res[0]<<res[1]<<"."<<res[2]<<((res[3]=='0') ?' ':res[3])<<endl;
		}
		else{
			cout<<"C-"<<fans[i].second<<" n/a\n";
		}
		}
		return ;
	}
	priority_queue<pair<int,int>> pq;
	for(int i = 1 ;i<=c ;i++){
		if(v[i]>0){
			pq.push({v[i],i});
		}
	}
	for(int i = 0 ;i <n ;i++){
		if(vis[i]) continue;
		int cno = pq.top().second;
		int val = pq.top().first;
		val--;
		ans[cno] = min(ans[cno],v2[i].p);
		if(val>0){
			pq.push({val,cno});
		}		
	}
	vector<pair<int,int>> fans;
		for(int i =1 ;i<=c ;i++){
			if(ans[i]!=INT_MAX){
				fans.push_back({ans[i],i});
			}
			else{
				fans.push_back({-ans[i],i});
			}
		}
		sort(fans.rbegin(),fans.rend());
		for(int i = 0 ;i<c ;i++){
			if(fans[i].first!=-INT_MAX){
			string res = to_string(fans[i].first);
			cout<<"C-"<<fans[i].second<<" "<<res[0]<<res[1]<<"."<<res[2]<<((res[3]=='0')?' ':res[3])<<endl;
		}
		else{
			cout<<"C-"<<fans[i].second<<" n/a\n";
		}
		}

}
int main(){
    int t;
    t = 1 ;
    while(t--){
            solve();

    }
    
}


