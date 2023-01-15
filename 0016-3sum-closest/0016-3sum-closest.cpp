class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int ans=nums[0]+nums[1]+nums[2];
        
       for(int i=0;i<n-2;i++)
       {
          
           int second=i+1,last=n-1;
           int sum=0;
           while(second<last)
           {
              sum=nums[i]+nums[second]+nums[last];
               if(abs(sum-target)<abs(ans-target))ans=sum;
               
               if(sum>target)
               {
                   last--;
               }
               else if(sum<target)
               {
                   second++;
               }
               else
               {
                   return sum;
               }
           }
           
       }
        
        return ans;
    }
};