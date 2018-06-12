//solution 1 recommoned
class Solution {
public:
    /**
     * @param N: The number of integers
     * @return: The number of beautiful arrangements you can construct
     */
    int countArrangement(int N) {
        vector<int> nums(N);
        for (int i = 0; i < N; ++i) nums[i] = i + 1;
        return helper(N, nums);
    }
    int helper(int n, vector<int>& nums) {
        if (n <= 0) return 1;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (n % nums[i] == 0 || nums[i] % n == 0) {
                swap(nums[i], nums[n - 1]);
                res += helper(n - 1, nums);
                swap(nums[i], nums[n - 1]);
            }
        }
        return res;
    }
};

//solution2
class Solution {
public:
    /**
     * @param N: The number of integers
     * @return: The number of beautiful arrangements you can construct
     */
    int countArrangement(int N) {
        // Write your code here
       std::vector<bool> visit(N,false);
       int an = 0;
       help(an,visit,N,1);
       return an;
    }
    
    void help(int &an,vector<bool> &visit,int N,int cur){
        if(cur == N+1){
            an++;
            return;
        }
        for(int i=1;i<=N;i++){
            if(!visit[i-1] &&(i % cur ==0 || cur % i == 0)){
                visit[i-1] = true;
                help(an,visit,N,cur+1);
                visit[i-1] = false;
            }
        }
    }
};
