class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=0;
        int curr=(n+1)/2;
        int srt=0;
        for(int i=curr;i<n;i++)
        {
            if(2*a[srt]<=a[i])
            {
                srt++;
            }
        }
        return 2*srt;
    }
};