public class Solution {
    /*
     * @param source: source string to be scanned.
     * @param target: target string containing the sequence of characters to match
     * @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
     */
    public int strStr(String source, String target) {
        // write your code here
        if(source==null || target==null){
            return -1;
        }
        int i1 = source.length();
        int i2 = target.length();
        if(i1<i2){
            return -1;
        }
        int re = -1;
        String s;
        for(int i = 0;i<i1-i2+1;i++){
            s = source.substring(i,i+i2);
            if(s.equals(target)){
                re = i;
                break;
            }
        }
        return re;
    }
}
