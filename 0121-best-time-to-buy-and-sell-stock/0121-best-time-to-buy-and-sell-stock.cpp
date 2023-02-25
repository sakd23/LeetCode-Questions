class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=INT_MAX,ans=0;
        
        for(auto x:prices)
        {
            buy=min(buy,x);
            ans=max(ans,x-buy);
        }
        return ans;
    }
};