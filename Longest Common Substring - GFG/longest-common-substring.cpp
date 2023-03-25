//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n1, int n2)
    {
        // your code here
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        int ans=0;
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=1+dp[i+1][j+1];
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends