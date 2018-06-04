/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */


public class Solution {
    public void selHelper(StringBuilder s,TreeNode root){
        if(root == null){
            s.append("#,");
        }else{
            s.append(root.val+",");
            selHelper(s,root.left);
            selHelper(s,root.right);
        }
    }
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    public String serialize(TreeNode root) {
        // write your code here
        StringBuilder s = new StringBuilder();
        selHelper(s,root);
        return s.toString();
    }


    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    public TreeNode deserialize(String data) {
       if (data == null || data.length() == 0) return null;

        String[] s = data.split(",");
        
        int length = s.length;
        i = 0;
        return des(s);
        // write your code here
    }
    
    
    int i = 0;
    
    public TreeNode des(String []s){
        if(i>=s.length){
            return null;
        }
        String c = s[i];
        i++;
        if(c.equals("#")){
            return null;
        }
        TreeNode t =new TreeNode(Integer.valueOf(c));
        t.left = des(s);
        t.right = des(s);
        return t;
    }
}
