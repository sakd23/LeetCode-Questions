class Solution {
public:
    int change(int amt, vector<int>& a) {
        int n=a.size();
       vector<int> dp(amt+1,0);
        dp[0]=1;
        
        for(auto x:a)
        {
            for(int  i=x;i<=amt;i++)
            {
                dp[i]+=dp[i-x];
            }
        }
        return dp[amt];
    }
};