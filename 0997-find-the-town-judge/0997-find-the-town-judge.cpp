class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
     int a[1005]={0},b[1005]={0};   
     for(auto x:trust)
     {
         a[x[0]]++;
         b[x[1]]++;
         
     }
     int ans=-1;
     for(int i=1;i<=n;i++)
     {
         
         if(a[i]==0 and b[i]==n-1)
         {
             ans=i;
             break;
         }
     }
     return ans;
    }
};