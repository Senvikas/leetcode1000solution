struct CacheNode
{
    int key;
    int val;
    long tick;
    int freq;
   	// Defines the order, smaller one will be evicted first
    bool operator < (const CacheNode &rhs) const
    {
        if (freq < rhs.freq)
            return true;
        if (freq == rhs.freq)
            return tick < rhs.tick;
        return false;
    }
};

class LFUCache
{

    public:
        LFUCache(int capacity): capacity_(capacity), tick_(0) {}

    int get(int key)
    {
        auto iter = map_.find(key);
        if (iter == map_.end())
            return -1;	// not found
        int value = iter->second.val;
        touch(iter->second);
        return value;
    }

    void put(int key, int value)
    {
        if (capacity_ == 0)
            return;
        auto iter = map_.find(key);
        if (iter != map_.end())
        {
            iter->second.val = value;
            touch(iter->second);
            return;
        }
        if (capacity_ == cache_.size())
        {
           	// set is ordered, so the first element should be the one to remove
            const CacheNode &toRemoved = *cache_.cbegin();
            map_.erase(toRemoved.key);
            cache_.erase(toRemoved);
        }
        CacheNode newNode
        {
            key,
            value,
            tick_++,
            1
        };
        map_.insert({ key,
            newNode });
        cache_.insert(newNode);
    }

    private:
        int capacity_;
    long tick_;
    unordered_map<int, CacheNode> map_;
    set<CacheNode> cache_;	// std::set is BST, sort CacheNodes
   	// handling update node properties
    void touch(CacheNode & node)
    {
        cache_.erase(node);
        node.freq++;
        node.tick = ++tick_;
        cache_.insert(node);
    }
};