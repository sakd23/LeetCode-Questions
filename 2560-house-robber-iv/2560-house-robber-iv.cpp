class Solution {
public:
    int minCapability(vector<int>& a, int k) {

        int left=k-1,n=a.size();
        int ans,low=1,high=1e9,mid;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]<=mid)
                {
                    cnt++;
                    i++;
                }
            }
            if(cnt>=k)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};