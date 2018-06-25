class Solution {
public:
    /**
     * @param a: The array.
     * @return: The number which has odd number of times or -1.
     */
    int isValid(vector<int> &a) {
        // Write your code here
        unordered_map<int,int> mp;
        for(int y:a) mp[y]++;
        int an = -1;
        for(auto y:mp){
            if(y.second &1 == 1){
                if(an==-1) an = y.first;
                else return -1;
            }
        }
        return an;
    }
};
