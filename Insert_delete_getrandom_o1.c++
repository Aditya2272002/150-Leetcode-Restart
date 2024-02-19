class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> vec;

public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        mp[val]=vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0) return false;

        int curPos=mp[val], lastPos=vec.size()-1;
        vec[curPos]=vec[lastPos];  
        mp[vec[lastPos]]=curPos;

        vec.pop_back();
        mp.erase(val);
        return true;
    }

    
    int getRandom() {
        return vec[rand()%mp.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
