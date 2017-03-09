class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.size() == 1) return words[0];
        graph g = make_graph(words);
        unordered_map<char, int> degrees = compute_indegree(g);
        int numNodes = degrees.size();
        string order;
        queue<char> toVisit;
        for (auto node : degrees)
            if (!node.second)
                toVisit.push(node.first);
        for (int i = 0; i < numNodes; i++) {
            if (toVisit.empty()) return "";
            char c = toVisit.front();
            toVisit.pop();
            order += c;
            for (char neigh : g[c])
                if (!--degrees[neigh])
                    toVisit.push(neigh);
        }
        return order;
    }
private:
    typedef unordered_map<char, unordered_set<char>> graph;
    
    graph make_graph(vector<string>& words) {
        graph g;
        int n = words.size();
        for (int i = 1; i < n; i++) {
            bool found = false;
            string word1 = words[i - 1], word2 = words[i];
            int l1 = word1.length(), l2 = word2.length(), l = max(l1, l2);
            for (int j = 0; j < l; j++) {
                if (j < l1 && g.find(word1[j]) == g.end())
                    g[word1[j]] = unordered_set<char>();
                if (j < l2 && g.find(word2[j]) == g.end())
                    g[word2[j]] = unordered_set<char>();
                if (j < l1 && j < l2 && word1[j] != word2[j] && !found) {
                    g[word1[j]].insert(word2[j]);
                    found = true;
                }
            }
        }
        return g; 
    }
    
    unordered_map<char, int> compute_indegree(graph& g) {
        unordered_map<char, int> degrees;
        for (auto adj : g) {
            if (!degrees[adj.first]);
            for (char neigh : adj.second)
                degrees[neigh]++;
        }
        return degrees;
    }
};