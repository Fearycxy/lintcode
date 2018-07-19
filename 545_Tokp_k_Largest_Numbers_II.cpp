class Solution {
public:
multiset<int> mt;
int k;
    /*
    * @param k: An integer
    */Solution(int k) {
        this-> k = k;
        // do intialization if necessary
    }

    /*
     * @param num: Number to be added
     * @return: nothing
     */
    void add(int num) {
        // write your code here
        if(mt.size()<k) mt.insert(num);
        else if(*mt.begin() < num){
            mt.erase(mt.begin());
            mt.insert(num);
        }
    }

    /*
     * @return: Top k element
     */
    vector<int> topk() {
        // write your code here
     return vector<int>(mt.rbegin(),mt.rend());
    }
};
