class Solution {
public:
    
    bool help(vector<int>& candies,long long k,int mid)
    {
        long long cnt=0;
        for(auto x:candies)
        {
            cnt=cnt+(long long)x/mid;
            if(cnt>=k)
            {
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
       int low=1,high=1e7,mid,ans=0;
        
        while(low<=high)
        {
           mid=low+(high-low)/2;
            
            if(help(candies,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};