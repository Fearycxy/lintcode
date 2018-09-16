class Solution {
public:
    /**
     * @param A: as indicated in the description
     * @param E: as indicated in the description
     * @return: Return the number of edges on the longest path with same value.
     */
    int LongestPathWithSameValue(vector<int> &A, vector<int> &E) {
        // write your code here
        int result = 0;
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<E.size()-1;i+=2){
            graph[E[i]].push_back(E[i+1]);
            graph[E[i+1]].push_back(E[i]);
        }
        dfs(result,0,graph,A,1);
        return result-1;
    }
    
    int dfs(int &result,int last, unordered_map<int,vector<int>> &graph,vector<int> &A,int cur){
        int most = 0 , second = 0;
        for(int i:graph[cur]){
            if(i==last) continue;
            int t = dfs(result,cur,graph,A,i);
            if(A[i-1] == A[cur-1]) {
                if(t>=most){
                    second = most;
                    most = t;
                }else if(t>=second){
                    second = t;
                }
            }
        }
        result = max(result , most+second+1);
        return most+1;
    }

};
