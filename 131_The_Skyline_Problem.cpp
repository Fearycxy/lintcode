class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int>> buildingOutline(vector<vector<int>> &buildings) {
        // write your code here
        vector<pair<int,int>> tem;
        vector<vector<int>> re;
        multiset<int> mul;
        for(auto &a : buildings){
            tem.emplace_back(a[0],-a[2]);
            tem.emplace_back(a[1],a[2]);
        }
        int cur,pre = 0;
        mul.insert(0);
        sort(tem.begin(),tem.end());
        for(auto &a : tem){
            if(a.second <0)mul.insert(-a.second);
            else mul.erase(mul.find(a.second));
            cur = *mul.rbegin();
            if(cur != pre){
                if(cur){
                    if(pre) re[re.size()-1][1] = a.first;
                    re.push_back({a.first,0,cur});
                }else if(pre) re[re.size()-1][1] = a.first;
                pre =cur;
            }
        }
        return re;
    }
};
