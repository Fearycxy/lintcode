class ZigzagIterator2 {
public:
vector<int> dp;
vector<int>::iterator it;
    /*
    * @param vecs: a list of 1d vectors
    */ZigzagIterator2(vector<vector<int>>& vecs) {
        // do intialization if necessary
        size_t h = 0;
        for(auto av:vecs) h = max(av.size(),h);
        for(int i =0;i<h;i++){
            for(auto av:vecs){
                if(i<av.size()) dp.push_back(av[i]);
            }
        }
        it = dp.begin();
    }

    /*
     * @return: An integer
     */
    int next() {
        return *it++;
        // write your code here
    }

    /*
     * @return: True if has next
     */
    bool hasNext() {
        return it != dp.end();
        // write your code here
    }
};

/**
 * Your ZigzagIterator2 object will be instantiated and called as such:
 * ZigzagIterator2 solution(vecs);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
