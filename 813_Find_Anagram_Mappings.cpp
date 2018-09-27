class Solution {
public:
    /**
     * @param A: lists A
     * @param B: lists B
     * @return: the index mapping
     */
    vector<int> anagramMappings(vector<int> &A, vector<int> &B) {
        // Write your code here
        unordered_map<int,queue<int>>mp;
        for(int i =0;i<B.size();i++){
            mp[B[i]].push(i);
        }
        vector<int> an;
        for(int i:A){
            an.push_back(mp[i].front());
            mp[i].pop();
        }
        return an;
    }
};
