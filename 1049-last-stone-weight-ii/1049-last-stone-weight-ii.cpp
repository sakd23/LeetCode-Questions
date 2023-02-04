class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
     
        int sum=0;
        for(auto x:stones)sum+=x;
        int n=stones.size();
        bool dp[n][sum+1];
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=sum;j++)
            {
                
                if(j==0){
                     
                     dp[i][j]=true;
                   continue;
                 }
                if(i==n-1)
                {
                    dp[i][j]=false;
                    if(stones[i]==j)dp[i][j]=true;
                     continue;
                }
                 
                
                else
                {
                    dp[i][j]=dp[i+1][j];
                    if(stones[i]<=j)dp[i][j]=(dp[i][j] or dp[i+1][j-stones[i]]);
                    // cout<<dp[i][j]<<" ";
                }
            }
            
        }

        int ans=sum;
        // cout<<sum<<endl;
        for(int i=1;i<=sum/2;i++)
        {
            // cout<<i<<" ";
            // cout<<dp[0][i]<<endl;
            if(dp[0][i]==true)
            {
                ans=min(ans,((sum-i)-i));
            }
        }
        return ans;
    }
};