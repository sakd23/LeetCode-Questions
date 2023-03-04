class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& a, int mink, int maxk) {
     ll ans=0,currmin=-1,currmax=-1,srt=0;
        map<ll,ll> map;
        for(int i=0;i<a.size();i++)
        {
            
           if(a[i]<mink or a[i]>maxk)srt=i+1;
            if(a[i]==mink)currmin=i;
            if(a[i]==maxk)currmax=i;
   ans+=max(0ll,min(currmin,currmax)-srt+1);
           
            
        }
        return ans;
    }
};