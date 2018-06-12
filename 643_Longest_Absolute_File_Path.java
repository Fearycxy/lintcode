public class Solution {
    /**
     * @param input: an abstract file system
     * @return: return the length of the longest absolute path to file
     */
    public int lengthLongestPath(String input) {
        // write your code here
        HashMap<Integer,Integer> map = new HashMap();
        map.put(0,0);
        map.put(-1,0);
        String[] kk = input.split("\n");
        int an = 0;
        for(String s:kk){
            int level = s.lastIndexOf('\t')+1;
            int len = s.substring(level).length();
            if(s.indexOf('.') !=-1){
                an = Math.max(an,map.get(level-1)+len);
            }else{
                map.put(level,map.get(level-1) +len +1);
            }
        }
        return an;
    }
}
