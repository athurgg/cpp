#include<bits/stdc++.h>
using namespace std;
void dfs(int vis[],vector<int>node[],int n,vector<int>&ans){
	ans.push_back(n);
	vis[n]=1;
	for(int i =0;i<node[n].size();i++){
		if(!vis[node[n][i]]){
			dfs(vis,node,node[n][i],ans);
		}
	}
	return;
}
int main(){
	int n,e;
	cin>>n>>e;
	int u,v;
	vector<pair<int,int>>edge;
	for(int i = 0 ;i<e;i++){
		cin>>u>>v;
		edge.push_back({u,v});
	}
	vector<int>node[n];
	for(int i = 0 ;i< e;i++){
		node[edge[i].first].push_back(edge[i].second);
	}
	int vis[n]={0};
	vector<int>ans;
	dfs(vis,node,0,ans);
	for(int i = 0 ; i< ans.size() ;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
