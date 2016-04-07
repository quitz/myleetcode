class Solution {
public:
void sortColors(vector<int>& nums) {
    int len = nums.size();
    if(len == 0 || len == 1)
        return;
    int idx0 = 0, idx1 = 0;
   
    for(int i=0;i<len;i++){
        if(nums[i]==0){
            nums[i] = 2;
            nums[idx1++] = 1;
            nums[idx0++] = 0;
        }
        else if(nums[i]==1){
            nums[i] = 2;
            nums[idx1++] = 1;
        }
    }
        
        return;
    }
/*void sortColors(vector<int>& nums) {
    int len = nums.size();
    if(len == 0 || len == 1)
        return;
    int r=-1, w=-1, b=-1;
    
    for(int i=0;i<len;i++){
        if(nums[i] == 0){
            r = 0;
            if(w==-1 && b==-1)
                continue;
            else if(w==-1)
                swap(nums[b++],nums[i]);
            else if(b==-1)
                swap(nums[w++],nums[i]);
            else{
                swap(nums[w],nums[b]);
                swap(nums[i],nums[w]);
                w++;
                b++;
            }
        }
        else if(nums[i] == 1){
            if(w==-1 && b==-1){
                w = i;
                continue;
            }
            else if(w==-1)
                w = b;
            else if(b==-1)
                continue;
            
            swap(nums[b],nums[i]);
            b++;
        }
        else
            if(b==-1)
                b = i;
    }
    return;
    
}*/
    /*void sortColors(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1)
            return;
        map<int, int> res;
        vector<int> re;
        for(int i=0;i<len;i++)
            res[nums[i]]++;
        map<int, int>::iterator it;
        for(it = res.begin();it!=res.end();it++)
            for(int i=0;i<it->second;i++)
                re.push_back(it->first);
        
        nums.clear();
        nums.assign(re.begin(),re.end());
        return;
        
    }*/
};