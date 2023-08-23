#include<bits/stdc++.h>
using namespace std;
class fanwick{
public:
	vector<int>fen;
	int n;
	fanwick(int N){
		n=N;
		fen.resize(N+1);
	}
	void add(int i ,int val){
		while(i<=n){
			fen[i]+=val;	
			i+=i&(-i);
		}
		return;
	}
	int sum(int i){
		int sum=0;
		while(i>0){
			sum+=fen[i];
			i-=i&(-i);
		}
		return sum;
	}
	int range(int l ,int r){
		return sum(r)-sum(l-1);
	}
	int find(int val){
		int ind=0, prev=0;
		for(int i = log2(n);i>=0;i--){
			if(fen[ind+(1<<i)] +prev<val){
				ind=ind+(1<<i);
				prev+=fen[ind];	
			}
		}
		return ind;
	}
};
int main(){
	int n ;
	cin>>n;
	fanwick fen(n);
	for(int i = 1 ;i<=n;i++){
		int temp;
		cin>>temp;
		fen.add(i,temp);
	}
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int l,r;
			cin>>l>>r;
			cout<<fen.range(l,r)<<endl;
		}
		else{
			int i ,val;
			cin>>i>>val;
			fen.add(i,val);
		}
	}
}
