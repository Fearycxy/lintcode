class ConnectingGraph {
public:
std::vector<int> vec;
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        vec.resize(n);
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
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return find(a) == find(b);
    }
};
