class LRUCache {
public:

    list<int> l;
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // for(auto it:m) {
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        // cout<<"END of 1 op.\n\n\n";
        
        if(m.find(key) != m.end()) {
            list<int>::iterator itr = m[key].second;
            l.erase(itr);
            l.push_front(key);
            m[key].second = l.begin();
            return m[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()) {
            list<int>::iterator itr = m[key].second;
            l.erase(itr);
        } else {
            if(l.size()==cap) {
                int remKey = l.back();
                l.pop_back();
                m.erase(remKey);
            }
        }
        l.push_front(key);
        m[key].first = value;
        m[key].second = l.begin();
        // for(auto it:m) {
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        // cout<<"END of 1 op.\n\n\n";
    }
};
