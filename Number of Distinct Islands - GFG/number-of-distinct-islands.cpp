//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>>& grid,int i,int j,vector<pair<int,int>>& curr,int row,int col,pair<int,int>& par,vector<vector<bool>>& vis)
   {
       if(i>=row or j>=col or i<0 or j<0 or vis[i][j] or grid[i][j]!=1)
       {
           return;
       }
       curr.push_back({i-par.first,j-par.second});
       vis[i][j]=true;
       dfs(grid,i+1,j,curr,row,col,par,vis);
       dfs(grid,i-1,j,curr,row,col,par,vis);
       dfs(grid,i,j+1,curr,row,col,par,vis);
       dfs(grid,i,j-1,curr,row,col,par,vis);
   }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row=grid.size(),col=grid[0].size();
        set<vector<pair<int,int>>> st;
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    vector<pair<int,int>> curr;
                    pair<int,int> par={i,j};
                    dfs(grid,i,j,curr,row,col,par,vis);
                    st.insert(curr);
                }
            }
        }
    
        return st.size();
    }
    
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends