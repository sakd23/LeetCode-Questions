//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> a[]) {
        // Code here
        queue<int> q;
        vector<int> vis(v,0),ans;
        q.push(0);
       vis[0]=1;
        
        while(!q.empty())
        {
            int siz=q.size();
            for(int i=0;i<siz;i++)
            {
                int temp=q.front();
                ans.push_back(temp);
               
                q.pop();
                for(auto x:a[temp])
                {
                    if(!vis[x])
                    {
                        q.push(x);
                        vis[x]=1;
                    }
                }
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
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends