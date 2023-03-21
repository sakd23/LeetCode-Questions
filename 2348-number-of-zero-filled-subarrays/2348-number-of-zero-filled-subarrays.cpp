class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& a) {
        ll ans=0,n=a.size();
       
        for(ll i=0;i<n;i++)
        {
            ll cnt=0;
           while(i<n and a[i]==0)
           {
               i++;
               cnt++;
           }
            if(cnt>0)i--;
            ans=ans+((cnt+1)*cnt)/2;
           
        }
        return ans;
    }
};