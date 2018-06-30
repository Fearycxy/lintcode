class ZigzagIterator {
public:
vector<int> v;
vector<int>::iterator it;

    /*
    * @param v1: A 1d vector
    * @param v2: A 1d vector
    */ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        // do intialization if necessary
        int m = v1.size(),n = v2.size(),t = max(m,n);
        for(int i=0;i<t;i++){
            if(i<m)v.push_back(v1[i]);
            if(i<n)v.push_back(v2[i]);
        }
        it = v.begin();
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
        return it != v.end();
        // write your code here
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator solution(v1, v2);
 * while (solution.hasNext()) result.push_back(solution.next());
 * Ouptut result
 */
