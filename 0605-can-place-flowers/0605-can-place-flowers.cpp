class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==1)continue;
            if(i>0 and a[i-1]==1)continue;
            if(i<a.size()-1 and a[i+1]==1)continue;
            a[i]=1;
            ans++;
        }
        return (ans>=n);
    }
};