class Solution {
public:
//学习了
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        // write your code here
        long long an =0ll;
        for (auto i : key) {
            an = (an*33+i)%HASH_SIZE;
        }
        return an;
    }
};
