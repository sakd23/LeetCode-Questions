class Solution {
public:
    
    int help(vector<int>& coins,int amt,int idx,vector<vector<int>>& dp)
    {
        
        if(amt==0)
        {
            return 0;
        }
        if(idx==coins.size() or amt<0)
        {
            return 1e5;
        }
        if(dp[idx][amt]!=-1)return dp[idx][amt];
        int pick=1+help(coins,amt-coins[idx],idx,dp);
        int notpick=help(coins,amt,idx+1,dp);
        
        return dp[idx][amt]=min(pick,notpick);
        
    }
    
    int coinChange(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>> dp(coins.size()+1,vector<int>(amt+1,-1));
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=amt;j++)
            {
                if(i==n)
                {
                    dp[i][j]=1e5;
                    continue;
                }
                
                if(j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
                
                dp[i][j]=dp[i+1][j];
                if(j>=coins[i])dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i]]);
                
            }
        }
        // int ans=help(coins,amt,0,dp);
        // if(ans>=1e5)return -1;
        return dp[0][amt]>=1e5?-1:dp[0][amt];
    }
};