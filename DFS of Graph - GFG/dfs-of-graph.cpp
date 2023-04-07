//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // Function to return a list containing the DFS traversal of the graph.
  vector<int> ans;
  void dfs(vector<int> a[],vector<int>& vis,int v,int n)
  {
      ans.push_back(v);
      vis[v]=1;
      
      
      for(auto x:a[v])
      {
          if(!vis[x])
          {
             dfs(a,vis,x,n); 
          }
      }
  }
    vector<int> dfsOfGraph(int v, vector<int> a[]) {
       
        vector<int> vis(v+1,0);
       
       for(int i=0;i<v;i++)
       {
           if(!vis[i])
           {
               dfs(a,vis,0,v);
           }
       }
       return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends