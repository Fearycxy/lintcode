class Solution {
public:
    /**
     * @param ghosts: a 2D integer array
     * @param target: a integer array
     * @return: return boolean
     */
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target) {
        // write your code here
        int dist = abs(target[0]) + abs(target[1]);
        for(auto t:ghosts)
            if(abs(t[0] - target[0]) + abs(t[1] - target[1]) <= dist) 
                return false;
        return true;
    }
};
