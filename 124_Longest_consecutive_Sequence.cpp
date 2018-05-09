//超时的暴力算法
class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        int an = 0;
        unordered_set<long long> re;
        for(int u : num){
            if(!re.count(u)) re.insert(u);
            int t = 1;
             long long y = u;
            while(re.count(--y)) t++;
            y = u;
            while(re.count(++y)) t++;
            an = max(an,t);
        }
        return an;
    }
};

//改由存储范围
class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
        long long  an = 0;
        vector<pair<long long,long long>> dp;
        for(const long long u : num){
            bool flag = false;
            auto fg  = dp.begin();
            for(auto p = dp.begin();p!=dp.end();p++){
                if(u>= p->first && u<=p->second){
                    flag = true;
                    break;
                }
                if(u == p->first-1){
                    if(flag){
                        fg->second = p->second;
                        an = max(an, fg->second- fg->first +1);
                        p = dp.erase(p);
                        break;
                    }
                    flag = true;
                    fg = p;
                    p->first = u;
                    an = max(an, p->second- p->first +1);
                }else if(u == (*p).second+1){
                    if(flag){
                        fg->first = p->first;
                        an = max(an, fg->second- fg->first +1);
                        p = dp.erase(p);
                        break;
                    }
                    flag = true;
                    fg = p;
                    p->second = u;
                    an = max(an, p->second- p->first +1);
                }
            }
            if(!flag){
                an = max(an,1ll);
                dp.push_back(make_pair(u,u));
            }
        }
        return an;
    }
};
