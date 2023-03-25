//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> dp(n+1);
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=n;j++)
            {
                // dp[i][j]=dp[i+1][j];
                
                if(j>=(i+1))
                {
                    dp[j]=max(dp[j],price[i]+dp[j-(i+1)]);
                }
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends