class Solution {
public:
    /**
     * @param arr: The 2-dimension array
     * @return: Return the column the leftmost one is located
     */
    int getColumn(vector<vector<int>> &arr) {
        int len = arr[0].size();
        int lo = 0, hi = len - 1;
        int m = 0;
        while(lo < hi){
            m = lo + (hi - lo)/2;
            if(arr[0][m]) hi = m;
            else lo = m + 1;
        }
        for(int i = 1; i < arr.size(); i++){
            if(arr[i][m]){
                while(m && arr[i][m-1]) m--;
            }
        }
        return m;
    }
};
