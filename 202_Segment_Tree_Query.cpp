/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if(start<=root->start && end >= root->end){
            return root->max;
        }
        auto left = root->left;
        auto right = root->right;
        if(left->end<start){
            return query(right,start,end);
        }else if(right->start>end){
            return query(left,start,end);
        }else{
            return max(query(left,start,end),query(right,start,end));
        }
    }
};
