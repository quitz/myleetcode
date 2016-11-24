/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    map<int, vector<int>> l;
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int ml = maxLayer(nestedList,1);
        //cout<<ml<<endl;
        int res=0;
        for(auto it=l.begin();it!=l.end();it++)
            for(auto it1 = it->second.begin();it1!=it->second.end();it1++)
                res += it->first * (ml-*it1+1);
        
        return res;
    }
    
    int maxLayer(vector<NestedInteger>& nestedList, int layer){
        int len = nestedList.size();
        int max_layer = layer;
        for(int i=0;i<len;i++){
            if(nestedList[i].isInteger())
                l[nestedList[i].getInteger()].push_back(layer);
            else{
                vector<NestedInteger> t =  nestedList[i].getList();
                int ti = maxLayer(t, layer+1);
                max_layer = max(ti,max_layer);
            }
        }
        return max_layer;
    }
};