class Solution {
public:
    vector<int> id;
    void unions(int p, int q){
        int x = find(p);
        int y = find(q);
        id[x] = y;
    }
    
    int find(int i){
        while(i != id[i]){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    int countComponents(int n, vector<pair<int, int>>& edges) {
        id.resize(n);
        for (int i = 0; i < n; i++) 
            id[i] = i;
            
        int count = 0;
        
        for (const auto& edge: edges) {
            int x = find(edge.first);
            int y = find(edge.second);
            if (x != y) {
                unions(edge.first, edge.second);
                count++;
            }
        }
        return n-count;
        
    }
    
    
};