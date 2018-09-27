class Solution {
public:
    /**
     * @param s: a string
     * @return: whether the student could be rewarded according to his attendance record
     */
    bool checkRecord(string &s) {
        // Write your code here
        int a = 0, l = 0;
        for(char c:s){
            switch(c){
                case 'A':
                    a++;
                    l=0;
                    if(a==2) return false;
                    break;
                case 'L':
                    l++;
                    if(l==3) return false;
                    break;
                default:
                    l = 0;
                    break;
            }
        }
        return true;
    }
};
