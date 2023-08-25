#include<bits/stdc++.h>
using namespace std;
void marsyalflod(vector<vector<int>>mat,int n){
	for(int via =0;via<n;via++){
		for(int i = 0 ; i< n ; i++){
			for(int j = 0 ; j< n ;j++){
				if(i==j || via== i ||j==via)continue;
				if(mat[i][via]+mat[via][j]<mat[i][j]){
					mat[i][j]=mat[i][via]+mat[via][j];
				}
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	return;
}
int main(){
	int n , m ;
	cin>>n>>m;
	vector<vector<int>>mat(n,(vector<int>(n,1000)));
	for(int i = 0  ; i< m ; i ++){
		int u , v,w;
		cin>>u>>v>>w;
		mat[u][v]=w;
		mat[v][u]=w;
		
		
	}
	for(int i = 0 ; i < n ; i++){
		mat[i][i]=0;
	}
	
	marsyalflod(mat,n);

	return 0;
}
