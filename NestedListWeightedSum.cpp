/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return sum(nestedList,1);
    }
    
    int sum(vector<NestedInteger>& nestedList, int layer){
        int len = nestedList.size();
        int res=0;
        for(int i=0;i<len;i++){
            if(nestedList[i].isInteger())
                res += nestedList[i].getInteger()*layer;
            else{
                vector<NestedInteger> t =  nestedList[i].getList();
                res += sum(t,layer+1);
            }
        }
        return res;
    }
};