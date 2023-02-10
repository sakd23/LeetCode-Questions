class Solution {
public:
    int maxValue(int n, int index, int msum) {
        
        long long left=(long long)1,right=(long long)msum,mid,ans=(long long)1;
        
        while(left<=right)
        {
            mid=left+(right-left)/2;
           
            long long leftover=mid-(index+1),leftover2=mid-(n-index),total=0;
            
             if(mid-(index+1)<=0)
            {
                total=(index+1)-mid;
                leftover=0;
            }
            if(mid-(n-index)<=0)
            {
              total=total-mid+(n-index);  
                leftover2=0;
            }
            long long sum=(mid*(mid+1))-((leftover*(leftover+1))/2)-mid-((leftover2*(leftover2+1))/2)+total;
           
            if(sum<=(long long)msum)
            {
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};