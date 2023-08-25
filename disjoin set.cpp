//buat tree di graph
// #include<bits/stdc++.h>
// using namespace std;
// class disjoinsize{
// public:
// 	vector<int>parent,size;
// 	disjoinsize(int n){
// 		parent.resize(n);
// 		size.resize(n,0);
// 		for(int i = 0 ; i< n ; i++){
// 			parent[i]=i;
// 		}
// 	}
// 	int find(int n){
// 		int p = n;
// 		while (parent[p]!=p){
// 			p=parent[p];
// 		}
// 		return parent[n]=p;
// 	}
// 	void uni(int a ,int b){
// 		int n =find(a);
// 		int m = find(b);
// 		if(n==m)return;
// 		if(size[n]>size[m]){			
// 			parent[m]=n;
// 			size[n]+=size[m];
// 		}
// 		else{
// 			parent[n]=m;
// 			size[m]+=size[n];
// 		}
// 	}	
 
// };
// int main(){
// 	int n,m ;
// 	cin>>n;
// 	m=n-1;
// 	disjoinsize ds(n);
// 	queue<pair<int,int>>q;
// 	for(int i = 0 ;i < m ; i++){
// 		int u , v ;
// 		cin>>u>>v;
// 		u--;
// 		v--;
// 		if(ds.find(u)==ds.find(v)){
// 			q.push({u,v});			
// 		}
// 		else{
// 			ds.uni(u,v);
// 		}
// 	}
// 	vector<int>parent;
// 	for(int i = 0 ; i< n; i++){
// 		if(ds.parent[i]==i)parent.push_back(i);
// 	}
// 	cout<<parent.size()-1<<endl;
// 	for(int i =0 ; i<parent.size()-1;i++){
// 		cout<<q.front().first+1<<" "<<q.front().second+1<<" "<<parent[i]+1<<" "<<parent[i+1]+1<<endl;
// 		q.pop();
// 	}
// 	return 0;
// }


#include <bits/stdc++.h>
class disjoinrank{
	vector<int>parent,rank;
	disjoinrank(int n){
		rank.resize(n,0);
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
		if(rank[n]>rank[m]){			
			parent[m]=n;
				
		}
		else if(rank[m]>rank[n]){
			parent[n]=m;
		}
		else{
			parent[m]=n;
			rank[n]++;
		}
	}	

};
class disjo{
public:
vector<int>size,parent;
	disjo (int n ){
		size.resize(n,1);
		parent.resize(n);
		for(int i = 0 ; i< n ; i++){
			parent[i]=i;
		}
	}
	int find(int n){
		int p = n ; 
		while(p !=parent[p]){
			p=parent[p];
		}
		return parent[n]=p;
	}
	void uni(int a,int b){
		int n = find(a);
		int m =find (b);
		if(n==m)return;
		if(size[n]>size[m]){
			size[n]+=size[m];
			parent[m]=n;
		}
		else{
			size[m]+=size[n];
			parent[n]=m;
		}
	}

};
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	vector<int>ans;
	disjo dj(n*m);
	int mat[n][m]={0};
	int xx[4]={0,0,-1,1};
	int yy[4]={1,-1,0,0};
	int cur=0;
	for(auto it:q){
		int y=it[0];
		int x = it[1];
		mat[y][x]=1;
		for(int i = 0 ; i < 4 ; i++){
			int nx=x+xx[i];
			int ny=y+yy[i];
			if(ny>=0 && nx>=0&& ny<n&&nx<m&& mat[ny][nx]==1){
				if(dj.find(y*m+x)!=dj.find(ny*m+nx)){
					dj.uni(y*m+x,ny*m+nx);
					cur--;
				}
			}		
		}
		cur++;
			
		ans.push_back(cur);
	}
	return ans;
}
