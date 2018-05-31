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
    int start,end;
    long long val;
    SegmentTree * left,*right;
    SegmentTree(int s,int e):start(s),end(e) {};
    static SegmentTree * buildSegmentTree(int s ,int e,vector<int>&source){
        auto root = new SegmentTree(s,e);
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
    
    long long query(Interval &s){
        if(s.start>end || s.end<start) return 0;
        if(s.start <=start && s.end>=end) return val;
        return compute(left->query(s),right->query(s));
    }
};
class Solution {
public:
    /**
     * @param A: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<long long> re;
        SegmentTree* tree = SegmentTree::buildSegmentTree(0,A.size()-1,A);
        for(Interval &iv: queries){
            re.push_back(tree->query(iv));
        }
        return re;
    }
};
