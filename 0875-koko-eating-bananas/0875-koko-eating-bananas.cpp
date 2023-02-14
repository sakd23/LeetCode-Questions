class Solution {
public:
    
    bool help(vector<int>& piles,int h,long long mid)
    {
        for(auto x:piles)
        {
            h=h-(x+mid-1)/mid;
            if(h<0)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum=0;
        for(auto x:piles)sum=sum+(long long)x;
        
        long long low=1,high=sum,mid,ans;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            if(help(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};