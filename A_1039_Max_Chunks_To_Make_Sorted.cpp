class Solution {
public:
    /**
     * @param arr: a permutation of N
     * @return: the most number of chunks
     */
    int maxChunksToSorted(vector<int> &arr) {
        // write your code here
        int top = -1,n=arr.size(),an = 0;
        for(int i =0;i<n;i++){
            top = max(top,arr[i]);
            if(top == i) an++;
        }
        return an;
    }
};
