class LFUCache {
public:
    unordered_map<int, list<int>> freq_keyslist;
    unordered_map<int, vector<int>> key_value_freq;
    unordered_map<int, list<int>::iterator> key_iterator;
    int min_freq;
    int size;
    int c;
    
    LFUCache(int capacity) {
        c = capacity;
        size = 0;
        min_freq = 0;
        
    }
    
    int get(int key) {
        if(!key_value_freq.count(key)) return -1;
        
        int value = key_value_freq[key][0];
        int freq = key_value_freq[key][1];
        freq_keyslist[freq].erase(key_iterator[key]);
        
        freq_keyslist[freq+1].push_back(key);
        key_value_freq[key][1]++;
        key_iterator[key] = --freq_keyslist[freq+1].end();
        
        if(!freq_keyslist[min_freq].size()) min_freq++;
        
        return value;
    }
    
    void put(int key, int value) {
        if(c<=0) return;
        
        if(get(key) != -1){
            key_value_freq[key][0] = value;
            return;
        }
        
        if(size==c){
            //remove the element from cache with min freq
            int key_to_remove = freq_keyslist[min_freq].front();
            freq_keyslist[min_freq].pop_front();
            key_value_freq.erase(key_to_remove);
            key_iterator.erase(key_to_remove);
        }
        
        key_value_freq[key] = {value, 1};
        freq_keyslist[1].push_back(key);
        key_iterator[key] = --freq_keyslist[1].end();
        min_freq=1;
        if(size < c) size++;
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */