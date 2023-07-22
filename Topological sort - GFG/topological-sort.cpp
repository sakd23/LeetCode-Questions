//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[],int node,vector<int>& vis,stack<int>& st)
	{
	    vis[node]=1;
	    for(auto x:adj[node])
	    {
	        if(!vis[x])
	        {
	            dfs(adj,x,vis,st);
	        }
	    }
	    st.push(node);
	}
	void bfs(vector<int> adj[],int v,vector<int>& indeg,vector<int>& ans)
	{
	    queue<int> q;
	    for(int i=0;i<v;i++)
	    {
	        if(indeg[i]==0)
	        {
	            q.push(i);
	            ans.push_back(i);
	            
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
	                if(indeg[x]>0)
	                {
	                    indeg[x]--;
	                    if(indeg[x]==0)
	                    {
	                        q.push(x);
	                        ans.push_back(x);
	                    }
	                }
	            }
	        }
	    }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<int> vis(V,0);
	     vector<int> ans,indeg(V,0);
	     for(int i=0;i<V;i++)
	     {
	         for(auto x:adj[i])
	         {
	           indeg[x]++;    
	         }
	     }
	   // for(int i=0;i<V;i++)
	   // {
	   //     if(!vis[i])
	   //     {
	   //         dfs(adj,i,vis,st);
	   //     }
	   // }
	   
	     bfs(adj,V,indeg,ans);
	   
	   // while(!st.empty())
	   // {
	   //     int curr=st.top();
	        
	   //     st.pop();
	   //     ans.push_back(curr);
	   // }
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends