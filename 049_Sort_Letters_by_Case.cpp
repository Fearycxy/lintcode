class Solution {
public:

bool isUpper(char c){
        return c>='A'&&c<='Z';
}

    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
    void sortLetters(string &chars) {
        // write your code here
        int n = chars.size();
        int first=-1;
        for(int i =0;i<n;i++){
            char t = chars[i];
            if(isUpper(t)){
                if(first<0){
                    first = i;
                }
            }else{
               if(first>=0){
                   char tem = chars[first];
                   cout << tem;
                   chars[first++] = t;
                   chars[i] = tem;
               }
            }
        }
    }
};
