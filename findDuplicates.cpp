class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        
        for(int i=0;i<nums.size();i++){
            int index = abs(nums[i]) - 1;
            if(nums[index]<0)
                ret.push_back(index + 1);
            nums[index] = -nums[index];
            
        }
        return ret;
    }

    char* StrStr(const char *str, const char *target) {
        char* ret;
        if(!*target)
            return str;
        char *pbegin = str;
        while(*!pbegin){
            char *t = pbegin, *t1 = target;
            while(*t && *t1 && *t == *t1){
                t++;
                t1++;
            }
            if(!*t1)
                return pbegin;
            else
                pbegin++;
        }
        return nullptr;
    }
};