class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        int n=a.size(),ans=0;
        sort(a.begin(),a.end());
        int curr=a[0]+1;
       for(int i=1;i<n;i++)
       {
           if(curr<=a[i])
           {
               
               curr=a[i]+1;
           }
           else {
               ans=ans+(curr-a[i]);
               curr++;
           }
       }
        return ans;
    }
};