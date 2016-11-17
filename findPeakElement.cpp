class Solution {
public:
    int findPeakElement(vector<int>& a) {
        int len = a.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return 0;
        /*nums.push_back(INT_MIN);
        if(nums[0]>nums[1])
            return 0;
            
        for(int i=1;i<len;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
                return i;
        }
        return len-1;*/
        int low = 0, high = len-1,mid;
        while(low<high){
            mid = (low+high)/2;
            if(a[mid]<a[mid+1])
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};