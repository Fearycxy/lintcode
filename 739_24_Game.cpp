class Solution {
public:
const double eps = 0.001;
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        // write your code here
        if(nums.size() == 1) return abs(nums[0]-24) < eps;
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                double p = nums[i],q = nums[j];
                vector<double> t{p+q,p-q,q-p,q*p};
                if(abs(p) > eps) t.push_back(q/p);
                if(abs(q) > eps) t.push_back(p/q);
                nums.erase(nums.begin()+i);
                nums.erase(nums.begin()+j);
                for(double f:t){
                    nums.push_back(f);
                    if(compute24(nums)) return true;
                    nums.pop_back();
                }
                nums.insert(nums.begin()+j,q);
                nums.insert(nums.begin()+i,p);
            }
        }
        return false;
    }
};
