class Solution {
public:
    /*
     * @param A: an integer array
     * @param k: a postive integer <= length(A)
     * @param targer: an integer
     * @return: A list of lists of integer
     */
    vector<vector<int>> kSumII(vector<int> &A, int k, int target) {
        // write your code here
        vector<vector<int>> tem;
        tem.push_back(vector<int>());
        if (target < 0) {
            return tem;
        }
        map<int,vector<vector<int>>> mp[k+1];
        int len = A.size();
        mp[0][0].push_back(vector<int>());
        for(int i = 0; i < A.size(); ++i)
            for(int j = k; j > 0; j--)
                for(int l = target; l >= A[i]; l--) {
                    if(!mp[j].count(l)){
                        tem.clear();
                        mp[j][l] =tem;
                    }
                    for(vector<int> dit:mp[j-1][l-A[i]]){
                        dit.push_back(A[i]);
                        mp[j][l].push_back(dit);
                    }
                }
        if(!mp[k].count(target)){
            return tem;
        }
        return mp[k][target];
    }
};
