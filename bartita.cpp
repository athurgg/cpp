#include<bits/stdc++.h>
using namespace std;
// bool bartita(vector<int>&vis,int parent,int n,vector<int>node[]){
// 	vis[n]=parent;
// 	for(auto it:node[n]){
// 		if(vis[it]==-1){
// 			if(bartita(vis,!parent,it,node))return true;
// 		}
// 		else if(vis[it]==parent){
// 			return  true;
// 		}
// 	}
// 	return false;
// }
bool bartita(vector<int>vis,vector<int>node[]){
	queue<pair<int,int>>q;
	q.push({0,0});
	vis[0]=0;
	while(!q.empty()){
		int n=q.front().first;
		int p=q.front().second;
		q.pop();
		
		for(auto it: node[n]){
			if(vis[it]==-1){
				q.push({it,!p});
				vis[it]=!p;
			}
			else if(vis[it]==p){
				return  true;
			}
		}	
	}
	return false;

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
	vector<int>vis(n,-1);
	cout<<bartita(vis,node);
	return 0;
}
