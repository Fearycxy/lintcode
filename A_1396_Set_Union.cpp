class Solution {
public:
    /**
     * @param sets: Initial set list
     * @return: The final number of sets
     */
    int setUnion(vector<vector<int>> &sets) {
        unordered_map<int,int> mp;
        unordered_map<int,int> un;
        int an = 0;int in = 1;
        unordered_set<int> st;
        for(auto s:sets){
            st.clear();
            int t = un[in] = in;
            st.insert(t);
            for(int i:s) {
                if(mp.find(i) != mp.end() && mp[i] != in){
                    int o = mp[i];
                    while(un[o] != o){
                        int u =o;
                        o = un[o];
                        un[u] = un[o];
                    }
                    mp[i] = o;
                    st.insert(o);
                    t = min(t,o);
                }else{
                    mp[i] = un[in];
                }
            }
            an += 2 - st.size();
            for(int k:st) un[k] = t;
            in++;
        }
        return an;
    }
};
