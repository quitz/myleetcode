class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
            
        vector<int> res;
        if(len==0)
            return res;
        if(len == 1){
            if(numbers[0] == target)
                res.push_back(target);
            
            return res;
        }
        
        int i=0,j=len-1;
        /*for(;i<len-1;i++){
            int t = target - numbers[i];
            int temp = findbinary(numbers,i+1,t);
            if(temp!=-1){
                res.push_back(i+1);
                res.push_back(temp+1);
                return res;
            }
        }*/
        while(i<j){
            if(numbers[i] + numbers[j] == target){
                res.push_back(i+1);
                res.push_back(j+1);
                return res;
            }
            else if(numbers[i] + numbers[j] > target)
                j--;
            else
                i++;
        }
        return res;
        
    }
    
    int findbinary(vector<int> a, int start, int t){
        int i=start,j=a.size()-1;
        //cout<<"line35 start: "<<start<<"shengyu: "<<t<<endl;
        while(i<=j){
            int mid = (i+j)/2;
            if(a[mid] == t)
                return mid;
            if(a[mid] > t)
                j = mid-1;
            else
                i = mid + 1;
            
            //cout<<"line 45 i: "<<i<<"j: "<<j<<endl;
        }
        return -1;
    }
};