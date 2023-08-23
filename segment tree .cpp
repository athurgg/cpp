# cpp
#include <bits/stdc++.h>
using namespace std;
void build(int ind,int low,int high,int arr[],int seg[]){
	if(low==high){
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)/2;
	build(ind*2+1,low,mid,arr,seg);
	build (ind*2+2,mid+1,high,arr,seg);
	seg[ind]=min(seg[ind*2+2],seg[ind*2+1]);
}
int quary(int ind,int low,int high,int l ,int r,int seg[]){
	if(low>r || high<l)return INT_MAX;
	if(l<=low && r>=high)return seg[ind];
	int mid=(low+high)/2;
	return min (quary(ind*2+1,low,mid,l,r,seg),quary(ind*2+2,mid+1,high,l,r,seg));
}
void update(int ind,int low,int high,int i , int val,int seg[]){
	if(low==high)
		{
			seg[ind]=val;
			return;
		}
	int mid=(low+high)>>1;
	if(i<=mid){
		update(ind*2+1,low,mid,i,val,seg);
	}
	else update(ind*2+2,mid+1,high,i,val,seg);
	seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
}
int main(){ 
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	int seg[n*4];
	build(0,0,n-1,arr,seg);
	int t;
	cin>>t;
	while(t--){
		int type;
		cin>>type;
		if(type== 1){
			int l,r;
			cin>>l>>r;
			cout<<quary(0,0,n-1,l,r,seg)<<endl;
		}
		else {
			int i,val;
			cin>>i>>val;
			update(0,0,n-1,i,val,seg);
		}
	}
	
	for(int i = 0 ; i< n*4-1;i++){
		cout<<seg[i]<<" ";
	}
	// cout<<"wiuhdai";

	
}




