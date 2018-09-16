class Solution {
public:
    /**
     * @param intervalList: 
     * @param number: 
     * @return: return True or False
     */
    string isInterval(vector<vector<int>> &intervalList, int number) {
        // Write your code here
        for(auto & in:intervalList){
            if(number>=in[0] && number<= in[1]) return "True";
        }
        return "False";
    }
};
