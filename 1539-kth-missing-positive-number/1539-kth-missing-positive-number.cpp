class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
      
        int n=arr.size();
        // arr.push_back(arr[n-1]+1);
        int low=0,high=n-1,mid;
        
        while(low<=high)
        {
            mid=low+(high-low)/2;
            
            if(arr[mid]-mid-1<k)low=mid+1;
            
            else high=mid-1;
        }
        return low+k;
    }
};