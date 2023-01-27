class Solution {
public:
    int help(vector<vector<int>>& a,int i,int j,int row,int col,vector<vector<int>>& dp)
    {
        if(j>=col or j<0)return INT_MAX;
        
        if(i==row-1)return a[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j]=a[i][j]+min({help(a,i+1,j-1,row,col,dp),help(a,i+1,j+1,row,col,dp),help(a,i+1,j,row,col,dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int ans=1e9;
        int row=matrix.size(),col=matrix[0].size();
        vector<int> curr(200),next(200);
        
        for(int i=row-1;i>=0;i--)
        {
            for(int j=0;j<col;j++)
            {
                curr[j]=matrix[i][j];
                if(i<row-1)
                {
                    int currmin=next[j];
                   
                    if(j>0)currmin=min(currmin,next[j-1]);
                    if(j<col-1)currmin=min(currmin,next[j+1]);
                    curr[j]+=currmin;
                }
                if(i==0)
                {
                    ans=min(ans,curr[j]);
                }
            }
            next=curr;
            
        }
        
       
        return ans;
         
        
    }
};