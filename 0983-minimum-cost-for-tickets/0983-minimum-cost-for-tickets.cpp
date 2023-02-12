class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
       int dp[2000];
        memset(dp,0,sizeof(dp));
        int last=days.back();
      int  curr=days.size()-1;
        // dp[last]=min({costs[0],costs[1],costs[2]});
       for(int i=last;i>=1;i--)
       {
           if(i==days[curr])
           {
                dp[i]=costs[0]+dp[i+1];
           dp[i]=min(dp[i],costs[1]+dp[i+7]);
           dp[i]=min(dp[i],costs[2]+dp[i+30]);
              // cout<<i<<" "<<dp[i]<<endl;
               curr--;
               if(curr<0)break;
               continue;
           }
           else
           dp[i]=dp[i+1];

       }
        return dp[days[0]];
    }
};