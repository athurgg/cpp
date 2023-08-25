# cpp
#include<bits/stdc++.h>
using namespace std;
class disjoinsize{
public:
	vector<int>parent,size;
	disjoinsize(int n){
		parent.resize(n);
		size.resize(n,0);
		for(int i = 0 ; i< n ; i++){
			parent[i]=i;
		}
	}
	int find(int n){
		int p = n;
		while (parent[p]!=p){
			p=parent[p];
		}
		return parent[n]=p;
	}
	void uni(int a ,int b){
		int n =find(a);
		int m = find(b);
		if(n==m)return;
		if(size[n]>size[m]){			
			parent[m]=n;
			size[n]+=size[m];
		}
		else{
			parent[n]=m;
			size[m]+=size[n];
		}
	}	

};
struct edg{
	int u,v,w;
	edg(int _u,int _v,int _w){
		 u=_u;
		 v=_v;
		 w=_w;
	}
};
bool com( edg a, edg b ){
	if(a.w<b.w)return true;
	return false;
}
int main(){
	int n , m ;
	cin>>n>>m;
	disjoinsize ds(n);
	vector<edg>edge;
	for(int i = 0 ; i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edge.push_back(edg (u,v,w));
	}
	int ans=0;
	sort(edge.begin(),edge.end(),com);
	for(int i  = 0 ; i< m ; i++){
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		if(ds.find(u)!=ds.find(v)){
			ds.uni(u,v);
			ans+=w;
		}
	}
	cout<<ans<<endl;
	return 0;
}
