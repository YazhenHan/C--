#include <iterator>
#include <vector>

using namespace std;

class PeekingIterator : public Iterator {
private:
    vector<int> nums;
    int it;

public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    this->nums = nums;
        it = -1;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nums[it + 1];
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    return nums[++it];
	}
	
	bool hasNext() const {
	    return it + 1 < nums.size();
	}
};