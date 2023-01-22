class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int prev2=nums[0], curr;
        int prev1=max(nums[0],nums[1]);
        
        for(int i=2;i<n;i++)
        {
           curr=max(prev1,nums[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};