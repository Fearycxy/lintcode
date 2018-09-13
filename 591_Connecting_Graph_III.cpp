class ConnectingGraph3 {
private:
    vector<int> father;
    int count;
    
public:
    /*
    * @param n: An integer
    */ConnectingGraph3(int n) {
        // do intialization if necessary
        vector<int> temp(n + 1);
        father = temp;
        count = n;
        for (int i = 1; i <= n; i++) {
            father[i] = i;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            count--;
        }
    }

    /*
     * @return: An integer
     */
    int query() {
        // write your code here
        return count;
    }
    
private:
    int find(int a) {
        if (father[a] == a) {
            return a;
        }
        
        return father[a] = find(father[a]);
    }
};
