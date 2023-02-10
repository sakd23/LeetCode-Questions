class Solution {
public:
    int maxValue(int n, int index, int msum) {
       
        long long left=(long long)1,right=(long long)msum,mid,ans=(long long)1;
        
        while(left<=right)
        {
            mid=left+(right-left)/2;
           
            long long a=max(1ll,mid-index),b=mid,a1=max(1ll,mid-(n-1-index)),b1=mid,total=0;
            
             if(mid<=(index+1))total=(index+1)-mid;
            if(mid<=((n)-index))total=total-(mid-((n)-index));
            long long sum=((((a+b)*(b-a+1))/2)+(((a1+b1)*(b1-a1+1))/2))-mid+(total);
           
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