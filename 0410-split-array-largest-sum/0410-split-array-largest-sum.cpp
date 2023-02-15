class Solution {
public:
    bool help(vector<int>& a,int k,long long mid)
    {
        long long cnt=1,sum=0;
        
        for(int i=0;i<a.size();i++)
        {
            long long x=a[i];
            if(sum+x>mid)
            {
                sum=x;
                cnt++;
            }
            else
            {
                            sum=sum+x;

            }
        }
        return ((cnt<=k)?true:false); 
    }
    int splitArray(vector<int>& nums, int k) {
        long long sum=0,ele=0;
        for(auto x:nums)
        {
            sum=sum+(long long)x;
            ele=max(ele,(long long)x);
        }
        long long low=ele,high=sum,mid,ans;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            if(help(nums,k,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};