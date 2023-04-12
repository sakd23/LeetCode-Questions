class Solution {
public:
    bool check(vector<int>& a) {
       bool flag=true;
        int cnt=0;
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i]>a[i+1])
            {
                flag=false;
                cnt++;
            }
        }
        if(cnt>1)return false;
        if(!flag)
        {
            if(a.back()<=a[0])flag=true;
        }
        return flag;
    }
};