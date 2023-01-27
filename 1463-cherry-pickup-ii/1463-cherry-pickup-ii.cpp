class Solution {
public:
int sign[3]={0,-1,+1};
    int help(vector<vector<int>>& g,int i1,int j1,int i2,int j2,int row,int col,vector<vector<vector<int>>>& dp)
    {
        if(j1>=col or j2>=col or j1<0 or j2<0)return -1e9;

        if(i1==row-1)
        {
            if(j1==j2)return g[i1][j1];
            else return g[i1][j1]+g[i2][j2];
        }
         if(dp[i1][j1][j2]!=-1)return dp[i1][j1][j2];
         int ans=INT_MIN;
        for(int i=0;i<3;i++)
        {
         for(int j=0;j<3;j++)
         {
             ans=max(ans,help(g,i1+1,j1+sign[i],i2+1,j2+sign[j],row,col,dp));
         }
        }
       
        
          int ans3=(j1==j2)?g[i1][j1]:(g[i1][j1]+g[i2][j2]);

          return dp[i1][j1][j2]=ans+ans3;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        vector<vector<vector<int>>> dp(200,vector<vector<int>>(200,vector<int>(200,-1)));
                int row=grid.size(),col=grid[0].size();

        for(int i=0;i<col;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==j)dp[row-1][i][j]=grid[row-1][i];
                else dp[row-1][i][j]=grid[row-1][i]+grid[row-1][j];
            }
        }
        
        for(int i=row-2;i>=0;i--)
        {
            for(int j=0;j<col;j++)
            {
                for(int k=0;k<col;k++)
                {
                    if(j==k)dp[i][j][k]=grid[i][j];
                    else dp[i][j][k]=grid[i][j]+grid[i][k];
                    int ans=-1e8;
                    for(int l=-1;l<2;l++)
                    {
                        for(int m=-1;m<2;m++)
                        {
                            
                            if(j+l>-1 and j+l<col and k+m>-1 and k+m<col)
                            {
//                                 
                                ans=max(ans,dp[i+1][k+m][j+l]);
                            }
                            
                            
                            
                        }
                    }
                    dp[i][j][k]+=ans;
                }
            }
        }
        return dp[0][0][col-1];
    }
};