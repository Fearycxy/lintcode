class Solution {
    double eps = 1e-3;
public:
    /**
     * @param nums: 4 cards
     * @return: whether they could get the value of 24
     */
    bool compute24(vector<double> &nums) {
        if (nums.size() == 1) return abs(nums[0]-24) < eps;
        for (int i = 0; i < nums.size() -1 ; i++){
            for (int u = i+1; u < nums.size(); u++){
                 vector<double> vec = {nums[i] + nums[u], nums[i] - nums[u],nums[u]-nums[i],nums[i] * nums[u]};
                if(nums[u] > eps) vec.push_back(nums[i]/nums[u]);
                if(nums[i] > eps) vec.push_back(nums[u]/nums[i]);
                double w = nums[i],q = nums[u];
                for(double p:vec){
                    auto pd = nums;
                    nums[i] = p;
                    nums.erase(nums.begin()+u);
                    if(compute24(nums)) return true;
                    nums.insert(nums.begin()+u, q);
                    nums[i] = w;
                }
            }
        }
    }
    
};
