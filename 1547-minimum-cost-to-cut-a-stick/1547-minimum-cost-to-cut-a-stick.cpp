class Solution {
public:
int help(vector<int>& a,int i,int j,vector<vector<int>>& dp,int n)
{
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
       for(int k=i;k<=j;k++)
       {
           
         
           int curr=a[j+1]-a[i-1]+help(a,i,k-1,dp,n)+help(a,k+1,j,dp,n);
           ans=min(ans,curr);
       }
    return dp[i][j]=ans;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return help(cuts,1,c,dp,n);
    }
};