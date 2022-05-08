
// 2022.5.8

/*
recursion
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    
    int i;
    vector<int> flattened;
    
    void flatten(NestedInteger &ni) {
        if (ni.isInteger())
            flattened.push_back(ni.getInteger());
        else
            for (NestedInteger &nni : ni.getList())
                flatten(nni);
    }

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        i = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            flatten(nestedList[i]);
        }
    }
    
    int next() {
        return flattened[i++];
    }
    
    bool hasNext() {  // though not required, it should be immutable (can be called arbitrary times) from my point of view 
        return i < flattened.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

/*
Runtime: 29 ms, faster than 19.68% of C++ online submissions for Flatten Nested List Iterator.
Memory Usage: 13.2 MB, less than 53.03% of C++ online submissions for Flatten Nested List Iterator.
*/
