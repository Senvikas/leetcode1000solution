class MyHashSet {
public:
    MyHashSet(int hashSize = 193939) : _hashSet(hashSize), _hashSize(hashSize) { }
    
    void add(int key) {
        _hashSet[key % _hashSize] = true;
    }
    
    void remove(int key) {
        _hashSet[key % _hashSize] = false;
    }
    
    bool contains(int key) {
        return _hashSet[key % _hashSize];
    }

private:
vector<bool> _hashSet;
int _hashSize;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */