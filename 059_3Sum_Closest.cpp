class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        int re = numbers[0]+numbers[1]+numbers[2];
        int n = numbers.size();
        int tem = 0;
        sort(numbers.begin(),numbers.end());
        for(int i = 0;i<n-2;i++){
            if(i && numbers[i] == numbers[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                tem = numbers[i]+numbers[left]+numbers[right];
                 if(tem == target){
                    return target;
                }else if(abs(tem-target)<abs(re-target)){
                    re = tem;
                }
                while(left < right && numbers[left+1] == numbers[left]) left++;
                 while(left < right && numbers[right-1] == numbers[right]) right--;
                if(tem>target) {
                     right--;
                }else if(tem<target) {
                    left++;
                }
            }
        }
        return re;
    }
};
