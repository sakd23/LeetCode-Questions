class Solution {
public:
    typedef long long ll;
    long long getDescentPeriods(vector<int>& a) {
        ll ans=0;
        ll n=a.size();
        for(int i=0;i<n;i++)
        {
           ll cnt=1;
          while(i<n-1 and a[i]-a[i+1]==1)
          {
              cnt++;
              i++;
          }
            ans=ans+((cnt+1)*cnt)/2;
            
        }
        return ans;
    }
};