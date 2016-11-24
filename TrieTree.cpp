class TrieNode {
public:
    // Initialize your data structure here.
    bool isWord;
    TrieNode* childs[26];
    TrieNode(bool end=false) {
        memset(childs,0,sizeof(childs));
        isWord = end;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *t = root;
        int i;
        for(i=0;i<word.size();i++){
            if(t->childs[word[i]-'a']==nullptr)
                break;
            else{
                t = t->childs[word[i]-'a'];
                t->isWord=((i==word.size()-1)?true:t->isWord);
            }
        }
        for(;i<word.size();i++){
            t->childs[word[i]-'a'] = new TrieNode(i==word.size()-1);
            t = t->childs[word[i]-'a'];
        }
        return;
        
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *t = root;
        for(int i=0;i<word.size();i++){
            if(t->childs[word[i]-'a']==nullptr)
                return false;
            t = t->childs[word[i]-'a'];
        }
        return t->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string word) {
        TrieNode *t = root;
        for(int i=0;i<word.size();i++){
            if(t->childs[word[i]-'a']==nullptr)
                return false;
            t = t->childs[word[i]-'a'];
        }
        return true;        
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");