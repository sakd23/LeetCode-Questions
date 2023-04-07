//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
typedef pair<int,int> pp;
pp help(string s,int srt,int end,vector<vector<vector<int>>>& dp)
{
    if(srt>end)
    {
        return {0,0};
    }
    if(srt==end)
    {
        if(s[srt]=='T')
        {
          return {1,0};       
        }
        
     return {0,1};
    }
    if(dp[srt][end][0]!=-1)
    {
        return {dp[srt][end][0],dp[srt][end][1]};
    }
    int tans=0,fans=0;
    for(int i=srt;i<=end-2;i+=2)
    {
        pp left=help(s,srt,i,dp);
        pp right=help(s,i+2,end,dp);
        int lt=left.first;
        int lf=left.second;
        int rt=right.first;
        int rf=right.second;
        
        if(s[i+1]=='&')
        {
            tans=(tans+lt*rt)%1003;
            fans=(fans+rf*lf+rt*lf+rf*lt)%1003;
        }
        
        if(s[i+1]=='|')
        {
            tans=(tans+lt*rt+lt*rf+lf*rt)%1003;
            fans=(fans+rf*lf)%1003;
        }
          if(s[i+1]=='^')
        {
            fans=(fans+lt*rt+lf*rf)%1003;
            tans=(tans+rt*lf+rf*lt)%1003;
        }
        
    }
    dp[srt][end][0]=tans;
    dp[srt][end][1]=fans;
    return {tans,fans};
}
    int countWays(int N, string S){
        // code here
        
vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(N+1,vector<int>(2,-1)));
return help(S,0,N-1,dp).first;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends