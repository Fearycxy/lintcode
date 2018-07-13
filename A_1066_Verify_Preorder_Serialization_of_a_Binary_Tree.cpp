class Solution {
public:
    /**
     * @param preorder: a string
     * @return: return a bool
     */
    bool isValidSerialization(string &preorder) {
        // write your code here
        int need = 1,y = 1,n=preorder.size();
        bool connect = false;
        for(char c:preorder){
            if(c == ','){
                connect = false;
            }else if(c == '#') {
                need --;
                connect = false;
            }else if( !connect){
                need++;
                connect = true;
            }
            if(need==0) break;
            y++;
        }
        return y==n;
    }
};
