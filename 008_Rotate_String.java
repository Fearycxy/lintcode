public class Solution {
    /*
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
   public void rotateString(char[] str, int offset) {
        // write your code here
         int length = str.length;
        if(offset >0 && length >0){
           
            offset = offset %length;
            int dex=offset-1;
            char[] flag = new char[offset];
            for(int i = 0;i<length;i++){
                if(dex >=0){
                    flag[dex] = str[length -offset+dex];
                    dex--;
                }
                char re ;
                if(length-1-i-offset >=0){
                    re = str[length-1-i-offset];
                }else{
                    re = flag[length-i-1];
                }
                str[length - i-1] = re;
            }
        }
    }
}
