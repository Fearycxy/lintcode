/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class SegmentTree{
public:    
  SegmentTree *left, *right;
    int start, end, val;
    SegmentTree(int start, int end, int min=0): left(NULL), right(NULL), start(start), end(end), val(min) {};
  static SegmentTree* build(vector<int>&A,int s,int e){
      SegmentTree * root = new SegmentTree(s,e,0);
      if(s==e){
          root->val =A[s];
      }else{
        root->left = build(A,s,(s+e)/2);
      root->right = build(A,(s+e)/2+1,e);
      root->val = min(root->left->val,root->right->val);
      }
      return root;
  }
static int query(SegmentTree *root, int start, int end) {
        if (start <= root->start &&  root->end <= end) {
            return root->val;
        }
        
        if (root->left->end >= end) {
            return query(root->left, start, end);
        }
        if (root->right->start <= start) {
            return query(root->right, start, end);
        }
        
        int leftmin = query(root->left, start, root->left->end);
        int rightmin = query(root->right, root->right->start, end);
        return leftmin < rightmin ? leftmin : rightmin;
    }
};
class Solution {
public:
    /**
     * @param A: An integer array
     * @param queries: An query list
     * @return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
         SegmentTree * root = SegmentTree::build(A,0, A.size()-1);
        vector<int> result;
        int len = queries.size();
        for (int i = 0; i < len; ++i)
            result.push_back(SegmentTree::query(root, queries[i].start, queries[i].end));
        return result;
    }
};
