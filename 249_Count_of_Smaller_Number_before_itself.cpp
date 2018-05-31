class SegmentTree{
public:
    int start,end,count;
    SegmentTree * left,*right;
    SegmentTree(int s,int e):start(s),end(e){
        count = 0;
        left = NULL,right = NULL;
    }
    
    void add(int a){
        if(a < start || a > end) return;
        count ++;
        if(left) left->add(a);
        if(right) right->add(a);
    }
    
    static SegmentTree * build(int s,int e){
        if(s>e) return NULL;
        auto root = new SegmentTree(s,e);
        if(s == e) return root;
        int mid = ((e-s)>>1) + s;
        root->left = build(s,mid);
        root->right = build(mid+1,e);
        return root;
    }
    
    int query(int a){
        if(end <= a) return count;
        if(start > a) return 0;
         int re = 0;
        if(left) re += left->query(a); 
        if(right) re += right->query(a);
        return re;
    } 
};
class Solution {
public:
    /**
     * @param A: an integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        vector<int> re;
        auto root = SegmentTree::build(0,10000);
        if(!root) return re;
        for(int m:A) {
            re.push_back(root->query(m-1));
            root->add(m);
        }
        return re;
    }
};
