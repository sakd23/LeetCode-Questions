class Solution {
public:
    int maxScore(vector<int>& a) {
       sort(a.begin(),a.end());
        long long n=a.size(),i,sum=0,ans=0;
        for( i=n-1;i>=0;i--)
        {
            if(a[i]<=0)break;
            sum+=a[i];
            ans++;
        }
        
        if(sum==0)
        {
            return 0;
        }
        for(;i>=0;i--)
        {
            
            if(sum+a[i]<=0)break;
            sum+=a[i];
            ans++;
            // cout<<sum<<endl;
        }
        return ans;
        
    }
};