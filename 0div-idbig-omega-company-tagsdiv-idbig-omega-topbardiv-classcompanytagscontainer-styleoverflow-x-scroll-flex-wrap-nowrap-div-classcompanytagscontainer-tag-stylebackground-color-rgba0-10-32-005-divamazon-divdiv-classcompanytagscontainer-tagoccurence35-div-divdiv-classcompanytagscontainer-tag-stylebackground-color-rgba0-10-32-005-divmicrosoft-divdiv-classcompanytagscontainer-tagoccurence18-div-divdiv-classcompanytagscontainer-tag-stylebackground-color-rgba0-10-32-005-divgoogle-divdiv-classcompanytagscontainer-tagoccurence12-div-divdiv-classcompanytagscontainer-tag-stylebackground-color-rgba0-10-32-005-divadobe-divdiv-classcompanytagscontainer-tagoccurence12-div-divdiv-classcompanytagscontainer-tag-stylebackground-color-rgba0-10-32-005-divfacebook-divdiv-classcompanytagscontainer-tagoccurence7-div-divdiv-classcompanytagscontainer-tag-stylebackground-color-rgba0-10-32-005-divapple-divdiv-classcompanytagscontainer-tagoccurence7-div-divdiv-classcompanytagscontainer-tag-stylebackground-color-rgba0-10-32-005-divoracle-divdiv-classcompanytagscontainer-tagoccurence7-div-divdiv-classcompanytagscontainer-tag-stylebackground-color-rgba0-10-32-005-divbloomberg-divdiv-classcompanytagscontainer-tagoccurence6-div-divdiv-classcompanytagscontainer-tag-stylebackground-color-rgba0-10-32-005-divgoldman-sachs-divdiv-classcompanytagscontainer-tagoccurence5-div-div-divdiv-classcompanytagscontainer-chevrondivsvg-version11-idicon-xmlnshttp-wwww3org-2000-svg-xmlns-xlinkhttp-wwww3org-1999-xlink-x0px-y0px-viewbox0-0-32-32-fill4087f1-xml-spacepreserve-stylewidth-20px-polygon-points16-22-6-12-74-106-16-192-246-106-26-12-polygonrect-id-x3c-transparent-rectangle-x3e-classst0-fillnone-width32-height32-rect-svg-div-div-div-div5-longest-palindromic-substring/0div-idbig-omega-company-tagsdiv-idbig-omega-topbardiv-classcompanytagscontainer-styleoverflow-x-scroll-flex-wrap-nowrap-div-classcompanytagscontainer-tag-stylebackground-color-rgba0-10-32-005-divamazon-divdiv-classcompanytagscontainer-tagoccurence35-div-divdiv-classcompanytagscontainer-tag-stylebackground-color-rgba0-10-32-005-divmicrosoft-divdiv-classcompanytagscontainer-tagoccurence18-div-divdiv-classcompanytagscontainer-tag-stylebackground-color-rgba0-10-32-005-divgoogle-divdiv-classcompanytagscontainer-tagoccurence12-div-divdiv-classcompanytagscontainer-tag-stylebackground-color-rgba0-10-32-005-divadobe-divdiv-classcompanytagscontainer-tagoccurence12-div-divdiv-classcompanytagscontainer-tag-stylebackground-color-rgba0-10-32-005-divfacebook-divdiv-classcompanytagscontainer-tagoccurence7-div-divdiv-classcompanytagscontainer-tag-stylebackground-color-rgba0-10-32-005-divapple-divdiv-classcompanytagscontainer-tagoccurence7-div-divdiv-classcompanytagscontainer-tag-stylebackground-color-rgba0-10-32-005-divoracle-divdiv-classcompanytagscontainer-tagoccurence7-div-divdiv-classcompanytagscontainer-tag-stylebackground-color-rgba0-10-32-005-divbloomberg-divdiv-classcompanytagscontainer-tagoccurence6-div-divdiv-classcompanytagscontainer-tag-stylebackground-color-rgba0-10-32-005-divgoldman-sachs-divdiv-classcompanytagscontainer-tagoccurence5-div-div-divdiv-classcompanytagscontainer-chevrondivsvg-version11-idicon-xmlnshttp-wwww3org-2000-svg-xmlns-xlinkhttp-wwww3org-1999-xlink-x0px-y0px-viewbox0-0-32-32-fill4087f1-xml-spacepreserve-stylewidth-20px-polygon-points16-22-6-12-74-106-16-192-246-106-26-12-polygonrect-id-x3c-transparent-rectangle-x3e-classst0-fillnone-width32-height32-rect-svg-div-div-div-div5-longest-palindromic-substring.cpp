class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string str;
        vector<vector<int>>dp(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1]){
                
                dp[i][i+1]=1;
            }
        }
        for(int i=2;i<n;i++)
        {
            for(int j=0;j<n and j+i<n;j++)
                
            {
                if(s[j]==s[j+i] and dp[j+1][j+i-1]){
                    dp[j][j+i]=1;
                    ans=max(ans,i);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=i and dp[i][j] and ans<(j-i+1))
                {
                    ans=j-i+1;
                    str=s.substr(i,j-i+1);
                }
            }
        }
        return str;
    }
};