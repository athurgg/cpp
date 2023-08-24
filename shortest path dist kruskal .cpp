# cpp
#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h> 
int numberOfWays(int n, int m, vector<vector<int>> edges)
{
    vector<pair<int,int>>adj[n];

    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int>mini(n,INT_MAX);
    vector<int>ans(n);
    mini[0]=0;
    ans[0]=1;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,0});
    while(!q.empty()){
        int val=q.top().first;
        int node=q.top().second;
        q.pop();
        for(auto it : adj[node]){
            int adjn=it.first;
            int adjv=it.second;
            if(mini[adjn]>adjv+val){
                ans[adjn]=ans[node];
                mini[adjn]=adjv+val;
                q.push({mini[adjn],adjn});
            }
            else if(mini[adjn]==adjv+mini[node]){
                ans[adjn]=(ans[adjn]+ans[node])%mod;
                
            }
        }    
        
    }
    return ans[n-1];


}
int mazeRunner(int n, int m, vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
    vector<int>dist(n*m+1,INT_MAX);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    dist[start[0]*m+start[1]]=0;
    pq.push({0,{start[0],start[1]}});
    int xx[4]={0,0,-1,1};
    int yy[4]={-1,1,0,0};
    while(!pq.empty()){
        int dis=pq.top().first;
        int y=pq.top().second.first;
        int x= pq.top().second.second;
        pq.pop();
        for(int i = 0 ; i< 4 ; i++){
            int ny=y;
            int nx=x;
            int cnt=dis;
            while(ny>=0 && nx>=0 &&ny<n && nx<m && maze[ny][nx]==0){
                ny+=yy[i];
                nx+=xx[i];
                cnt++;
            }
            ny-=yy[i];
            nx-=xx[i];
            cnt--;
            
            if(cnt<dist[ny*m+nx]){
                dist[ny*m+nx]=cnt;
                pq.push({cnt,{ny,nx}});
            }
        }
    }
    if(dist[destination[0]*m+destination[1]]==INT_MAX)return -1;
    else return dist[destination[0]*m+destination[1]];
}  
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
