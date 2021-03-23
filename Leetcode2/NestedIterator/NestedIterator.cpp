#include <vector>
#include <queue>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    queue<int> ans;
    void getAns(const vector<NestedInteger> &nestedList) {
        for (auto nested : nestedList)
            if (nested.isInteger())
                ans.push(nested.getInteger());
            else
                getAns(nested.getList());
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        getAns(nestedList);
    }
    
    int next() {
        int tem = ans.front();
        ans.pop();
        return tem;
    }
    
    bool hasNext() {
        return !ans.empty();
    }
};