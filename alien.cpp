# cpp
#include<bits/stdc++.h>
using namespace std;
class Solution {
private: 
    int getInt(char c) {
        return (c-'a'); 
    }
private: 
    bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, stack<int> &st) {
        vis[node] = 1; 
        pathVis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(checkCycle(it, adj, vis, pathVis, st) == true) {
                    return true; 
                }
            }
            else if(pathVis[it] == 1) {
                return true; 
            }
        }
        pathVis[node] = 0; 
        st.push(node); 
        return false; 
    }
public:
    string alienOrder(vector<string>& words) {
        int n = words.size(); 
        vector<int> adj[26]; 
 
        vector<int> present(26, 0); 
        vector<int> vis(26, 0), pathVis(26, 0); 
        for(int i = 0;i<n;i++) {
            for(auto it : words[i]) {
                present[getInt(it)] = 1; 
            }
        }
 
        for(int i = 0;i<n-1;i++) {
            string s1 = words[i]; 
            string s2 = words[i+1]; 
            int m = s1.size(); 
 
 
            for(int j = 0;j<m;j++) { 
                if(s1[j] != s2[j]) {
                    adj[getInt(s1[j])].push_back(getInt(s2[j]));
                    break; 
                }
            }
        }
 
        stack<int> st; 
        for(int i = 0;i<26;i++) {
            if(present[i] && !vis[i]) {
                if(checkCycle(i, adj, vis, pathVis, st) == true) {
                    return ""; 
                }
            }
        }
 
        string ans = ""; 
        while(!st.empty()) {
            ans += char(st.top() + 'a'); 
            st.pop(); 
        }
        return ans; 
    }
};
int main(){
	int n ;
	cin>>n;
	vector<string>s;
	for(int i = 0 ; i< n ; i++){
		string t;
		cin>>t;
		s.push_back(t);
	}
	Solution a;
	string ans=a.alienOrder(s) ;
	cout<<ans;
	
	
}
