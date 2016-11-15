class LRUCache{
public:

    struct cacheEntry{
    public:
        int key;
        int value;
        cacheEntry(int k,int v) :key(k),value(v) {}
    };
    
    LRUCache(int capacity) {
        m_capacity = capacity;
    }   
    
    int get(int key){
        if(m_map.find(key) == m_map.end())
            return -1;
        moveToHead(key);
        return m_map[key]->value;
    }
    
    void set(int key, int value){
        if(m_map.find(key) == m_map.end()){
            cacheEntry c(key,value);
            if(m_list.size()>=m_capacity){
                m_map.erase(m_list.back().key);
                m_list.pop_back();
            }
            m_list.push_front(c);
            m_map[key] = m_list.begin();
            return;
        }
        m_map[key]->value = value;
        moveToHead(key);
    }
    
    
private:
    unordered_map<int, list<cacheEntry>::iterator> m_map;
    list<cacheEntry> m_list;
    int m_capacity;
    
    void moveToHead(int key){
        cacheEntry tc = *m_map[key];
        m_list.erase(m_map[key]);
        m_list.push_front(tc);
        m_map[key] = m_list.begin();
    }
    /*map<int,vector<int>> res;
    int len;
    int used;
    map<int, vector<int>>::iterator it;
    LRUCache(int capacity) {
        len = capacity;
        used = 0;
    }
    
    int get(int key) {
        it = res.find(key);
        if(it == res.end())
            return -1;
        else{
            it->second[1]=0;
            map<int, vector<int>>::iterator it1;
            for(it1=res.begin();it1!=res.end();it1++){
                it1->second[1]++;
            }
            return it->second[0];
        }
    }
    
    void set(int key, int value) {
        if(used<len){
            res[key].push_back(value);
            res[key].push_back(1);
            used++;
        }
        else{
            it=res.begin();
            int m = it->second[0];
            map<int, vector<int>>::iterator it1;
            it1 = it;
            it++;
            for(;it!=res.end();it++){
                if(it->second[0]<m){
                    it1 = it;
                }
            }
            res.erase(it1);
            res[key].push_back(value);
            res[key].push_back(1);
        }
    }*/
    
    
};