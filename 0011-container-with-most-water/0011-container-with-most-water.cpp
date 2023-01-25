class Solution {
public:
    int maxArea(vector<int>& h) {
        int n=h.size();

        int l=0,r=n-1;
         int ans=0;
        while(l<r)
        {
            int currh=min(h[r],h[l]);
            ans=max(ans,(r-l)*currh);

            if(h[r]<h[l])r--;
            else l++;
        }
        return ans;
    }
};