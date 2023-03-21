class Solution {
public:
  
    int numSubseq(vector<int>& a, int tar) {
     sort(a.begin(),a.end());
        int n=a.size(),ans=0;
        int mod=1e9+7;
        
         int p=1;
        int N=1e6;
        int power[N+1];
        power[0]=1;
        for(int i=1;i<=N;i++)
        {
            p=(p*2)%mod;
            power[i]=p;
        }
        
        for(int i=0;i<n;i++)
        {
            int left=tar-a[i];
            int idx=upper_bound(a.begin()+i,a.end(),left)-a.begin();
            idx--;
            int cnt=idx-i;
            if(cnt<0)continue;
            // cout<<a[idx]<<endl;
            ans=(ans+power[cnt])%mod;
            // cout<<ans<<endl;
        }
        return ans;
    }
};