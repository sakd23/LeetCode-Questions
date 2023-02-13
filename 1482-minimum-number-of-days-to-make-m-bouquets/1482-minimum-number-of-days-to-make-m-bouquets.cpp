class Solution {
public:
    
    bool help(vector<int>&a ,int mid,int m,int k)
    {
        int cnt=0;
        for(auto x:a)
        {
            
            if(x<=mid)
            {
                cnt++;
                if(cnt>=k)
                {
                    m--;
                    cnt=0;
                }
                
                if(m<=0)return true;
            }
            else
            {
                cnt=0;
            }
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
       // if((long long)m*k>n)return -1;
        int low=1,high=1e9,mid,ans=-1;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            if(help(bloomDay,mid,m,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
    }
};