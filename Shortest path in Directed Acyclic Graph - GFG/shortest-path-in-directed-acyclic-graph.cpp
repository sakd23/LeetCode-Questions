//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  typedef pair<int,int> pp;
  void dfs(vector<vector<pair<int,int>>>& adj,stack<int>& st,vector<int>& vis,int srt)
  {
      vis[srt]=true;
      for(auto x:adj[srt])
      {
          if(!vis[x.first])dfs(adj,st,vis,x.first);
      }
      st.push(srt);
    //   cout<<srt<<endl;
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int,int>>> adj(N);
        
        for(int i=0;i<M;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        stack<int> st;
        vector<int> vis(N,0),dis(N,1e9);
       
           
            dfs(adj,st,vis,0);
        
        dis[0]=0;
        
        while(!st.empty())
        {
         int cnode=st.top();
         st.pop();
        //  cout<<cnode<<endl;
         for(auto x:adj[cnode])
         {
             int v=x.first;
             int w=x.second;
             
             if(dis[cnode]+w<dis[v])
             {
                 dis[v]=dis[cnode]+w;
             }
         }
        }
        for(int i=0;i<dis.size();i++)
        {
            if(dis[i]==1e9)dis[i]=-1;
        }
         return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends