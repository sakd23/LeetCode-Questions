class Solution {
public:
    int help(string& s,int srt,int end,vector<vector<int>>& dp)
    {
        if(srt>end)return 0;
        
        if(srt==end)return 1;
        if(dp[srt][end]!=-1)return dp[srt][end];
        if(s[srt]==s[end])return dp[srt][end]=2+help(s,srt+1,end-1,dp);
        else return dp[srt][end]=max(help(s,srt+1,end,dp),help(s,srt,end-1,dp));
    }
    int longestPalindromeSubseq(string s) {
       
         int n=s.size();

     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return help(s,0,n-1,dp);
    }
};