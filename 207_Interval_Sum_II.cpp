class Solution{
public:    
    int start,end;
    long long val;
    Solution * left,*right;
    Solution(int s,int e):start(s),end(e) {};
      /* you may need to use some attributes here */
    /*
    * @param A: An integer array
    */
    Solution(vector<int> A) {
        if(A.empty()) return;
        auto root = buildSegmentTree(0,A.size()-1,A);
        left = root->left;
        right = root->right;
        val = root->val;
        start = root->start;
        end = root->end;
    }
    static Solution * buildSegmentTree(int s ,int e,vector<int>&source){
        auto root = new Solution(s,e);
        int mid = (s+e)>>1;
        if(s==e) {
            root->val = source[e];
            return root;
        }
        root->left = buildSegmentTree(s,mid,source);
        root->right = buildSegmentTree(mid+1,e,source);
        root->val = compute(root->left->val , root->right->val);
        return root;
    }
    
    inline static long long compute(long long l,long long r) {
        return l+r;
    }
    
    /*
     * @param start: An integer
     * @param end: An integer
     * @return: The sum from start to end
     */
    long long query(int s, int e) {
        if(s> end || e<start) return 0;
        if(s <= start && e >= end) return val;
        return compute(left->query(s,e),right->query(s,e));
    }
    
     /*
     * @param index: An integer
     * @param value: An integer
     * @return: nothing
     */
    void modify(int index, int value) {
        if(index == start && end ==index){
            val = value;
        }else if(index >= start && index <= end){
            left->modify(index,value);
            right->modify(index,value);
            val = compute(left->val,right->val);
        }
    }
};

