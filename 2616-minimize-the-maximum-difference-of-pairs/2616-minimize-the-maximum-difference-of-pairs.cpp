class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
      int ans, low=0,high=1e9,mid;
        sort(a.begin(),a.end());
        
        while(low<=high)
            
        {
            mid=low+(high-low)/2;
            int cnt=0;
            for(int i=0;i<a.size()-1;i++)
            {
                if(a[i+1]-a[i]<=mid)
                {
                    cnt++;
                    i++;
                }
            }
            if(cnt>=p)
            {
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};