class HashFunction {
private:
    int seed, cap;
    
public:
    HashFunction(int seed, int cap){
        this->seed = seed;
        this->cap = cap;
    }
    
    int hash(string s){
        int rst = 0;
        for (int i = 0; i < s.size(); ++i){
            rst = ((long long)rst * (long long)seed + s[i]) % cap;
        }
        return rst;
    }


};

class CountingBloomFilter {
public:
    /*
    * @param k: An integer
    */
    static const int maxn = 100000;
    int k;
    vector<HashFunction*> f;
    int b[maxn];
    
    CountingBloomFilter(int k) {
        // do intialization if necessary
        this->k = k;
        for (int i = 0; i < k; ++i){
            int seed = rand() % maxn;
            int cap = rand() % maxn;
            f.push_back(new HashFunction(seed, cap));
        }
        memset(b, 0, sizeof(b));
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void add(string &word) {
        // write your code here
        for (int i = 0; i < k; ++i)
            b[f[i]->hash(word)] += 1;
    }

    /*
     * @param word: A string
     * @return: nothing
     */
    void remove(string &word) {
        // write your code here
        for (int i = 0; i < k; ++i)
            b[f[i]->hash(word)] --;
    }

    /*
     * @param word: A string
     * @return: True if contains word
     */
    bool contains(string &word) {
        // write your code here
        for (int i = 0; i < k; ++i)
            if (b[f[i]->hash(word)] <= 0)
                return false;
        return true;
    }
};
