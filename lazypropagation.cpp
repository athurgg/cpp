#include <bits/stdc++.h>
using namespace std;
class ST{
public:
	vector<int>seg,lazy;
	ST (int n){
		seg.resize(n*4);
		lazy.resize(n*4);
	}
	void build(int ind ,int low,int high ,int arr[]){
		if(low==high){
			seg[ind]=arr[low];
			return;
		}
		int mid=(low+high)/2;
		build(ind*2+1,low,mid,arr);
		build(ind*2+2,mid+1,high,arr);
		seg[ind]=seg[ind*2+1]+seg[ind*2+2];
	}
	int quary(int ind,int low,int high,int l,int r){
		if(lazy[ind]!=0){
			seg[ind]+=lazy[ind]*(high-low+1);
			if(low!=high){
				lazy[ind*2+1]+=lazy[ind];
				lazy[ind*2+2]+=lazy[ind];	
			}
			lazy[ind]=0;
		}
		if(l>high || r<low)return 0;
		if(l<=low && r>=high)return seg[ind];
		int mid=(low+high)/2;
		return quary(ind*2+1,low,mid,l,r)+quary(ind*2+2,mid+1,high,l,r);
		
	}
	void update(int ind,int low,int high,int l,int r,int val){
		if(lazy[ind]!=0){
			seg[ind]+=lazy[ind]*(high-low+1);
			if(low!=high){
				lazy[ind*2+1]+=lazy[ind];
				lazy[ind*2+2]+=lazy[ind];	
			}
			lazy[ind]=0;
		}
		if(low==high){
			seg[ind]+=val;
		}
		
		if(l>high || r<low)return;
		if(l<=low && r>=high){
			seg[ind]+=val*(high-low+1);
			lazy[ind*2+1]+=val;
			lazy[ind*2+2]+=val;
			return;
		}		
		int mid=(low+high)/2;
			update(ind*2+1,low,mid,l,r,val);
			update(ind*2+2,mid+1,high,l,r,val);
		seg[ind]=seg[ind*2+1]+seg[ind*2+2];
	}

};

class STmin{
public:
	vector<int>seg,lazy;
	STmin (int n){
		seg.resize(n*4);
		lazy.resize(n*4);
	}
	void build(int ind ,int low,int high ,int arr[]){
		if(low==high){
			seg[ind]=arr[low];
			return;
		}
		int mid=(low+high)/2;
		build(ind*2+1,low,mid,arr);
		build(ind*2+2,mid+1,high,arr);
		seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
	}
	int quary(int ind,int low,int high,int l,int r){
		if(lazy[ind]!=0){
			seg[ind]+=lazy[ind];
			if(low!=high){
				lazy[ind*2+1]+=lazy[ind];
				lazy[ind*2+2]+=lazy[ind];	
			}
			lazy[ind]=0;
		}
		if(l>high || r<low)return INT_MAX;
		if(l<=low && r>=high)return seg[ind];
		int mid=(low+high)/2;
		return min(quary(ind*2+1,low,mid,l,r),quary(ind*2+2,mid+1,high,l,r));
		
	}
	void update(int ind,int low,int high,int l,int r,int val){
		if(lazy[ind]!=0){
			seg[ind]+=lazy[ind];
			if(low!=high){
				lazy[ind*2+1]+=lazy[ind];
				lazy[ind*2+2]+=lazy[ind];	
			}
			lazy[ind]=0;
		}
		if(low==high){
			seg[ind]+=val;
		}
		
		if(l>high || r<low)return;
		if(l<=low && r>=high){
			seg[ind]+=val;
			lazy[ind*2+1]+=val;
			lazy[ind*2+2]+=val;
			return;
		}		
		int mid=(low+high)/2;
			update(ind*2+1,low,mid,l,r,val);
			update(ind*2+2,mid+1,high,l,r,val);
		seg[ind]=min(seg[ind*2+1],seg[ind*2+2]);
	}

};
int main(){ 
	int n ; 
	cin>> n ;
	 int arr[n];
	 for(int i = 0 ; i< n ; i++){
	 	cin>>arr[i];
	 }
	 ST st(n);
	 st.build(0,0,n-1,arr);
	 int t;
	 cin>> t;
	 while(t--){
	 	int type;
	 	cin>>type;
	 	if(type==1){
	 		int l , r;
	 		cin>>l>>r;
	 		cout <<st.quary(0,0,n-1,l,r)<<endl;
	 	}
	 	else{
	 		int l , r , val;
	 		cin>>l>>r>>val;
	 		st.update(0,0,n-1,l,r,val);

	 	}
	 }
	 return 0;
}



