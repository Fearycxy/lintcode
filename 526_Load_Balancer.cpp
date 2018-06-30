class LoadBalancer {
private:
    unordered_map<int,int> m;
    vector<int> vec;
public:
    LoadBalancer() {
        // do intialization if necessary
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here
        vec.push_back(server_id);
        m[server_id]=vec.size()-1;
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here
        m[vec[vec.size()-1]] = m[server_id];
        vec[m[server_id]]=vec[vec.size()-1];
        vec.pop_back();
        m.erase(m.find(server_id));
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here
        return vec[rand()%(vec.size())];
    }
};
