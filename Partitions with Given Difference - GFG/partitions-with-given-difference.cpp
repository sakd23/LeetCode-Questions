//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& a) {
        // Code here
        int sum=0,ans=0;
        int mod=1e9+7;
        for(auto x:a)sum+=x;
        
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=sum;j++)
            {
                dp[i][j]=dp[i+1][j];
                if(j>=a[i])dp[i][j]=(dp[i][j]+dp[i+1][j-a[i]])%mod;
            }
        }
        for(int i=0;i<=sum/2;i++)
        {
            if(sum-2*i==d)ans=(ans+dp[0][i])%mod;
        }
        return (ans)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends