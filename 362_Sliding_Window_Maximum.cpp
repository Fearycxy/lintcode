class Solution {
public:
    /*
     * @param nums: A list of integers
     * @param k: An integer
     * @return: The maximum number inside the window at each moving
     */
    vector<int> maxSlidingWindow(vector<int> nums, int k) {
        // write your code here
        vector<int> re;
        std::deque<int> que;
        int n =nums.size();
        for(int i = 0;i<n;i++){
            if(!que.empty()&& que.front()+k==i) que.pop_front();
            while(!que.empty()&&nums[que.back()]<nums[i]) que.pop_back();
            que.push_back(i);
             if (i >= k - 1) re.push_back(nums[que.front()]);
        }
        return re;
    }
};
