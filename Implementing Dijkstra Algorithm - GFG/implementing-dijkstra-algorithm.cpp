//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        set<pair<int,int>> st;
        st.insert({0,s});
        
        vector<int> dp(v,1e9);
        dp[s]=0;
        
        while(!st.empty())
        {
           auto curr=*(st.begin());
           int dis=curr.first;
           int node=curr.second;
           st.erase(curr);
           for(auto x:adj[node])
           {
               int cdis=dis+x[1];
               
              if(cdis<dp[x[0]])
              {
                  if(dp[x[0]]!=1e9)
                  {
                      st.erase({dp[x[0]],x[0]});
                       
                  }
                  st.insert({cdis,x[0]});
                  dp[x[0]]=cdis;
              }
           }
        }
        return dp;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends