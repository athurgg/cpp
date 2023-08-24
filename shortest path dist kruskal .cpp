# cpp
#include<bits/stdc++.h>
using namespace std;
// void shortest10(vector<pair<int,int>>adj[],int n){
// 	deque<pair<int,int>>dq;
// 	dq.push_front({0,0});
// 	vector<int>ans(n,INT_MAX);
// 	ans[0]=0;
// 	while(!dq.empty()){
// 		int n=dq.front().first;
// 		int w=dq.front().second;
// 		dq.pop_front();
// 		for(auto it:adj[n]){
// 			if(w+it.second<ans[it.first]){
// 				ans[it.first]=w+it.second;
// 				if(it.second==0){
// 					dq.push_front({it.first,w+it.second});
// 				}
// 				else{
// 					dq.push_back({it.first,w+it.second});
// 				}
// 			}
// 		}
// 	}
// 	for(int i = 0 ; i<n ; i++){
// 		cout<<ans[i]<<" ";
// 	}
// }
// void shortestdist(vector<pair<int,int>>adj[],int n){
// 	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
// 	pq.push({0,0});
// 	vector<int>ans(n,INT_MAX);
// 	vector<int>parent(n);
// 	ans[0]=0;
// 	while(!pq.empty()){
// 		int w=pq.top().first;
// 		int n=pq.top().second;
// 		pq.pop();
// 		for(auto it:adj[n]){
// 			if(w+it.second<ans[it.first]){
// 				ans[it.first]=w+it.second;
// 				pq.push({w+it.second,it.first});
// 			}
// 		}
// 	}
// 	for(int i = 0 ; i<n ; i++){
// 		cout<<ans[i]<<" ";
// 	}
// }
void shortestpath(vector<pair<int,int>>adj[],int N,int s,int end){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({s,0});
	vector<int>ans(N,INT_MAX);
	vector<int>parent(N);
	parent[0]=-1;
	ans[0]=0;
	while(!pq.empty()){
		int w=pq.top().first;
		int n=pq.top().second;
		pq.pop();
		for(auto it:adj[n]){
			if(w+it.second<ans[it.first]){
				ans[it.first]=w+it.second;
				parent[it.first]=n;
				pq.push({w+it.second,it.first});
			}
		}
	}
	int temp=end;
	while(temp!=-1){
		cout<<temp<<" ";
		temp=parent[temp];
	}

}
int main(){
	int n,e;
	cin>>n>>e;
	int u,v,w;
	vector<pair<int,int>>adj[n];
	for(int i = 0 ; i < e;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	shortestpath(adj,n,0,n-1);
	
	return 0;
}
