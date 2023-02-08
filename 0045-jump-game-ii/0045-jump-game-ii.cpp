class Solution {
public:
    int jump(vector<int>& nums) {
     int step=nums[0],maxrange=step,jumps=0;
        int i=1,n=nums.size();
        if(n==1)return 0;
         if(step>=n-1)
        return 1;
        while(i<n)
        {
            
          step--;
          maxrange=max(maxrange,nums[i]+i);
          if(step==0)
          {
            step=maxrange-i;  
              jumps++;
              if(step+i>=n-1)
              {
                  jumps++;
                  break;
              }
          }
           i++; 
        }
        return jumps;   
    }
};