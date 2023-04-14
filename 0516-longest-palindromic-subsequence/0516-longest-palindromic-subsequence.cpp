class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(s.begin(),s.end());

         int n1=s.size(),n2=s.size();

      int  dp[n1+1][n2+1];

        for(int i=0;i<=n1;i++)
        {
            dp[i][n2]=0;
        }

        for(int i=0;i<=n2;i++)
        {
            dp[n1][i]=0;
        }

        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(s[i]==t[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};