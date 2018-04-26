class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer array
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int first = 0;
        for(auto it = A.begin();it!=A.end();it++){
            first ^= *it;
        }
        int one = first & -first;
        int h=0;int w = 0;
         for(auto it = A.begin();it!=A.end();it++){
            if((one & *it) ==0){
                h ^= *it;
            }else{
                w ^= *it;
            }
        }
        vector<int> an;
        an.push_back(h);
        an.push_back(w);
        return an;
    }
};
