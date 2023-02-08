class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step=nums[0],maxrange=step;
        int i=1,n=nums.size();
        while(i<n)
        {
            if(i>maxrange)return false;
          step--;
          maxrange=max(maxrange,nums[i]+i);
          if(step==0)
          {
            step=maxrange-i;  
          }
           i++; 
        }
        return true;
    }
};