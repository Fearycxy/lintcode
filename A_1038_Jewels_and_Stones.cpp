class Solution {
public:
    /**
     * @param J: the types of stones that are jewels
     * @param S: representing the stones you have
     * @return: how many of the stones you have are also jewels
     */
    int numJewelsInStones(string &J, string &S) {
        // Write your code here
        int i = 0;
        for(char c:S){
            if(find(J.begin(),J.end(),c) != J.end()){
                i++;
            }
        }
        return i;
    }
};
