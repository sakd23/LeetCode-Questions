class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int dp[n+1][2];
      memset(dp,0,sizeof(dp));
        
        for(int i=n-1;i>=0;i--)
        {
            dp[i][1]=max(a[i]+dp[i+1][0],dp[i+1][1]);
            dp[i][0]=max(dp[i+1][1]-a[i],dp[i+1][0]);
        }
        return dp[0][0];
    }
};