//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool detect(int v, vector<int> a[],int src, vector<int>& vis)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
       
        vis[src]=1;
        while(!q.empty())
        {
            pp curr=q.front();
            q.pop();
            int parent=curr.second;
            for(auto x:a[curr.first])
            {
                
                if(!vis[x])
                {
                    q.push({x,curr.first});
                    vis[x]=1;
                }
                else if(x!=parent)
                {
                    return true;
                }
            }
            
        }
        return false;
    }
  public:
  typedef pair<int,int> pp;
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> a[]) {
        // Code here
         vector<int> vis(v,0);
         bool ans=false;
         for(int i=0;i<v;i++)
         {
             if(!vis[i])
             {
                 if(detect(v,a,i,vis))return true;
                
             }
         }
         return ans;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends