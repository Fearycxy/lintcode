class Solution {
public:
    /**
     * @param N: The number of buses
     * @param route: The route of buses
     * @param A: Start bus station
     * @param B: End bus station
     * @return: Return the minimum transfer number
     */
    int getMinTransferNumber(int N, vector<vector<int>> &route, int A, int B) {
        // Write your code here
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<N;i++){
            for(int y:route[i]){
                mp[y].push_back(i);
            }
        }
        queue<pair<int,int>> que;
        que.emplace(A,0);
        unordered_map<int,bool> visit;
        while(!que.empty()){
            int stop = que.front().first;
            int bus = que.front().second;
            if(stop == B) return bus;
            que.pop();
            visit[stop] = true;
            for(int r:mp[stop]){
                for(int y:route[r]){
                    if(!visit[y]){
                        que.emplace(y,bus+1);
                    }
                }
            }
        }
        return -1;
    }
};
