#include<bits/stdc++.h>
using namespace std;
// void toposort(int vis[],int n,stack<int>&st,vector<int>node[]){
// 	vis[n]=1;
// 	for(auto it:node[n]){
// 		if(!vis[it]){
// 			toposort(vis,it,st,node);
// 		}
// 	}
// 	st.push(n);
// 	return;
// }
void kahn(vector<pair<int,int>>edge,vector<int>node[],int n){
	int arr[n]={0};
	for(auto it:edge){
		arr[it.second]++;
	}
	queue<int>q;
	for(int i  = 0 ; i< n ;i++){
		if(arr[i]==0){
			q.push(i);

		}
	}
	while(!q.empty()){
		int u=q.front();
		cout<<u<<" ";
		q.pop();
		for(auto it:node[u]){
			arr[it]--;
			if(arr[it]==0){
				q.push(it);

			}

		}
	}

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
	stack<int>st;
	// for(int i = 0 ; i< n ; i++){
	// 	if(!vis[i]){
			kahn(edge,node,n);
	// 	}
	// }
	
	// while(!st.empty()){
	// 	cout<<st.top()<<" ";
	// 	st.pop();
	// }
	return 0;
}
