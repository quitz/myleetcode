/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return node;
        map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        UndirectedGraphNode *tmp = new UndirectedGraphNode(node->val);
        mp[node] = tmp;
        queue<UndirectedGraphNode*> q;
        q.push(node);

        while(!q.empty()){
            UndirectedGraphNode *t = q.front();
            q.pop();
            for(auto item: t->neighbors){
                if(mp.find[item] == mp.end()){
                    UndirectedGraphNode *nt = new UndirectedGraphNode(item->val);
                    mp[item] = nt;
                    q.push(t);
                }
                mp[t]->neighbors.push_back(mp[item])
            }
        }
        return tmp;
    }
private:
    
};