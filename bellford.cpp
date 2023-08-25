#include<bits/stdc++.h>
using namespace std;
struct edg{
	int u,v,w;
	edg(int _u,int _v,int _w){
		 u=_u;
		 v=_v;
		 w=_w;
	}
};
void bellford(vector<edg>edge,int n){
	vector<int>dist(n,INT_MAX);
	dist[0]=0;
	for(int i = 0 ; i < n-1;i++){
		for(auto it:edge){
			int u = it.u;
			int v=it.v;
			int w=it.w;
			if(dist[u]+w<dist[v]){
				dist[v]=dist[u]+w;
			}
		}
	}
	for(auto it:edge){
		int u = it.u;
		int v=it.v;
		int w=it.w;
		if(dist[u]+w<dist[v]){
			cout<<"cycle neg"<<endl;
			return;
		}
	}
	for(int i = 0 ; i < n ; i++){
		cout<<dist[i]<<" ";
	}
}
int main(){
	int n , m ;
	cin>>n>>m;
	vector<edg>edge;
	for(int i = 0  ; i< m ; i ++){
		int u , v,w;
		cin>>u>>v>>w;
		
		edge.push_back(edg(u,v,w));
		
	}
	
	bellford(edge,n);

	return 0;
}
