class Solution {
public:
    long long minimumRemoval(vector<int>& a) {
        sort(a.begin(),a.end());
        if(a.size()==1)return 0;
       
//         for(auto x:a)cout<<x<<" ";
//         cout<<endl;
        int cnt=1,n=a.size();
         long long asum[n];
        asum[0]=a[0];
        
        for(int i=1;i<n;i++)
        {
            asum[i]=asum[i-1]+a[i];
        }
        long long ans=asum[n-2];
        long long ans1=0;
        for(int i=n-1;i>=1;i--)
        {
           
            ans1=ans1+((long long)a[i]-a[i-1])*cnt;
            cnt++;
            long long ans2=0;
            if(i>1)ans2=asum[i-2];
            
            ans=min(ans,ans1+ans2);
           
        }
        return ans;
    }
};