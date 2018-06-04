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
    /*
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    public List<Integer> searchRange(TreeNode root, int k1, int k2) {
        List<Integer> list = new LinkedList();
        // write your code here
        if(root == null){
            return list;
        }
        int val = root.val;
        if(val>=k1){
            int right = val <= k2? val:k2;
            list.addAll(searchRange(root.left,k1,right));
        }else{
            list.addAll(searchRange(root.right,k1,k2));
            return list;
        }
        if(val>= k1 && val <= k2){
            list.add(val);
        }
        if(val <= k2){
            list.addAll(searchRange(root.right,val,k2));
        }
          return list;
    }
}
