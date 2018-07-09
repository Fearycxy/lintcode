class Solution {
public:
    /**
     * @param matrix: List[List[int]]
     * @param k: a integer
     * @return: return a integer
     */
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // write your code here
        int left = matrix[0][0],right = matrix.back().back();
        while(left < right){
            int mid = left +((right - left) >>1);
            int cnt = less_equal(matrix,mid);
            if(cnt < k){
                left = mid +1;
            }else{
                right = mid;
            }
        }
        return left;
    }
private:
    inline int less_equal(vector<vector<int>> &matrix, int t){
        int n = matrix.size(), i = n -1, j = 0,re =0;
        while(j<n && i >= 0){
            if(matrix[i][j] <= t){
                re += i+1;
                j++;
            }else{
                i--;
            }
        }
        return re;
    }
};
