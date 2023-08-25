# cpp
#include<bits/stdc++.h>
using namespace std;
int tin[1000];
int low[1000];
int vis[1000];
int m;
void brige(vector<int>adj[],int parent,int node){
	tin[node]=low[node]=++m;
	vis[node]=1;
	for(auto it: adj[node]){
		if(it==parent)continue;
		if(!vis[it]){
			brige(adj,node,it);
			low[node]=min(low[node],low[it]);
			if(tin[node]<low[it]){
				cout<<node<<" "<<it<<endl;
			}
		}
		else{
			low[node]=min(low[node],low[it]);
		}


	}
}
int main(){
	int n , m ;
	cin>>n>>m;
	vector<int>adj[n];
	for(int i = 0  ; i< n ; i ++){
		int u , v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	brige(adj,-1,0);

	return 0;
}
