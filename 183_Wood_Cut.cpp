class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        int ms = 0,mb = INT_MAX;
        while(ms < mb-1){
            int s= 0;
            int mid = ms + ((mb-ms)>>1);
            for(int &t :L){
                s+=t / mid;
            }
            if(s>=k){
                ms = mid;
            }else{
                mb = mid;
            }
        }
        return ms;
    }
};
