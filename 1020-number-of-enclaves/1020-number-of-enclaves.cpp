class Solution {
public:
    void dfs(vector<vector<int>>& a,int i,int j)
    {
        if(i>=a.size() or i<0 or j<0 or j>=a[0].size() or a[i][j]==0 or a[i][j]==2)return ;
        a[i][j]=2;
        dfs(a,i+1,j);
        dfs(a,i-1,j);
        dfs(a,i,j-1);
        dfs(a,i,j+1);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int cnt=0;
         for(int i=0;i<grid.size();i++)
     {
         for(int j=0;j<grid[0].size();j++)
         {
             if(grid[i][j]==1)
             {
                 cnt++;
             }
         }
     }
        
        
     for(int i=0;i<grid.size();i++)
     {
         for(int j=0;j<grid[0].size();j++)
         {
             
             if((i==0 or i==grid.size()-1 or j==0 or j==grid[0].size()-1) and grid[i][j]==1)
             {
                 dfs(grid,i,j);
             }
         }
     }
        int ans=0;
        for(int i=0;i<grid.size();i++)
     {
         for(int j=0;j<grid[0].size();j++)
         {
             if(grid[i][j]==2)
             {
                 // cout<<i<<" "<<j<<endl;
                 ans++;
             }
         }
     }
        return cnt-ans;
    }
};