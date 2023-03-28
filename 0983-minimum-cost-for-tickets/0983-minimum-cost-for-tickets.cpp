class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(500,0);
        int n=days.size(),idx=n-1;
        for(int i=365;i>=1;i--)
        {
            
            
            if(idx>=0 and days[idx]==i)
            {
               dp[i]=min({costs[0]+dp[i+1],costs[1]+dp[i+7],costs[2]+dp[i+30]});
             idx--;
            }
            else dp[i]=dp[i+1];
        }
        return dp[1];
    }
};