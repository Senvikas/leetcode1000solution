class SmallestInfiniteSet
{
    int smallest_;
    priority_queue<int, std::vector < int>, std::greater < int>> q_;
    unordered_set<int> s_;
    public:
        SmallestInfiniteSet(): smallest_
        { 1 } {}

    int popSmallest()
    {
        if (!q_.empty())
        {
            int el = q_.top();
            q_.pop();
            s_.erase(el);
            return el;
        }
        else
        {
            return smallest_++;
        }
    }

    void addBack(int num)
    {
        if (num < smallest_ && s_.find(num) == end(s_))
        {
            s_.insert(num);
            q_.push(num);
        }
    }
};

/**
 *Your SmallestInfiniteSet object will be instantiated and called as such:
 *SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 *int param_1 = obj->popSmallest();
 *obj->addBack(num);
 */