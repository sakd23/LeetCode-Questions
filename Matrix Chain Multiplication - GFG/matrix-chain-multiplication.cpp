//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int help(int a[],int n,int i,int j,vector<vector<int>>& dp)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int curr=a[i-1]*a[k]*a[j]+help(a,n,i,k,dp)+help(a,n,k+1,j,dp);
        ans=min(ans,curr);
    }
    return dp[i][j]=ans;
}
    int matrixMultiplication(int n, int a[])
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(a,n,1,n-1,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends