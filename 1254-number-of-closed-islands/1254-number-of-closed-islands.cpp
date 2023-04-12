class Solution {
public:
    void help(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>& vis)
    {
        
        if(  i<0 or j<0 or i>=n or j>=m or vis[i][j]==1 or grid[i][j]==2 or grid[i][j]==1)
        {
            return;
        }
        
        vis[i][j]=1;
        grid[i][j]=2;
        help(grid,i+1,j,n,m,vis);
        help(grid,i,j-1,n,m,vis);
        help(grid,i,j+1,n,m,vis);
        help(grid,i-1,j,n,m,vis);
        
    }
    
     
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
       vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 or j==0 or i==n-1 or j==m-1) and !vis[i][j] and grid[i][j]==0)
                {
                    help(grid,i,j,n,m,vis);
                }
            }
        }
        
        int ans=0;
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if( !vis[i][j] and grid[i][j]==0)
                {
                    help(grid,i,j,n,m,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};