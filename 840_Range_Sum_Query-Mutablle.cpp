class NumArray {
public:
vector<int> A,C;
    NumArray(vector<int> nums) {
        C = nums;
        A.resize(nums.size()+1);
        for(int j =0;j<nums.size();j++){
            add(j,nums[j]);
        }
    }
    
    inline int lowbit(int j){
        return j & -j;
    }
    
    void add(int i,int val){
        i++;
        for(int j=i;j<=C.size();j+=lowbit(j)){
            A[j]+=val;
        }
    }
    
    void update(int i, int val) {
        add(i,val-C[i]);
        C[i] = val;
    }
    
    inline int sum(int x){
        int res=0;
        for(int i =x+1;i>0;i-=lowbit(i))res+=A[i];
        return res;
    }
    
    int sumRange(int i, int j) {
        return sum(j) - sum(i-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
