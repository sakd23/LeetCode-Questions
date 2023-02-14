class Solution {
public:
    bool help(vector<int>& w,int days,int mid)
    {
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            if(sum+w[i]>mid)
            {
                days--;
                sum=0;
                i--;
                if(days==0)
                 return false;
            }
            else sum+=w[i];
            
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto x:weights)sum+=x;
        int low=1,high=sum,mid,ans;
       while(low<=high)
        {
          mid=low+(high-low)/2;
           
           if(help(weights,days,mid))
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