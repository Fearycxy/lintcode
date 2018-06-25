class Solution {
public:
    /**
     * @param num: a string
     * @return: true if a number is strobogrammatic or false
     */
    bool isStrobogrammatic(string &num) {
        // write your code here
        int left =0;
        int right = num.size()-1;
        while(left<=right){
            bool f = num[left] == '1' && num[right] =='1';
            f =f || (num[left] == '8' && num[right] == '8');
            f =f || (num[left] == '0' && num[right] == '0');
            if(left<right){
                f =f || (num[left] == '9' && num[right] == '6');
                f =f || (num[left] == '6' && num[right] == '9');
            }
            if(!f) return false;
            left++;
            right--;
        }
        return true;
    }
};
