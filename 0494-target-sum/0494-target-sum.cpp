class Solution {
public:
    int findTargetSumWays(vector<int>& a, int tar) {
        int  n=a.size();
        int tot=0,ans=0;
        for(auto x:a)tot+=x;
        vector<vector<int>> dp(n+1,vector<int>(tot+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=tot;j++)
            {
                
                dp[i][j]=dp[i+1][j];
                if(j>=a[i])dp[i][j]=dp[i][j]+dp[i+1][j-a[i]];
            }
        }
        for(int i=0;i<=tot/2;i++)
        {
            if(abs(i-(tot-i))==abs(tar))ans+=dp[0][i];
        }
        return ans;
    }
};