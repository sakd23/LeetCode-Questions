class Solution {
public:
    int change(int amt, vector<int>& a) {
        int n=a.size();
       vector<int> dp(amt+1,0);
        dp[0]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            int x=a[i];
            for(int  i=x;i<=amt;i++)
            {
                dp[i]+=dp[i-x];
                if(i==amt)
                {
                    cout<<x<<" "<<dp[i]<<endl;
                }
            }
        }
        return dp[amt];
    }
};