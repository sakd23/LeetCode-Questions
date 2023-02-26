class Solution {
public:
    int minDistance(string a, string b) {
        int n=a.size(),m=b.size();
        int dp[n+1][m+1];
        for(int i=0;i<n;i++)
        {
            dp[i][m]=n-i;
        }
        
         for(int i=0;i<m;i++)
        {
            dp[n][i]=m-i;
        }
        dp[n][m]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(a[i]==b[j]) dp[i][j]=dp[i+1][j+1];
                else
                dp[i][j]=1+min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
            }
        }
        return dp[0][0];
    }
};