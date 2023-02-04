class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum=0,n=a.size();
        for(auto x:a)
        {
            sum+=x;
        }
        
        if((sum&1)==1)return false;
        sum/=2;
        bool dp[n][sum+1];
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j==0)
                {
                    dp[i][j]=true;
                    continue;
                }
                if(i==n-1)
                {
                 dp[i][j]=false;
                 if(j==a[i])  dp[i][j]=true;  
                    continue;   
                }
                
                dp[i][j]=dp[i+1][j];
                if(a[i]<=j)
                dp[i][j]=dp[i][j] or dp[i+1][j-a[i]];
            }
        }
        return dp[0][sum];
        
    }
};