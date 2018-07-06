//naive
class Solution {
public:
    /**
     * @param citations: a list of integers
     * @return: return a integer
     */
    int hIndex(vector<int> &citations) {
        // write your code here
        sort(citations.begin(),citations.end(),greater<int>());
        int i = 1;
        for(int it:citations){
            if(it<i){
                return i-1;
            }
            i++;
        }
        return citations.size();
    }
};


//better
class Solution {
public:
    /**
     * @param citations: a list of integers
     * @return: return a integer
     */
    int hIndex(vector<int> &citations) {
        // write your code here
        int n = citations.size();
        int count[n+1]={0};
        for(int i:citations) count[i>n?n:i]++;
        int sum = 0;
        for(int i=n;i>=0;i--){
            sum += count[i];
            if(sum>=i){
                return i;
            }
        }
    }
};
