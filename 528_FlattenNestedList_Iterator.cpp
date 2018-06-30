/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
vector<int> vec;
vector<int>::iterator it;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        for(auto f:nestedList){
            if(f.isInteger()){
                vec.push_back(f.getInteger());
            }else{
                auto u = f.getList();
                auto h = NestedIterator(u);
                vector<int > tem = h.vec;
                vec.insert(vec.end(),tem.begin(),tem.end());
            }
        }
        it = vec.begin();
    }

    // @return {int} the next element in the iteration
    int next() {
        return *it++;
        // Write your code here
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        return it != vec.end();
        // Write your code here
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
