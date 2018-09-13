class ConnectingGraph2 {
public:
std::vector<int> vec;
std::vector<int> count;
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        // do intialization if necessary
        vec.resize(n);
        count.resize(n,1);
    }
    
     int find(int x){
        while(vec[x-1] && vec[x-1] != x){
            return vec[x-1] = find(vec[x-1]);
        }
        return vec[x-1] = x;
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
         int fa = find(a);
        int fb = find(b);
        if(fa != fb){
            vec[fa-1] = fb;
            count[fb-1] += count[fa-1];
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        return count[find(a)-1];
    }
};
