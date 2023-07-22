//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    

    // Function to detect cycle in a directed graph.
    bool bfs(int V, vector<int> adj[])
    {
                    queue<int> q;
            vector<int> indeg(V,0),topo;
            
            for(int i=0;i<V;i++)
            {
              for(auto x:adj[i])
              {
                 indeg[x]++;      
              }
            }
            
            for(int i=0;i<V;i++)
            {
                
              if(indeg[i]==0)
              {
                  q.push(i);
              
                  topo.push_back(i);
              }
            }
            
            while(!q.empty())
            {
                int siz=q.size();
                while(siz--)
                {
                    int curr=q.front();
                    q.pop();
                    
                    for(auto x:adj[curr])
                    {
                      indeg[x]--;
                      if(indeg[x]==0)
                      {
                          q.push(x);
                          
                          topo.push_back(x);
                      }
                    }
                }
            }
            return !(topo.size()==V);
    }
    
    
    bool dfs(int v, vector<int> adj[],vector<bool>& vis,vector<bool>& path)
    {
        vis[v]=true;
        path[v]=true;
        bool ans=false;
        for(auto x:adj[v])
        {
            if(path[x])return true;
            if(!vis[x])
            {
                if(dfs(x,adj,vis,path))return true;
            }
        }
        path[v]=false;
        return ans;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // DFS solution
        // vector<bool> vis(V,false),path(V,false);
        // for(int i=0;i<V;i++)
        // {
        //     if(!vis[i])
        //   {
        //         if(dfs(i,adj,vis,path))return true;
        //   }
        // }
        // return false;
    
    //kahn's algo (bfs)

    return bfs(V,adj);
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends