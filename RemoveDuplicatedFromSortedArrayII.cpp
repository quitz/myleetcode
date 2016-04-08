class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int res = 2; //new length
    if(len <=2 )
        return len;
    for(int i=2;i<len;i++){
        if(nums[i]!=nums[res-1]) //attention : compared with new array rather than nums
            nums[res++] = nums[i];
        else if(nums[i]!=nums[res-2])
            nums[res++] = nums[i];
        else{
            continue;
        }
    }
    return res;
}
    /*int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int res = 0;
    if(len <=2 )
        return len;
        
    vector<int>::iterator it = nums.begin();
    int i=0;
    
    for(;i<nums.size()-2;i++){
        len = nums.size();
        if(nums[i]!=nums[i+1])
            res++;
        else if(nums[i+1] != nums[i+2]){
            res++;
        }
        else{
            int l = 3;
            while(i + l<len && nums[i+l] == nums[i])
                l++;
            nums.erase(it+i+2,it+i+l);
            res +=2;
            if(i+l == len)
                return res;
            else
                i = i+1;
            
        }
    }
    if(i==nums.size()-1){
        if(nums[i] == nums[i-1] && nums[i] == nums[i-2]);
        else
            res++;
    }
    if(i==nums.size()-2){
        if(nums[i] == nums[i+1]){
            if(nums[i] == nums[i-1]);
            else
                res += 2; //attention:+2 not +1!!
        }
        else{
            res++;
            if(nums[i] == nums[i-1] && nums[i] == nums[i-2]);
            else
                res++;
        }
    }
    return res;
}*/
};