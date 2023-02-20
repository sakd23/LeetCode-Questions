class Solution {
public:
    int minOperations(int n) {
        if(n<=0)return 0;
        if(n==1)return 1;
        
        int x=1;
        
        while(x*2<n)x*=2;
        
        int y=n-x;
        x=2*x-n;
        
        return 1+min(minOperations(x),minOperations(y));
    }
};