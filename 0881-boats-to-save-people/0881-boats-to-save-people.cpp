class Solution {
public:
    int numRescueBoats(vector<int>& a, int l) {
       int ans=0,cnt=0,srt=0,end=a.size()-1;
        
        sort(a.begin(),a.end());
      while(srt<end)
      {
          if(a[srt]+a[end]<=l)
          {
              srt++;
              end--;
              ans++;
          }
          else
          {
              ans++;
              end--;
          }
          
      }
        if(srt==end)ans++;
        return ans;
    }
};