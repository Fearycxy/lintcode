class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        int mp[k+1] = {0};
        for(int i:colors){
            mp[i]++;
        }
        int x =1;
        for(int &i:colors){
            if(mp[x]){
                mp[x]--;
                i = x;
            }else{
                while(!mp[++x]);
                i = x;
                mp[x]--;
            }
        }
    }
};
