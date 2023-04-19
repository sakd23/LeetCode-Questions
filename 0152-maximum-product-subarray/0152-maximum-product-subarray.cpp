class Solution {
public:

    int maxProduct(vector<int>& nums) {
      int maxans=INT_MIN,cans=1;
        vector<int> pro,pro2(nums.size(),0);
        int cnt=1;
        for(auto x:nums)
        {
            cnt=cnt*x;
            pro.push_back(cnt);
            if(cnt==0)cnt=1;
            
        }
        cnt=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            cnt=cnt*nums[i];
            pro2[i]=cnt;
            if(cnt==0)cnt=1;
            
        }
        for(auto x:pro)maxans=max(maxans,x);
         for(auto x:pro2)maxans=max(maxans,x);
        return maxans;
    }
};