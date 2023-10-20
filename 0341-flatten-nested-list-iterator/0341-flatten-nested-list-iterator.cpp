class IteratorPair {
private:
    vector<NestedInteger>::iterator currentIterator, endIterator;
public:
    IteratorPair(vector<NestedInteger> &nestedList) {
        currentIterator = nestedList.begin();
        endIterator = nestedList.end();
    }
    
    vector<NestedInteger>::iterator getCurrent() {
        return currentIterator;
    }
    
    vector<NestedInteger>::iterator getEnd() {
        return endIterator;
    }
    
    bool isCompleted() {
        return currentIterator == endIterator;
    }
    
    void increment() {
        currentIterator++;
    }
};

class NestedIterator {
private:
    stack<shared_ptr<IteratorPair>> iteratorStack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        iteratorStack.push(make_shared<IteratorPair>(nestedList));
    }
    
    int next() {
        auto nextPair = getNextPair();
        if (nextPair == nullptr) return -1;
        int value = nextPair->getCurrent()->getInteger();
        nextPair->increment();
        return value;
    }
    
    bool hasNext() {
        auto nextPair = getNextPair();
        if (nextPair == nullptr) return false;
        return true;
    }
private:
    shared_ptr<IteratorPair> getNextPair() {
        while (!iteratorStack.empty()) {
            auto currentTop = iteratorStack.top();
            if (currentTop->isCompleted()) {
                iteratorStack.pop();
            } else {
                if (currentTop->getCurrent()->isInteger()) {
                    return currentTop;
                }
                auto newPair = make_shared<IteratorPair>(currentTop->getCurrent()->getList());
                currentTop->increment();
                iteratorStack.push(newPair);
            }
        }
        return nullptr;
    }
};