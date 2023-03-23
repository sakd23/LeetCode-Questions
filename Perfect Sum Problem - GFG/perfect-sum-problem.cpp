//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	
	int perfectSum(int num[], int n, int tar)
	{
        // Your code goes here
        //  int n=num.size();
    int dp[n+1][tar+1];
    int mod=1e9+7;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            if(j==0)
            {
                dp[i][j]=1;
            }
            
            if(i==n)
            {
               dp[i][j]=0;  
            }
        }
    }
    
    dp[n][0]=1;
     for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<=tar;j++)
        {
            if(num[i]>j)
            {
                dp[i][j]=dp[i+1][j];
            }
            
            else
            {
                dp[i][j]=(dp[i+1][j]+dp[i+1][j-num[i]])%mod;
            }
        }
         
     }
    return dp[0][tar];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends