class Solution {
public:
    int change(int amount, vector<int>& a) {
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++)
        {
            dp[n][i]=0;
        }
        
         for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=amount;j++)
            {
                dp[i][j]=dp[i+1][j];
                if(j>=a[i])dp[i][j]+=dp[i][j-a[i]];
            }
        }
        return dp[0][amount];
        
    }
};