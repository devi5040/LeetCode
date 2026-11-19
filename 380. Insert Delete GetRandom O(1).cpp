class RandomizedSet {
public:
    unordered_map<int, int> random_set;
    vector<int> elements;
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(random_set.find(val)==random_set.end())
        {
            random_set[val] = elements.size();
            elements.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        int n = elements.size();
        if(random_set.find(val)==random_set.end())
            return false;
        int idx = random_set[val];
        int last = elements.back();
        elements[idx] = last;
        random_set[last] = idx;
        
        random_set.erase(val);
        elements.pop_back();
        return true;
    }
    
    int getRandom() {
        int n = elements.size();
        int index = rand()%n;

        return elements[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
