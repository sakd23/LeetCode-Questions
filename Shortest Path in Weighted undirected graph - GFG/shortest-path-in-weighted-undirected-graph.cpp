//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
       vector<vector<pair<int,int>>> adj(n+1);
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
       for(int i=0;i<m;i++)
       {
           adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
           adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
       }
       
       q.push({0,1});
       vector<int> dp(n+1,1e9),ans,par(n+1);
       dp[1]=0;
      for(int i=1;i<=n;i++)
      par[i]=i;
       
    //   while(!st.empty())
    //   {
    //         // cout<<"s"<<endl;
    //           auto curr=*(st.begin());
               
    //           int node=curr.second;
    //           int dist=curr.first;
    //       st.erase(curr);
    //     //   cout<<node<<endl;
    //             for(auto x:adj[node])
    //             {
    //                 int cdis=dist+x.second;
                   
    //                 if(cdis<dis[x.first])
    //                 {
                       
    //                     cout<<cdis<<" "<<x.first<<endl;
    //                     st.insert({cdis,x.first});
    //                      dis[x.first]=cdis;
    //                     break;
    //                     dp[x.first]=node;
    //                 }
    //             }
    //   }
    
     while(!q.empty())
        {
           auto curr=q.top();
           int dis=curr.first;
           int node=curr.second;
           q.pop();
           for(auto x:adj[node])
           {
            //   cout<<node<<" "<<x.first<<endl;
               int cdis=dis+x.second;
            //   cout<<cdis<<" "<<node<<" "<<x.first<<endl;
              if(cdis<dp[x.first])
              {
                  
                  q.push({cdis,x.first});
                  dp[x.first]=cdis;
                  par[x.first]=node;
              }
           }
        }
      int child=n;
    //   for(auto x:dp)cout<<x<<endl;
    if(dp[n]==1e9)return {-1};
      while(par[child]!=child)
      {
          
          ans.push_back(child);
          
          child=par[child];
      }
      
      ans.push_back(1);
      reverse(ans.begin(),ans.end());
      
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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