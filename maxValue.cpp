struct Iteminfo{
    string name;
    int value;
    int maximum_stack_size;
};

class solution{
    public:
    int maxValue(int n, vector<string> obj, vector<Iteminfo*> item){
        int ret = 0;
        map<string,int> mp;
        map<string,int> val;
        map<string,int> limit;
        
        for(auto i: obj)
            mp[i]++;
        
        for(auto i:item){
            val[i->name] = i->value;
            limit[i->name] = i->maximum_stack_size;
        }
        
        priority_queue<int> pq;
        for(auto it = mp.begin();it!= mp.end();it++){
            string na = it->first;
            int num = it->second;
            int max_size = limit[na];
            int v = val[na];
            
            int times = num / max_size;
            int left = num % max_size;
            for(int j=0;j<times;j++)
                pq.push(v*max_size);
            if(left!=0)
                pq.push(v*left);
            
        }
        int i=1;
        while(!pq.empty() && i<=n){
            ret += pq.top();
            pq.pop();
            i++;
        }
        
        return ret;
    }
};
};