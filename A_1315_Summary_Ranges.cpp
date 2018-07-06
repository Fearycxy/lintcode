class Solution {
public:
    /**
     * @param nums:  a sorted integer array without duplicates
     * @return: the summary of its ranges
     */
    vector<string> summaryRanges(vector<int> &nums) {
        // Write your code here
        vector<string> an;
        if(nums.empty()) return an;
        int head = nums[0];
        int last = head;
        for(int i:nums){
            if(head == i) continue;
            if(i != last+1){
                if(last == head) an.push_back(to_string(head));
                else an. push_back(to_string(head) + "->" + to_string(last));
                head = i;
            }
            last = i;
        }
        if(last == head) an.push_back(to_string(head));
        else an. push_back(to_string(head) + "->" + to_string(last));
        return an;
    }
};
