class Solution {
public:
    /**
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
        int n = triangle.size();
        queue<int> que;
        que.push(0);
        for(auto t:triangle){
            for(auto f = t.begin();f!=t.end();f++){
                int x =  (*f)+que.front();
                if(f!=t.begin() || t == triangle[0]){
                    que.pop();
                    if(f+1!=t.end()){
                        x =  min((*f)+que.front(),x);
                    }
                }
                 que.push(x);
                
            }
        }
        int re=INT_MAX;
        while(!que.empty()){
            re = min(que.front(),re);
            que.pop();
        }
        return re;
    }
};
