class LRUCache {
public:

    list<int> l;
    unordered_map<int, int> m;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // for(auto it:m) {
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        // cout<<"END of 1 op.\n\n\n";
        int count = 0, found = 0;
        for(auto it : l) {
            if(it == key) {
                auto itr = l.begin();
                advance(itr, count);
                itr = l.erase(itr);
                found = 1;
                break;
            }
            count++;
        }
        if(found == 0) {
            return -1;
        } else {
            l.push_front(key);
        }
        if(m.find(key) != m.end()) return m[key];
        return -1;
    }
    
    void put(int key, int value) {
        m[key] = value;
        int count = 0, found = 0;
        for(auto it : l) {
            if(it == key) {
                auto itr = l.begin();
                advance(itr, count);
                itr = l.erase(itr);
                found = 1;
                break;
            }
            count++;
        }
        if(found == 0) {
            int rem = l.back();
            if(l.size() == cap) {
                l.pop_back();
                m.erase(rem);
            }
        }
        l.push_front(key);
        // for(auto it:m) {
        //     cout<<it.first<<" "<<it.second<<"\n";
        // }
        // cout<<"END of 1 op.\n\n\n";
    }
};
