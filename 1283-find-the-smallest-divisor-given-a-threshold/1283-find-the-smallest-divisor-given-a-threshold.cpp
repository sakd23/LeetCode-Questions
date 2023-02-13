class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
       int low=1,high=1e6,mid,ans;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            long long sum=0;
            for(auto x:nums)sum=sum+((x+mid-1)/mid);
            
            if(sum<=threshold)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};