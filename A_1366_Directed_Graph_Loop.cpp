class Solution {
public:


    /**
     * @param start: The start points set
     * @param end: The end points set
     * @return: Return if the graph is cyclic
     */
    bool isCyclicGraph(vector<int> &start, vector<int> &end) {
        // Write your code here
        unordered_map<int,int> enter;
        unordered_map<int,vector<int>> mp;
        int n = start.size();
        for(int i=0;i<n;i++){
            if(enter.find(start[i]) == enter.end()){
                enter[start[i]] = 0;
            }
            enter[end[i]]++;
            mp[start[i]].push_back(end[i]);
        }
        while(!enter.empty()){
            bool canReturn = true;;
            for(auto it = enter.begin();it!=enter.end();){
                if(it->second == 0){
                    for(int t:mp[it->first]){
                        enter[t]--;
                    }
                    it = enter.erase(it);
                    canReturn = false;
                }else{
                    it++;
                }
            }
            if(canReturn) break;
        }
        return !enter.empty();
    }
};
